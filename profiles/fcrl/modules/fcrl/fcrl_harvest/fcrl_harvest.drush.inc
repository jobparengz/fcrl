<?php

/**
 * @file
 * Fcrl_harvest.drush.inc.
 */

/**
 * Implements hook_drush_command().
 */
function fcrl_harvest_drush_command() {
  // Run harvest operation on the source passed as argument.
  $items['fcrl-harvest'] = array(
    'aliases' => array('fcrl-h', 'fcrl-harvest-run', 'fcrl-hr'),
    'description' => 'Run a harvest (cache and migration) operation on a single source or all the available sources if no argument is provided.',
    'callback' => 'fcrl_harvest_drush_command_harvest',
    'arguments' => array(
      'source_machine_name' =>
      'The source machine name to run the harvest operation on',
    ),
    'options' => array(
      'skiphash' => 'Skip hash checking and update all the datasets available in the source.',
      'limit' => 'Limit on the length of each migration. Check migrate doc for more about this option.',
      'instrument' => 'Capture performance information (timer, memory, or all). Check migrate doc for more about this option.',
      'idlist' => 'A comma delimited list of ids to import or rollback. Check migrate doc for more about this option.',
    ),
    'drupal dependencies' => array('fcrl_harvest'),
  );

  // Run harvest cache operation on the source passed as argument.
  $items['fcrl-harvest-cache'] = array(
    'aliases' => array('fcrl-hc', 'fcrl-cache-harvested-data', 'fcrl-chd'),
    'description' => 'Run a cache operation on a single source or all the available sources if the argument is not provided.',
    'callback' => 'fcrl_harvest_drush_command_cache',
    'arguments' => array(
      'source_machine_name' =>
      'The source machine name to run the cache operation on',
    ),
    'drupal dependencies' => array('fcrl_harvest'),
  );

  // Run harvest migrate operation on the source passed as argument.
  $items['fcrl-harvest-migrate'] = array(
    'aliases' => array('fcrl-hm', 'fcrl-migrate-cached-data', 'fcrl-mcd'),
    'description' => 'Run a migrate operation on a single source or all the available sources if the argument is not provided.',
    'callback' => 'fcrl_harvest_drush_command_migrate',
    'arguments' => array(
      'source_machine_name' => 'The source machine name to run the migration on',
    ),
    'options' => array(
      'skiphash' => 'Skip hash checking and update all the datasets available in the source.',
      'limit' => 'Limit on the length of each migration. Check migrate doc for more about this option.',
      'instrument' => 'Capture performance information (timer, memory, or all). Check migrate doc for more about this option.',
      'idlist' => 'A comma delimited list of ids to import or rollback. Check migrate doc for more about this option.',
    ),
    'drupal dependencies' => array('fcrl_harvest'),
  );

  // Run harvest rollback operation on the source passed as argument.
  $items['fcrl-harvest-rollback'] = array(
    'aliases' => array('fcrl-hr'),
    'description' => 'Run a harvest rollback on a single source.',
    'callback' => 'fcrl_harvest_drush_command_rollback',
    'arguments' => array(
      'source_machine_name' => 'The source machine name to run the rollback on.',
    ),
    'options' => array(
      'limit' => 'Limit on the length of each migration. Check migrate doc for more about this option.',
      'instrument' => 'Capture performance information (timer, memory, or all). Check migrate doc for more about this option.',
      'idlist' => 'A comma delimited list of ids to import or rollback. Check migrate doc for more about this option.',
    ),
    'drupal dependencies' => array('fcrl_harvest'),
  );

  // Displays the list of available sources.
  $items['fcrl-harvest-status'] = array(
    'aliases' => array('fcrl-hs'),
    'description' => 'Status Harvest Sources available',
    'callback' => 'fcrl_harvest_drush_command_status',
    'drupal dependencies' => array('fcrl_harvest'),
  );

  // Deregister the migration associated with a source.
  $items['fcrl-harvest-deregister'] = array(
    'aliases' => array('fcrl-hdr'),
    'description' => 'Deregister the migration associated with the specified source',
    'callback' => 'fcrl_harvest_drush_command_deregister',
    'arguments' => array(
      'source_machine_name' => 'The source machine name',
    ),
    'options' => array(),
    'drupal dependencies' => array('fcrl_harvest'),
  );

  /* NOT IMPLEMENTED YET */
  $items['orphaned-resources-count'] = array(
    'description' => "Count resources that are not linked to datasets.",
    'drupal dependencies' => array('fcrl_dataset'),
    'aliases' => array('fcrl-or-count', 'orphaned-resources'),
  );

  /* NOT IMPLEMENTED YET */
  $items['orphaned-resources-delete'] = array(
    'description' => "Count resources that are not linked to datasets.",
    'drupal dependencies' => array('fcrl_dataset'),
    'aliases' => array('fcrl-or-delete', 'orphaned-resources-delete'),
  );

  return $items;
}

