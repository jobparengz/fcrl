<?php

/**
 * @file
 * fcrl_sitewide.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function fcrl_sitewide_defaultconfig_features() {
  return array(
    'fcrl_sitewide' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function fcrl_sitewide_defaultconfig_strongarm() {
  $export = array();

  return $export;
}
