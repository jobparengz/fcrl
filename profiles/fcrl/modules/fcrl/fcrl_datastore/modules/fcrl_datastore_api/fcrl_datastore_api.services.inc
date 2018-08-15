<?php

/**
 * @file
 * Fcrl_datastore_api.services.inc.
 */

/**
 * Implements hook_default_services_endpoint().
 */
function fcrl_datastore_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'fcrl_datastore_api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/action/datastore';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'bencode' => TRUE,
      'json' => TRUE,
      'jsonp' => TRUE,
      'php' => TRUE,
      'xml' => TRUE,
      'yaml' => TRUE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'application/x-yaml' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
      'text/csv' => TRUE,
    ),
  );
  $endpoint->resources = array(
    'fcrl_datastore_search' => array(
      'alias' => 'search',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'fcrl_datastore' => array(
      'alias' => 'store',
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'fcrl_datastore_file' => array(
      'alias' => 'data',
      'operations' => array(
        'delete' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
        ),
        'logout' => array(
          'enabled' => '1',
        ),
        'token' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['fcrl_datastore_api'] = $endpoint;

  return $export;
}
