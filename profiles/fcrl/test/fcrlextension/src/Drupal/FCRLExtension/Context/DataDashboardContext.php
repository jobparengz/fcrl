<?php

namespace Drupal\FCRLExtension\Context;

use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
 */
class DataDashboardContext extends RawFCRLEntityContext{

  public function __construct(){
    parent::__construct(
      'node',
      'data_dashboard'
    );
  }

  /**
   * @Given data dashboards:
   */
  public function addDataDashboard(TableNode $dashboardtable){
    parent::addMultipleFromTable($dashboardtable);
  }
}
