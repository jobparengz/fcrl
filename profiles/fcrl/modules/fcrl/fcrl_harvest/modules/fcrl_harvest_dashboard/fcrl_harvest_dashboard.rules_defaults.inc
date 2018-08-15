<?php

/**
 * @file
 * fcrl_harvest_dashboard.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function fcrl_harvest_dashboard_default_rules_configuration() {
  $items = array();
  $items['rules_fcrl_harvest_source_cache'] = entity_import('rules_config', '{ "rules_fcrl_harvest_source_cache" : {
      "LABEL" : "Cache Source(s)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Harvest" ],
      "REQUIRES" : [ "fcrl_harvest_dashboard" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "harvest_source" : { "label" : "Harvest Source", "type" : "node" } },
      "DO" : [
        { "fcrl_harvest_dashboard_harvest_cache_action" : { "node" : [ "harvest-source" ] } }
      ]
    }
  }');
  $items['rules_fcrl_harvest_source_cache_and_migrate'] = entity_import('rules_config', '{ "rules_fcrl_harvest_source_cache_and_migrate" : {
      "LABEL" : "Harvest (Cache and Migrate) Source(s)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Harvest" ],
      "REQUIRES" : [ "fcrl_harvest_dashboard" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "harvest_source" : { "label" : "Harvest Source", "type" : "node" } },
      "DO" : [
        { "fcrl_harvest_dashboard_harvest_cache_migrate_action" : { "node" : [ "harvest-source" ] } }
      ]
    }
  }');
  $items['rules_fcrl_harvest_source_migrate'] = entity_import('rules_config', '{ "rules_fcrl_harvest_source_migrate" : {
      "LABEL" : "Migrate Source(s)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Harvest" ],
      "REQUIRES" : [ "fcrl_harvest_dashboard" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "harvest_source" : { "label" : "Harvest Source", "type" : "node" } },
      "DO" : [
        { "fcrl_harvest_dashboard_harvest_migrate_action" : { "node" : [ "harvest-source" ] } }
      ]
    }
  }');
  return $items;
}
