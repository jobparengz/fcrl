<?php

/**
 * @file
 * Base phpunit tests for fcrl_harvest module.
 */

/**
 * PHPUnit test class for FCRL harvest types.
 *
 * @class FcrlHarvestSourcesTest
 */
class FcrlHarvestSourcesTest extends \PHPUnit_Framework_TestCase {

  static $setUpBeforeClassModuleDisabled = FALSE;

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    // Make sure the test module exporting the test source type is disbled.
    // This will be enabled during the tests.
    if (!module_exists('fcrl_harvest_test')) {
      // The module is disabled.
      self::$setUpBeforeClassModuleDisabled = TRUE;
    }
    else {
      self::$setUpBeforeClassModuleDisabled = FALSE;
      module_disable(array('fcrl_harvest_test'));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function setup() {
  }

  /**
   * Tests for the cache support in the 'source_types' hook.
   *
   * @covers ::fcrl_harvest_source_types_definition()
   * @covers ::fcrl_harvest_modules_enabled()
   * @covers ::fcrl_harvest_modules_disabled()
   */
  public function testFcrlHarvestSourceTypesDefinition() {
    // Make sure that all the harvest source type entries available right now
    // in the site are cached by 'fcrl_harvest_source_types_definition()'.
    fcrl_harvest_source_types_definition();
    $before_cache = cache_get('fcrl_harvest_source_types_definition');
    $this->assertTrue(is_array($before_cache->data));
    $before_count = count($before_cache->data);

    // Enabling a module that implements the "harvest_source_types" hook should
    // reset the cached entries.
    module_enable(array("fcrl_harvest_test"));
    $module_enabled_cache = cache_get('fcrl_harvest_source_types_definition');
    $this->assertFalse($module_enabled_cache);

    // Running the callback should repopulate the cache entry with the latest
    // harvest source types available in the system.
    fcrl_harvest_source_types_definition();
    $after_cache = cache_get('fcrl_harvest_source_types_definition');
    $this->assertTrue(is_array($after_cache->data));
    $after_count = count($after_cache->data);

    // Run a before/after comparison. Make sure that the test source types
    // provided by the 'fcrl_harvest_test' module are now available.
    $this->assertGreaterThan($before_count, $after_count);
    $this->assertArrayHasKey('harvest_test_type', $after_cache->data);
    $this->assertArrayHasKey('harvest_another_test_type', $after_cache->data);
  }

  /**
   * Test field_harvest_source_type.
   *
   * Make sure that the allowed harvest type values the the type machine name
   * as key and the type label as value.
   *
   * @covers ::fcrl_harvest_field_fcrl_harveset_type_allowed_values()
   *
   * @depends testFcrlHarvestSourceTypesDefinition
   */
  public function testFcrlHarvestSourcesFieldFcrlHarvesetTypeAllowedValues() {
    $allowed_values_expected = array(
      'harvest_test_type' => 'Fcrl Harvest Test Type',
      'harvest_another_test_type' => 'Fcrl Harvest Another Test Type',
    );

    $allowed_values = fcrl_harvest_field_fcrl_harveset_type_allowed_values();

    $this->assertNotNull($allowed_values['harvest_test_type']);
    $this->assertEquals($allowed_values['harvest_test_type'], $allowed_values_expected['harvest_test_type']);

    $this->assertNotNull($allowed_values['harvest_another_test_type']);
    $this->assertEquals($allowed_values['harvest_another_test_type'], $allowed_values_expected['harvest_another_test_type']);
  }

  /**
   * Test field_sourec_uri validation.
   *
   * @covers ::fcrl_harvest_field_attach_validate_source_uri()
   */
  public function testFcrlHarvestSourcesFieldAttachValidateSourceUri() {
    // Invalid arguments.
    $errors = array();
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertNotEmpty($errors);

    $langcode = LANGUAGE_NONE;
    $delta = 0;

    // Invalid Protocol.
    $errors = array();
    $uri = 'wrong://data.mo.gov/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertNotEmpty($errors);

    // Invalid Local URI.
    $errors = array();
    $uri = 'file://test/phpunit/data/harvest_test_source_local_file/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertNotEmpty($errors);

    // Valid local URI.
    $errors = array();
    $uri = 'file://' . __DIR__ . '/data/harvest_test_source_local_file/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertEmpty($errors);

    // Invalid Remote URI.
    $errors = array();
    $uri = 'http://this_is_not_correct.wrong/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertNotEmpty($errors);

    // Valid Remote URI.
    $errors = array();
    $uri = 'https://data.mo.gov/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertEmpty($errors);

    $errors = array();
    $uri = 'http://data.mo.gov/data.json';
    fcrl_harvest_field_attach_validate_source_uri($uri, $langcode, $delta, $errors);
    $this->assertEmpty($errors);
  }

  /**
   * {@inheritdoc}
   */
  protected function tearDown() {
  }

  /**
   * {@inheritdoc}
   */
  public static function tearDownAfterClass() {
    if (self::$setUpBeforeClassModuleDisabled) {
      // Assuming the test module enabled by now. Restore original status of the
      // modules.
      module_disable(array('fcrl_harvest_test'));
    }
    else {
      module_enable(array('fcrl_harvest_test'));
    }
  }

}
