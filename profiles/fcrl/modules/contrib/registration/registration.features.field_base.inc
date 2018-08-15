<?php
/**
 * @file
 * registration.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function registration_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_age'.
  $field_bases['field_age'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_age',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_ages'.
  $field_bases['field_ages'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ages',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_baranggay'.
  $field_bases['field_baranggay'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_baranggay',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'libmanan' => 'libmanan',
          'r5_albay_bacacay_brgy' => 'r5_albay_bacacay_brgy',
          'r5_albay_legaspi_city_brgy' => 'r5_albay_legaspi_city_brgy',
          'r5_albay_manito_brgy' => 'r5_albay_manito_brgy',
          'r5_albay_rapu_rapu_brgy' => 'r5_albay_rapu_rapu_brgy',
          'r5_albay_santo_brgy' => 'r5_albay_santo_brgy',
          'r5_balatan_brgy' => 'r5_balatan_brgy',
          'r5_bato_brgy' => 'r5_bato_brgy',
          'r5_bula_brgy' => 'r5_bula_brgy',
          'r5_del_gallego_brgy' => 'r5_del_gallego_brgy',
          'r5_lupi_minalabac_brgy' => 'r5_lupi_minalabac_brgy',
          'r5_masbate_cawayan_brgy' => 'r5_masbate_cawayan_brgy',
          'r5_masbate_esperanza' => 'r5_masbate_esperanza',
          'r5_masbate_milagros_brgy' => 'r5_masbate_milagros_brgy',
          'r5_masbate_placer_brgy' => 'r5_masbate_placer_brgy',
          'r5_minalabac_brgy' => 'r5_minalabac_brgy',
          'r5_pasacao_brgy' => 'r5_pasacao_brgy',
          'r5_ragay_brgy' => 'r5_ragay_brgy',
          'r5_san_fernando_brgy' => 'r5_san_fernando_brgy',
          'r5_san_pascual_brgy' => 'r5_san_pascual_brgy',
          'r5_sipocot_brgy' => 'r5_sipocot_brgy',
          'r5_sorsogon_bacon_district_sorsogon_city_brgy' => 'r5_sorsogon_bacon_district_sorsogon_city_brgy',
          'r5_sorsogon_prieto_diaz_brgy' => 'r5_sorsogon_prieto_diaz_brgy',
          'rviii_eastern_samar_balangiga_brgy' => 'rviii_eastern_samar_balangiga_brgy',
          'rviii_eastern_samar_bgiporlos_brgy' => 'rviii_eastern_samar_bgiporlos_brgy',
          'rviii_eastern_samar_gen_macarthur_brgy' => 'rviii_eastern_samar_gen_macarthur_brgy',
          'rviii_eastern_samar_guiuan_brgy' => 'rviii_eastern_samar_guiuan_brgy',
          'rviii_eastern_samar_hernani_brgy' => 'rviii_eastern_samar_hernani_brgy',
          'rviii_eastern_samar_lawa_an_brgy' => 'rviii_eastern_samar_lawa_an_brgy',
          'rviii_eastern_samar_mercedes_brgy' => 'rviii_eastern_samar_mercedes_brgy',
          'rviii_eastern_samar_quinapondan_brgy' => 'rviii_eastern_samar_quinapondan_brgy',
          'rviii_eastern_samar_salcedo_brgy' => 'rviii_eastern_samar_salcedo_brgy',
        ),
      ),
      'sync' => '',
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_gender'.
  $field_bases['field_gender'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gender',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'gender' => 'gender',
        ),
      ),
      'sync' => '',
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_municipality'.
  $field_bases['field_municipality'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_municipality',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'camsur' => 'camsur',
        ),
      ),
      'sync' => '',
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_name'.
  $field_bases['field_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_organizational_belong'.
  $field_bases['field_organizational_belong'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_organizational_belong',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_provinces'.
  $field_bases['field_provinces'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_provinces',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'r5_province' => 'r5_province',
        ),
      ),
      'sync' => '',
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_region'.
  $field_bases['field_region'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_region',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'regionstag' => 'regionstag',
        ),
      ),
      'sync' => '',
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_registration_num'.
  $field_bases['field_registration_num'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_registration_num',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_type_of_beneficiary'.
  $field_bases['field_type_of_beneficiary'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_type_of_beneficiary',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
