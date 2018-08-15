<?php

/**
 * @file
 * API functions.
 */

/**
 * Register your import/export module here.
 *
 * This will allow you to use the drush 'fcrl-save-data' commmand to add
 * exported datasets to your modules 'data' folder.
 *
 * If no modules register then datasets are exported to the 'data' folder in
 * this module.
 */
function hook_fcrl_fixtures_register() {
  return 'my_module';
}
