<?php

namespace Drupal\FCRLExtension\Hook\Call;

use Drupal\FCRLExtension\Hook\Scope\FCRLEntityScope;
use Drupal\DrupalExtension\Hook\Call\EntityHook;

/**
 * BeforeNodeCreate hook class.
 */
class BeforeFCRLEntityCreate extends EntityHook {

  /**
   * Initializes hook.
   */
  public function __construct($filterString, $callable, $description = null) {
    parent::__construct(FCRLEntityScope::BEFORE, $filterString, $callable, $description);
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return 'BeforeFCRLEntityCreate';
  }
}
