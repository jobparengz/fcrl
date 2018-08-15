<?php

/**
 * @file
 * Base phpunit tests for FcrlDatastoreFastImport class.
 */

/**
 * FcrlDatastoreFastImport class.
 */
class FcrlDatastoreFastImportTest extends \PHPUnit_Framework_TestCase {
  /**
   * Variable for fcrl_datastore_fast_import status.
   *
   * @var fcrlFastImportTestBeforeClassStatus
   */
  public static $fcrlFastImportTestBeforeClassStatus = TRUE;

  /**
   * Set fcrl_datastore_fast_import status.
   */
  public static function setFcrlFastImportTestBeforeClassStatus($status) {
    self::$fcrlFastImportTestBeforeClassStatus = $status;
  }

  /**
   * Get fcrl_datastore_fast_import status.
   */
  public static function getFcrlFastImportTestBeforeClassStatus() {
    return self::$fcrlFastImportTestBeforeClassStatus;
  }

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    $resources = self::getResources();
    foreach ($resources as $resource) {
      self::addResource($resource);
    }
    if (!module_exists('fcrl_datastore_fast_import')) {
      self::setFcrlFastImportTestBeforeClassStatus(FALSE);
      module_enable(array('fcrl_datastore_fast_import'));
    }
  }

  /**
   * Get the node id from a known uuid.
   */
  public static function getNodeFromUuid($uuid) {
    $ids = entity_get_id_by_uuid('node', array($uuid));
    foreach ($ids as $uid => $id) {
      return $id;
    }
  }

  /**
   * Retrieves an keyed array of resources.
   */
  private static function getResources() {
    $resources = array(
      'polling_places' => array(
        'filename' => 'polling_places.csv',
        'title' => 'Polling Places',
        'uuid' => '3a05eb9c-3733-11e6-ac61-9e71128cae79'
      ),
      'null_check' => array(
        'filename' => 'null_check.csv',
        'title' => 'Empy Values Checker',
        'uuid' => '3a05eb9c-3733-11e6-ac61-9e71128cae80'
      ),
    );
    return $resources;
  }

  /**
   * Given a resource key retrieves a uuid.
   */
  private static function getUuid($key, $resources) {
    if (array_key_exists($key, $resources)) {
      return $resources[$key]['uuid'];
    }
    else {
      throw new \Exception('Resource is not defined');
    }

  }

  /**
   * Add a resource to test.
   */
  private static function addResource($resource) {

    // Create resource.
    $filename = $resource['filename'];
    $node = new stdClass();
    $node->title = $resource['title'];
    $node->type = 'resource';
    $node->uid = 1;
    $node->uuid = $resource['uuid'];
    $node->language = 'und';
    $path = implode(DIRECTORY_SEPARATOR, array(__DIR__, 'files', $filename));
    $file = file_save_data(file_get_contents($path), 'public://' . $filename);
    $node->field_upload[LANGUAGE_NONE][0] = (array) $file;

    node_save($node);
  }

  /**
   * Teardown function.
   */
  public static function tearDownAfterClass() {
    $resources = self::getResources();
    foreach ($resources as $resource) {
      entity_uuid_delete('node', array($resource['uuid']));
    }
    // Assuming the test module enabled by now. Restore original status of the
    // modules.
    if (!self::getFcrlFastImportTestBeforeClassStatus()) {
      module_disable(array('fcrl_datastore_fast_import'));
    }
  }

  /**
   * Test fcrl_datastore_fast_import functionality.
   */
  public function testFastImportWithQuoteDelimiters() {
    $nid = self::getNodeFromUuid(self::getUuid('polling_places', self::getResources()));
    $importerId = 'fcrl_file';
    $node = node_load($nid);
    $node = entity_metadata_wrapper('node', $node);

    $source = feeds_source($importerId, $nid);

    $table = feeds_flatstore_processor_table($source, array());
    $config = array(
      'delimiter' => ',',
      'no_headers' => 0,
      'encoding' => 'UTF-8',
    );

    variable_set('fcrl_datastore_load_data_type', 'load_data_local_infile');
    variable_set('quote_delimiters', '"');
    variable_set('lines_terminated_by', '\n');
    variable_set('fields_escaped_by', '');
    variable_set('fcrl_datastore_fast_import_load_empty_cells_as_null', 0);

    $result = fcrl_datastore_fast_import_import($source, $node, $table, $config);
    $this->assertEquals($result['total_imported_items'], 117);
  }

  /**
   * Test fast_import module with options for reading empty fields as null.
   */
  public function testFastImportLoadEmptyCellsAsNull() {
    $nid = self::getNodeFromUuid(self::getUuid('null_check', self::getResources()));
    $importerId = 'fcrl_file';
    $node = node_load($nid);
    $node = entity_metadata_wrapper('node', $node);

    $source = feeds_source($importerId, $nid);

    $table = feeds_flatstore_processor_table($source, array());
    $config = array(
      'delimiter' => ',',
      'no_headers' => 0,
      'encoding' => 'UTF-8',
    );

    variable_set('fcrl_datastore_load_data_type', 'load_data_local_infile');
    variable_set('quote_delimiters', '"');
    variable_set('lines_terminated_by', '\n');
    variable_set('fields_escaped_by', '');
    variable_set('fcrl_datastore_fast_import_load_empty_cells_as_null', 1);

    $result = fcrl_datastore_fast_import_import($source, $node, $table, $config);
    $this->assertEquals($result['total_imported_items'], 2);

    $source = feeds_source($importerId, $nid);
    $preview = $source->preview();

    $this->assertEquals($preview->items[1]['ward'], '');
    $this->assertEquals($preview->items[1]['address'], '');
  }

}
