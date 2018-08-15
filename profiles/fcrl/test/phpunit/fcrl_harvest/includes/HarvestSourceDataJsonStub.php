<?php

/**
 *
 */
class HarvestSourceDataJsonStub extends HarvestSource {

  /**
   *
   */
  public function __construct($uri) {
    $this->uri = $uri;
    $this->type = HarvestSourceType::getSourceType('datajson_v1_1_json');
    $this->label = 'Fcrl Harvest datajson Test Source';
    $this->machine_name = 'fcrl_harvest_datajson_test';
  }
}
