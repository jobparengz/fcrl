<?php

/**
 * @file
 * Base phpunit tests for fcrl_harvest module.
 */

include_once __DIR__ . '/includes/HarvestSourceTestStub.php';

/**
 *
 */
class FcrlHarvestTest extends \PHPUnit_Framework_TestCase {
  // fcrl_harvest_test status.
  public static $fcrlHarvestTestBeforClassStatus = TRUE;

  /**
   * Test Harvest Source.
   */
  public static function getTestSources() {
    return array(
      'harvest_test_source_local_dir' => new HarvestSourceTestStub(
        'harvest_test_source_local_dir',
        __DIR__ . '/data/harvest_test_source_local_dir/'
      ),
      'harvest_test_source_local_file' => new HarvestSourceTestStub(
        'harvest_test_source_local_file',
        __DIR__ . '/data/harvest_test_source_local_file/data.json'
      ),
      'harvest_test_source_remote' => new HarvestSourceTestStub(
        'harvest_test_source_remote',
        'https://data.mo.gov/data.json'
      ),
    );
  }

  /**
   *
   */
  public static function getFcrlHarvestTestBeforClassStatus() {
    return self::$fcrlHarvestTestBeforClassStatus;
  }

  /**
   *
   */
  public static function setFcrlHarvestTestBeforClassStatus($status) {
    self::$fcrlHarvestTestBeforClassStatus = $status;
  }

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    // Make sure the test module exporting the test source type.
    if (!module_exists('fcrl_harvest_test')) {
      self::setFcrlHarvestTestBeforClassStatus(FALSE);
      module_enable(array('fcrl_harvest_test'));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function setup() {
  }

  /**
   * @covers ::fcrl_harvest_migrate_sources()
   */
  public function test_fcrl_harvest_migrate_sources() {
    $this->markTestSkipped('This test should be implemneted by each for each harvest submodule.');
  }

  /**
   *
   */
  public function test_fcrl_harvest_rollback_sources() {
    $this->markTestSkipped('This test should be implemneted by each for each harvest submodule.');
  }

  /**
   * @covers ::fcrl_harvest_get_migration()
   */
  public function test_fcrl_harvest_get_migration() {
    $sources = self::getTestSources();

    // Get first migration registration.
    $harvest_test_source_local_dir = $sources['harvest_test_source_local_dir'];
    $migration_harvest_test_source_local_dir = fcrl_harvest_get_migration($harvest_test_source_local_dir);
    $this->assertEquals($harvest_test_source_local_dir, $migration_harvest_test_source_local_dir->getHarvestSource());

    // If we change the source (keeping the machine name) the migration should
    // have the updated harvest source.
    $harvest_test_source_local_dir->label = "This is an updated source";
    $harvest_test_source_local_dir->uri = __DIR__ . '/data/harvest_fictional_test_source/';
    $migration_harvest_test_source_second = fcrl_harvest_get_migration($harvest_test_source_local_dir);
    $this->assertEquals($harvest_test_source_local_dir, $migration_harvest_test_source_second->getHarvestSource());
  }

  /**
   * @covers ::fcrl_harvest_cache_default()
   */
  public function test_fcrl_harvest_cache_sources() {
    $this->markTestSkipped('This test should be implemneted by each for each harvest submodule.');
  }

  /**
   * @covers ::fcrl_harvest_cache_default()
   */
  public function test_fcrl_harvest_cache_default_remote() {
    return;
    // Setup the test:
    // - Remove the cache directory.
    $sources = self::getTestSources();
    $harvest_test_source_remote = $sources['harvest_test_source_remote'];
    $rmdir = drupal_rmdir($harvest_test_source_remote->getCacheDir());
    $this->assertTrue($rmdir);

    fcrl_harvest_cache_default($harvest_test_source_remote, microtime());

    // Check the file cached is the same provided by the source.
    // TODO Improve/Add conditions?
    $files = file_scan_directory($harvest_test_source_remote->getCacheDir(), '(.*)');
    $this->assertTrue(count($files) == 1);

    $file_content = file_get_contents($harvest_test_source_remote->uri);
    $this->assertJsonStringEqualsJsonFile(array_pop($files)->uri, $file_content);
  }

  /**
   * @covers ::fcrl_harvest_cache_default()
   */
  public function test_fcrl_harvest_cache_default_local_dir() {
    $sources = self::getTestSources();
    $harvest_test_source_local_dir = $sources['harvest_test_source_local_dir'];
    // Create/Clear the cache dir.
    $harvest_test_source_local_dir->getCacheDir(TRUE);

    fcrl_harvest_cache_default($harvest_test_source_local_dir, microtime());
    $files_cached = file_scan_directory($harvest_test_source_local_dir->getCacheDir(), '(.*)');
    $files_source = file_scan_directory($harvest_test_source_local_dir->uri, '(.*)');

    $this->assertEquals(count($files_cached), count($files_source));
  }

  /**
   * @covers ::fcrl_harvest_cache_default()
   */
  public function test_fcrl_harvest_cache_default_local_file() {
    $this->markTestIncomplete('Not implemented yet.');
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
    // Assuming the test module enabled by now. Restore original status of the
    // modules.
    if (!self::getFcrlHarvestTestBeforClassStatus()) {
      module_disable(array('fcrl_harvest_test'));
    }
  }

}