/**
 * Run a harvest operation (cache + migrate).
 *
 * Run harvest on all the harvest source
 * available or the source passed as arguments.
 *
 * @param string $source_machine_name
 *
 *   Optional harvest source machine name.
 */
function fcrl_harvest_drush_command_harvest($source_machine_name = NULL) {
  fcrl_harvest_drush_command_cache($source_machine_name);
  fcrl_harvest_drush_command_migrate($source_machine_name);
}

/**
 * Run harvest cache operation on the source passed as argument.
 *
 * @param string $source_machine_name
 *
 *   Source machine name to cache.
 */
function fcrl_harvest_drush_command_cache($source_machine_name = NULL) {
  $sources = array();
  if (isset($source_machine_name)) {
    $source = fcrl_harvest_get_harvestsource($source_machine_name);
    if (!$source) {
      return FALSE;
    }
    $sources[] = $source;
  }
  else {
    drush_log("Running the harvest caching on all the available sources.", 'notice');
    $sources = fcrl_harvest_sources_definition();
  }

  foreach ($sources as $source) {
    // Cache source.
    fcrl_harvest_cache_source($source);
  }
}

/**
 * Run harvest migrate operation on the source passed as argument.
 *
 * @param string $source_machine_name
 *
 *   Source machine name to migrate.
 */
function fcrl_harvest_drush_command_migrate($source_machine_name = NULL) {
  $supported_options = array('limit', 'skiphash', 'instrument', 'idlist');
  $options = array();

  // Gather harvest migration options. If parsing the arguments fails just relay
  // on the parsing callback to oouput an appropriate message and stop.
  $option_parsed = fcrl_harvest_get_options($options, $supported_options);
  if (!$option_parsed) {
    return;
  }

  $sources = array();
  if (isset($source_machine_name)) {
    $source = fcrl_harvest_get_harvestsource($source_machine_name);

    if (!$source) {
      return FALSE;
    }

    drush_log("Running the harvest migration on " . $source_machine_name, 'notice');
    $sources[] = $source;
  }
  else {
    drush_log("Running the harvest migration on all the available sources.", 'notice');
    $sources = fcrl_harvest_sources_definition();
  }

  foreach ($sources as $source) {
    // Migrate source.
    fcrl_harvest_migrate_source($source, $options);
  }

  // Print instrument info if set.
  global $_migrate_track_memory, $_migrate_track_timer;
  if ($_migrate_track_memory) {
    drush_migrate_print_memory();
  }

  if ($_migrate_track_timer && !drush_get_context('DRUSH_DEBUG')) {
    drush_print_timers();
  }
}

/**
 * Run harvest migrate operation on the source passed as argument.
 *
 * @param string $source_machine_name
 *
 *   Source machine name to migrate.
 */
function fcrl_harvest_drush_command_rollback($source_machine_name) {
  $options = array();
  $supported_options = array('limit', 'instrument', 'idlist');

  // Gather harvest migration options. If parsing the arguments fails just relay
  // on the parsing callback to oouput an appropriate message and stop.
  $option_parsed = fcrl_harvest_get_options($options, $supported_options);
  if (!$option_parsed) {
    return;
  }

  $sources = array();

  if (!isset($source_machine_name)) {
    return drush_set_error(
      dt("No source machine_name provided.")
    );
  }
  else {
    $source = fcrl_harvest_get_harvestsource($source_machine_name);

    if (!$source) {
      return FALSE;
    }

    $message = t("Running the harvest rollback on %source_machine_name",
      array('%source_machine_name' => $source_machine_name));
    drush_log($message, 'notice');
    $sources[] = $source;
  }

  fcrl_harvest_rollback_sources($sources, $options);
}

/**
 * Relevent Info about the available Harvest Sources.
 */
function fcrl_harvest_drush_command_status() {
  $harvest_sources = fcrl_harvest_sources_definition();

  $rows = array();

  $rows[] = array(
    'machine name' => 'Machine Name',
    'label' => 'Label',
    'uri' => 'URI',
    'type' => 'Type',
  );

  // Build table array.
  foreach ($harvest_sources as $harvest_source) {
    $rows[] = array(
      'machine name' => $harvest_source->machineName,
      'label' => $harvest_source->label,
      'uri' => $harvest_source->uri,
      'type' => $harvest_source->type->label,
    );
  }

  drush_print_table($rows, TRUE);
}

/**
 * Drop the harvest migrate information about a harvest source.
 *
 * @param string $source_machine_name
 *
 *   Source machine name to migrate.
 */
