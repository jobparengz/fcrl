<?php

namespace Drupal\FCRLExtension\Context\Initializer;

use Behat\Behat\Context\Initializer\ContextInitializer;
use Behat\Behat\Context\Context;
use Drupal\FCRLExtension\Context\FCRLAwareInterface;
use Drupal\DrupalExtension\Context\RawDrupalContext;

class FCRLAwareInitializer extends RawDrupalContext implements ContextInitializer {
  private $entityStore, $pageStore, $parameters;

  public function __construct($entityStore, $pageStore, array $parameters) {
    $this->entityStore = $entityStore;
    $this->pageStore = $pageStore;
    $this->parameters = $parameters;
  }

  /**
   * {@inheritdocs}
   */
  public function initializeContext(Context $context) {

    // All contexts are passed here, only RawFCRLEntityContext is allowed.
    if (!$context instanceof FCRLAwareInterface) {
      return;
    }
    $context->setEntityStore($this->entityStore);
    $context->setPageStore($this->pageStore);

    // Add all parameters to the context.
    //$context->setParameters($this->parameters);
  }

}
