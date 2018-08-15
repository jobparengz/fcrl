<?php

/**
 * @file
 * Migration class used to import Default Panelized Nodes from fixtures.
 */

/**
 * Default content extension of panelized node parent migration class.
 */
class DefaultContentPanelizedNodesImport extends FcrlPanelizedNodesImport {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {

    if (!isset($arguments['endpoint'])) {
      $arguments['endpoint'] = drupal_get_path('module', 'fcrl_default_content') . '/data/';
      $arguments['list_url'] = 'panelized_node_list.json';
      $arguments['item_url'] = 'panelized_node_show%3Fid=:id.json';
    }

    parent::__construct($arguments);
  }

}
