<?php

/**
 * @file
 * Drush integration for the fcrl_fixtures module.
 */

/**
 * Implements hook_drush_command().
 */
function fcrl_fixtures_drush_command() {
  $items = array();
  $items['fcrl-save-data'] = array(
    'description' => dt('Creates JSON files out of fcrl api endpoints'),
    'arguments' => array(),
    'aliases' => array('dsd'),
  );
  return $items;
}

/**
 * Drush save_fixtures command callback.
 */
function drush_fcrl_fixtures_fcrl_save_data() {
  $args = drush_get_arguments();
  $nids = array();
  if (isset($args[1])) {
    $nids = array($args[1]);
  }
  fcrl_fixtures_fcrl_save_data($nids);
}
