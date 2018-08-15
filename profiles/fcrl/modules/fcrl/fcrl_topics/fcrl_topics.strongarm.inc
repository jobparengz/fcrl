<?php

/**
 * @file
 * fcrl_topics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fcrl_topics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_expanded_fcrl_topics';
  $strongarm->value = 1;
  $export['taxonomy_menu_expanded_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_path_fcrl_topics';
  $strongarm->value = 'taxonomy_menu_path_default';
  $export['taxonomy_menu_path_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_rebuild_fcrl_topics';
  $strongarm->value = 0;
  $export['taxonomy_menu_rebuild_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_sync_fcrl_topics';
  $strongarm->value = 1;
  $export['taxonomy_menu_sync_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_term_item_description_fcrl_topics';
  $strongarm->value = 0;
  $export['taxonomy_menu_term_item_description_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_vocab_menu_fcrl_topics';
  $strongarm->value = 'main-menu';
  $export['taxonomy_menu_vocab_menu_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_description_fcrl_topics';
  $strongarm->value = 0;
  $export['taxonomy_menu_voc_item_description_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_item_fcrl_topics';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_item_fcrl_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_voc_name_fcrl_topics';
  $strongarm->value = FALSE;
  $export['taxonomy_menu_voc_name_fcrl_topics'] = $strongarm;

  return $export;
}
