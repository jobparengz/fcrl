<?php

/**
 * @file
 * Tests for fcrl_harvest module.
 */

/**
 * Test class for Data Json migration tests.
 *
 * @class FcrlHarvestDataJsonTest *
 */
class FcrlHarvestDataJsonTest extends PHPUnit_Framework_TestCase {

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    // Harvest cache the test source.
    fcrl_harvest_cache_source(self::getTestSource());

    // Harvest Migration of the test data.
    fcrl_harvest_migrate_source(self::getTestSource());
  }

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
  }

  /**
   * Test harvest filters on data.json source.
   */
  public function testFcrlHarvestDataJsonModifiers() {
    $source = self::getTestSource();
    $data = drupal_json_decode(file_get_contents(__DIR__ . '/data/fcrl_harvest_datajson_test_filters.json'));
    $cache = fcrl_harvest_datajson_cache_pod_v1_1_json($data, $source, microtime());
    $count = $cache->getSavedCount();
    $uuid = reset(array_keys($cache->getSaved()));
    $node = reset(array_values($cache->getSaved()));
    $identifier = fcrl_harvest_datajson_prepare_item_id($uuid);
    $dataset_file = implode('/', array($source->getCacheDir(), $identifier));
    $dataset = drupal_json_decode(file_get_contents(drupal_realpath($dataset_file)));
    $this->assertEquals($node['title'], 'Wisconsin Polling Places TEST');
    $this->assertEquals($dataset['awesomekey'], 'politics');
    $this->assertEquals($dataset['publisher']['name'], 'mis');
    // With filters and excludes, only one dataset should be cached from source.
    $this->assertEquals($count, 1);
  }

  /**
   * @covers fcrl_harvest_datajson_prepare_item_id().
   */
  public function testFcrlHarvestDataJsonPrepareItemId() {
    $url = 'http://example.com/what';
    $dir = fcrl_harvest_datajson_prepare_item_id($url);
    $this->assertEquals($dir, 'what');

    $url = 'http://example.com/what/now';
    $dir = fcrl_harvest_datajson_prepare_item_id($url);
    $this->assertEquals($dir, 'now');

    $url = 'http://example.com';
    $dir = fcrl_harvest_datajson_prepare_item_id($url);
    $this->assertEquals($dir, '');
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
    fcrl_harvest_rollback_sources(array(self::getTestSource()));
    fcrl_harvest_deregister_sources(array(self::getTestSource()));
  }

  /**
   * Test Harvest Source.
   */
  public static function getTestSource() {
    $source = new HarvestSourceDataJsonStub(__DIR__ . '/data/fcrl_harvest_datajson_test_filters.json');
    $source->filters = array('keyword' => array('election'));
    $source->excludes = array('keyword' => array('politics'));
    $source->defaults = array('awesomekey' => array('politics'));
    $source->overrides = array('publisher.name' => array('mis'));
    return $source;
  }

}
