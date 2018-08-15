<?php

/**
 * @file
 * Theme and preprocess functions for panels and panes.
 */

/**
 * Retrieves hero file.
 */
function fishcoral_project_hero_file_uri() {
  $fishcoral_project_hero_file_uri = &drupal_static(__FUNCTION__);
  if (!isset($fishcoral_project_hero_file_uri)) {
    $fid = theme_get_setting('hero_file');
    if ($cache = cache_get('fishcoral_project_hero_file_uri')) {
      $fishcoral_project_hero_file_uri = $cache->data;
    }
    else {
      $file = !empty($fid) ? file_load($fid) : FALSE;
      if ($file && isset($file->uri)) {
        $fishcoral_project_hero_file = $file->uri;
        cache_set('fishcoral_project_hero_file_uri', $fishcoral_project_hero_file, 'cache');
      }
      else {
        return FALSE;
      }
    }
  }
  return $fishcoral_project_hero_file_uri;
}

/**
 * Implements hook_preprocess().
 *
 * Set up variables for the front page.
 */
function fishcoral_project_preprocess(&$variables, $hook) {
  // Panel heading tag.
  $variables['title_heading'] = 'h2';

  // Front page vars.
  $front_url = drupal_get_normal_path(variable_get('site_frontpage', 'node'));
  $front_nid = NULL;
  $front = explode('/', $front_url);
  if (isset($front[0]) && isset($front[1]) && $front[0] == 'node' && ctype_digit($front[1])) {
    $front_nid = $front[1];
  }

  if (isset($variables['is_front']) && $variables['is_front'] || arg(1) == $front_nid) {
    $theme_path = drupal_get_path('theme', 'fishcoral_project');
    if ($uri = fishcoral_project_hero_file_uri()) :
      $variables['tint'] = 'tint';
      $variables['bg_color'] = 'transparent';
      $variables['path'] = 'url(' . file_create_url($uri) . ')';
    else :
      $background_option = theme_get_setting('background_option');
      if (empty($background_option)) :
        $variables['tint'] = 'no-tint';
        $variables['bg_color'] = '#005e9a';
        $variables['path'] = 'none';
      else :
        $uri = '';
        $variables['tint'] = 'no-tint';
        $variables['bg_color'] = '#' . ltrim($background_option, '#');
        $variables['path'] = 'none';
      endif;
    endif;
    $padding = theme_get_setting('hero_padding');
    $variables['padding'] = isset($padding) ? $padding : '0';
  }
}

/**
 * Implements hook_preprocess_panels_pane().
 */
function fishcoral_project_preprocess_panels_pane(&$vars) {
  // Add titles to dataset and resource forms.
  if ($vars['pane']->subtype == 'form' && empty($vars['content']['nid']['#value'])) {
    switch ($vars['content']['type']['#value']) {
      case 'dataset':
        $vars['title'] = "Add a Dataset";
        break;

      case 'resource':
        $vars['title'] = "Add a Resource";
        break;

      default:
        break;
    }
  }
}
