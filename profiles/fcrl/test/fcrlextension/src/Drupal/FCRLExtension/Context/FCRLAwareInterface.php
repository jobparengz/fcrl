<?php

namespace Drupal\FCRLExtension\Context;

use Drupal\FCRLExtension\ServiceContainer\EntityStore;
use Drupal\FCRLExtension\ServiceContainer\PageStore;
use Drupal\DrupalExtension\Context\DrupalAwareInterface;

interface FCRLAwareInterface extends DrupalAwareInterface {

  /**
   * Sets EntityStore instance.
   * @param $store
   * @return
   */
  public function setEntityStore(EntityStore $store);

  /**
   * Sets Page Store instance.
   * @param $store
   * @return
   */
  public function setPageStore(PageStore $store);

}
