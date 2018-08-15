<?php
/**
 * @file
 * registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function registration_node_info() {
  $items = array(
    'reg_form' => array(
      'name' => t('Beneficiaries Registration'),
      'base' => 'node_content',
      'description' => t('Data can be any file or link to a file containing useful data.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
