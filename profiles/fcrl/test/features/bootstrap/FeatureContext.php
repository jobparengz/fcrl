<?php

use Drupal\FCRLExtension\Context\RawFCRLContext;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawFCRLContext
{
  protected $old_global_user;

  // This file is only meant for temporary custom step functions or overrides to the fcrlextension.
  // Changes should be implemented in fcrlextension so that it works across all projects.

}