function fcrl_harvest_drush_command_deregister($source_machine_name = NULL) {
  // Gather harvest migration options.
  $options = array();
  $supported_options = array();

  // Gather harvest migration options. If parsing the arguments fails just relay
  // on the parsing callback to oouput an appropriate message and stop.
  $option_parsed = fcrl_harvest_get_options($options, $supported_options);
  if (!$option_parsed) {
    return;
  }

  if (!isset($source_machine_name)) {
    $message = t("A harvest source needs to be specified.");
    drush_log($message, 'error');
    return FALSE;
  }

  $harvest_source = new HarvestSource($source_machine_name);

  if (!$harvest_source) {
    drush_log(t("Harvest Source not found!"), 'error');
    return FALSE;
  }

  fcrl_harvest_deregister_sources(array($harvest_source), $options);
}

/**
 * Wrapper for options parsing callbacks.
 */
function fcrl_harvest_get_options(&$options, $lookup = array()) {
  foreach ($lookup as $option) {
    $options = call_user_func('fcrl_harvest_get_option_' . $option, $options);
    if ($options === FALSE) {
      // Some argument parsing failed. escalate.
      return drush_set_error(NULL, dt('unsupported or invalid use of the !option option.',
      array('!option' => $option)));
    }
  }
  return TRUE;
}

/**
 * Helper function to parse the 'limit' option.
 *
 * This is taken from migrate.drush.inc.
 */
function fcrl_harvest_get_option_limit($options) {
  $limit = drush_get_option('limit');
  if ($limit) {
    $parts = explode(' ', $limit);
    $options['limit']['value'] = $parts[0];
    // Default unit.
    if (!isset($parts[1])) {
      $parts[1] = 'items';
    }
    $options['limit']['unit'] = $parts[1];
    // Validation.
    if (!in_array($options['limit']['unit'],
      array('seconds', 'second', 'items', 'item'))) {
      return drush_set_error(NULL, dt("Invalid limit unit '!unit'",
      array('!unit' => $options['limit']['unit'])));
    }
  }
  return $options;
}

/**
 * Helper function to parse the 'instrument' option.
 *
 * This is taken from migrate.drush.inc.
 */
function fcrl_harvest_get_option_instrument($options) {
  $instrument = drush_get_option('instrument');
  global $_migrate_track_memory, $_migrate_track_timer;
  switch ($instrument) {
    case 'timer':
      $_migrate_track_timer = TRUE;
      break;

    case 'memory':
      $_migrate_track_memory = TRUE;
      break;

    case 'all':
      $_migrate_track_timer = TRUE;
      $_migrate_track_memory = TRUE;
      break;
  }
  return $options;
}

/**
 * Helper function to parse the 'skiphash' option.
 */
function fcrl_harvest_get_option_skiphash($options) {
  $options['skiphash'] = drush_get_option('skiphash', FALSE);
  return $options;
}

/**
 * Helper function to parse the 'idlist' option.
 *
 * This is taken from migrate.drush.inc.
 */
function fcrl_harvest_get_option_idlist($options) {
  if ($idlist = drush_get_option('idlist', FALSE)) {
    $options['idlist'] = $idlist;
  }
  return $options;
}

/**
 * Return the HarvestSource from machine name.
 */
function fcrl_harvest_get_harvestsource($source_machine_name) {
  $source = NULL;

  try {
    $source = new HarvestSource($source_machine_name);
  }
  catch (Exception $exception) {
    $message = t("No source with machine name ") . $source_machine_name . t(" found.");
    return drush_set_error(NULL, $message);
  }

  return $source;
}

/**
 * Get a count of orphaned resources.
 */
function drush_fcrl_harvest_orphaned_resources_count() {
  $result = db_query("SELECT count(node.nid) AS nid FROM
  {node} node
  LEFT JOIN {field_data_field_dataset_ref} field_data_field_dataset_ref ON node.nid = field_data_field_dataset_ref.entity_id AND (field_data_field_dataset_ref.entity_type = 'node' AND field_data_field_dataset_ref.deleted = '0')
  WHERE (( (node.status = '1') AND (node.type IN  ('resource')) AND (field_data_field_dataset_ref.field_dataset_ref_target_id IS NULL ) ))
  ")->fetchAll();
  drush_print(dt('There are !count orphaned resources', array('!count' => $result[0]->nid)));
  return TRUE;
}

/**
 * Delete orphaned resources.
 */
function drush_fcrl_harvest_orphaned_resources_delete() {
  $results = db_query("SELECT node.nid AS nid FROM
  {node} node
  LEFT JOIN {field_data_field_dataset_ref} field_data_field_dataset_ref ON node.nid = field_data_field_dataset_ref.entity_id AND (field_data_field_dataset_ref.entity_type = 'node' AND field_data_field_dataset_ref.deleted = '0')
  WHERE (( (node.status = '1') AND (node.type IN  ('resource')) AND (field_data_field_dataset_ref.field_dataset_ref_target_id IS NULL ) ))
  ")->fetchAll();
  foreach ($results as $result) {
    drush_print(dt('Deleting nid !nid', array('!nid' => $result->nid)));
    node_delete($result->nid);
  }
  return TRUE;
}
