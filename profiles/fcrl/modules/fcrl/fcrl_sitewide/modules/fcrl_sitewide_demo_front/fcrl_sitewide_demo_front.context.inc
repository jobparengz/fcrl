<?php

/**
 * @file
 * fcrl_sitewide_demo_front.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fcrl_sitewide_demo_front_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE;
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'fcrl_sitewide_demo_front-fcrl_demo_front' => array(
          'module' => 'fcrl_sitewide_demo_front',
          'delta' => 'fcrl_demo_front',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'fcrl_sitewide_demo_front-fcrl_add_front' => array(
          'module' => 'fcrl_sitewide_demo_front',
          'delta' => 'fcrl_add_front',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'views-popular_tags-block' => array(
          'module' => 'views',
          'delta' => 'popular_tags-block',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
        'fcrl_sitewide_demo_front-fcrl_search_front' => array(
          'module' => 'fcrl_sitewide_demo_front',
          'delta' => 'fcrl_search_front',
          'region' => 'preface_second',
          'weight' => '-9',
        ),
        'views-front_page_group_grid-block' => array(
          'module' => 'views',
          'delta' => 'front_page_group_grid-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  $export['front'] = $context;

  return $export;
}
