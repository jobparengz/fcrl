<?php

/**
 * @file
 * Migration class used to import Default Resources from fixtures.
 */

/**
 * Default content extension of resource fixtures migration class.
 */
class DefaultContentResourceImport extends FcrlResourceImport {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    if (!isset($arguments['endpoint'])) {
      $arguments['endpoint'] = drupal_get_path('module', 'fcrl_default_content') . '/data/';
      $arguments['list_url'] = 'resource_list.json';
      $arguments['item_url'] = 'resource_show%3Fid=:id.json';
    }
    parent::__construct($arguments);
  }

}
