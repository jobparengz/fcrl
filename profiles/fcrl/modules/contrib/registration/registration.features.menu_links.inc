<?php
/**
 * @file
 * registration.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function registration_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_registration:node/88.
  $menu_links['main-menu_registration:node/88'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/88',
    'router_path' => 'node/%',
    'link_title' => 'Registration',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_registration:node/88',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Registration');

  return $menu_links;
}
