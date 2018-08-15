<?php

/**
 * @file
 * Hooks provided by FCRL Datastore API module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allows fields exclusions to be altered for API queries.
 *
 * @param array $excludes
 *   List of fields to exclude.
 */
function hook_fcrl_datastore_api_field_excluded_alter(array &$excludes) {
  $excludes[] = 'exclude_this_field';
}

/**
 * @} End of "addtogroup hooks".
 */
