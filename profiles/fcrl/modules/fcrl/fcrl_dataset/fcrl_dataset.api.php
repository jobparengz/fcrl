<?php

/**
 * @file
 * Hooks provided by FCRL Dataset module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Add to or alter the array of external previews available to FCRL Dataset.
 *
 * @param array $previews
 *   An associative array of preview types. See
 *   fcrl_dataset_teaser_get_external_previews() for documentation on array
 *   elements.
 * @param object $node
 *   The dataset node object.
 */
function hook_fcrl_dataset_external_previews_alter(&$previews, $node) {
  $previews['third_party_service'] = array(
    'name' => t('Third-Party Mapping Service'),
    'description' =>
    t('A longer description of the preview.')
    'link_callback' => 'mymodule_preview_link',
    'suggested_format' => array('geojson'),
  );
}

/**
 * @} End of "addtogroup hooks".
 */
