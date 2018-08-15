<?php
/**
 * @file
 * registration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function registration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__reg_form';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_gallery_node_thumbnail' => array(
        'custom_settings' => TRUE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_reg_form';
  $strongarm->value = array();
  $export['menu_options_reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_reg_form';
  $strongarm->value = 'main-menu:3004';
  $export['menu_parent_reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_reg_form';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_reg_form';
  $strongarm->value = '1';
  $export['node_preview_reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_reg_form';
  $strongarm->value = 0;
  $export['node_submitted_reg_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_reg_form_pattern';
  $strongarm->value = '';
  $export['pathauto_node_reg_form_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_abuyog_pattern';
  $strongarm->value = 'rviii-provinces/leyte/abuyog/[term:name]';
  $export['pathauto_taxonomy_term_abuyog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_agusan_del_norte_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/[term:name]';
  $export['pathauto_taxonomy_term_agusan_del_norte_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_albay_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_albay_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_anahawan_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/anahawan[term:name]';
  $export['pathauto_taxonomy_term_anahawan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_bacacay_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_bacacay_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_bacon_district_sorsogon_city_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_bacon_district_sorsogon_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_balangiga_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_balangiga_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_balatan_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_balatan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_balud_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_balud_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_barobo_pattern';
  $strongarm->value = 'caraga-provinces/surigao-del-sur/barobo/[term:name]';
  $export['pathauto_taxonomy_term_barobo_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_basey_pattern';
  $strongarm->value = 'rviii-provinces/western-samar/basey/[term:name]';
  $export['pathauto_taxonomy_term_basey_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_bato_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_bato_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_bayabas_pattern';
  $strongarm->value = 'caraga-provinces/surigao-del-sur/bayabas/[term:name]';
  $export['pathauto_taxonomy_term_bayabas_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_buenavista_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/buenavista/[term:name]';
  $export['pathauto_taxonomy_term_buenavista_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_bula_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_bula_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_butuan_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/butuan/[term:name]';
  $export['pathauto_taxonomy_term_butuan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_cabadbaran_city_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/cabadbaran_city/[term:name]';
  $export['pathauto_taxonomy_term_cabadbaran_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_cagwait_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-sur/cagwait/[term:name]';
  $export['pathauto_taxonomy_term_cagwait_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_calbiga_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/calbiga/[term:name]';
  $export['pathauto_taxonomy_term_calbiga_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_camsur_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_camsur_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_caraga_provinces_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_caraga_provinces_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_carmen_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/carmen/[term:name]';
  $export['pathauto_taxonomy_term_carmen_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_catbalogan_city_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/catbalogan-city/[term:name]';
  $export['pathauto_taxonomy_term_catbalogan_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_cawayan_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_cawayan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_daram_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/daram/[term:name]';
  $export['pathauto_taxonomy_term_daram_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_del_gallego_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_del_gallego_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_dulag_pattern';
  $strongarm->value = 'rviii-provinces/leyte/dulag/[term:name]';
  $export['pathauto_taxonomy_term_dulag_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_eastern_samar_0_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_eastern_samar_0_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_eastern_samar_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_eastern_samar_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_esperanza_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_esperanza_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_gender_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_gender_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_gen_macarthur_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_gen_macarthur_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_giporlos_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_giporlos_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_group_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_group_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_guiuan_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_guiuan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hernani_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_hernani_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hinatuan_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-sur/hinatuan/[term:name]';
  $export['pathauto_taxonomy_term_hinatuan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hinunangan_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/hinunangan[term:name]';
  $export['pathauto_taxonomy_term_hinunangan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_hinundayan_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/hinundayan/[term:name]';
  $export['pathauto_taxonomy_term_hinundayan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_jabonga_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/jabonga/[term:name]';
  $export['pathauto_taxonomy_term_jabonga_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_javier_pattern';
  $strongarm->value = 'rviii-provinces/leyte/javier/[term:name]';
  $export['pathauto_taxonomy_term_javier_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_jiabong_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/jiabong/[term:name]';
  $export['pathauto_taxonomy_term_jiabong_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_lawa_an_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_lawa_an_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_legaspi_city_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_legaspi_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_leyte_pattern';
  $strongarm->value = 'rviii-provinces/leyte/[term:name]';
  $export['pathauto_taxonomy_term_leyte_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_libmanan_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_libmanan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_liloan_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/liloan/[term:name]';
  $export['pathauto_taxonomy_term_liloan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_lupi_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_lupi_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_mac_arthur_pattern';
  $strongarm->value = 'rviii-provinces/leyte/mac-arthur/[term:name]';
  $export['pathauto_taxonomy_term_mac_arthur_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_magallanes_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/magallanes/[term:name]';
  $export['pathauto_taxonomy_term_magallanes_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_manito_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_manito_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_marabut_pattern';
  $strongarm->value = 'rviii-provinces/western-samar/marabut/[term:name]';
  $export['pathauto_taxonomy_term_marabut_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_masbate_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_masbate_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_mayorga_pattern';
  $strongarm->value = 'rviii-provinces/leyte/mayorga/[term:name]';
  $export['pathauto_taxonomy_term_mayorga_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_mercedes_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_mercedes_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_milagros_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_milagros_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_minalabac_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_minalabac_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_motiong_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/motiong/[term:name]';
  $export['pathauto_taxonomy_term_motiong_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_nasipit_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/nasipit/[term:name]';
  $export['pathauto_taxonomy_term_nasipit_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_others_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_others_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_palo_pattern';
  $strongarm->value = 'rviii-provinces/leyte/palo/[term:name]';
  $export['pathauto_taxonomy_term_palo_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_paranas_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/paranas/[term:name]';
  $export['pathauto_taxonomy_term_paranas_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pasacao_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_pasacao_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pinabacdao_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/pinabacdao/[term:name]';
  $export['pathauto_taxonomy_term_pinabacdao_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_placer_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_placer_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_prieto_diaz_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_prieto_diaz_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_quinapondan_0_pattern';
  $strongarm->value = 'rviii-provinces/eastern-samar-0/quinapondan-0/[term:name]';
  $export['pathauto_taxonomy_term_quinapondan_0_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_quinapondan_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_quinapondan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_ragay_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_ragay_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_rapu_rapu_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_rapu_rapu_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_regionstag_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_regionstag_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_rviii_provinces_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_rviii_provinces_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_rv_provinces_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_rv_provinces_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_salcedo_0_pattern';
  $strongarm->value = 'rviii-provinces/eastern-samar-0/salcedo-0/[term:name]';
  $export['pathauto_taxonomy_term_salcedo_0_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_salcedo_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_salcedo_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_santo_domingo_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_santo_domingo_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_san_fernando_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_san_fernando_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_san_juan_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/san-juan/[term:name]';
  $export['pathauto_taxonomy_term_san_juan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_san_pascual_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_san_pascual_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_san_sebastian_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/san-sebastian/[term:name]';
  $export['pathauto_taxonomy_term_san_sebastian_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_silago_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/silago/[term:name]';
  $export['pathauto_taxonomy_term_silago_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_sipocot_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_sipocot_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_sorsogon_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_sorsogon_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_southern_leyte_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/[term:name]';
  $export['pathauto_taxonomy_term_southern_leyte_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_st_bernard_pattern';
  $strongarm->value = 'rviii-provinces/southern-leyte/st-bernard/[term:name]';
  $export['pathauto_taxonomy_term_st_bernard_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_surigao_del_sur_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_surigao_del_sur_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tacloban_city_pattern';
  $strongarm->value = 'rviii-provinces/leyte/tacloban-city/[term:name]';
  $export['pathauto_taxonomy_term_tacloban_city_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_talalora_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/talalora/[term:name]';
  $export['pathauto_taxonomy_term_talalora_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tanauan_pattern';
  $strongarm->value = 'rviii-provinces/leyte/tanauan/[term:name]';
  $export['pathauto_taxonomy_term_tanauan_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tolosa_pattern';
  $strongarm->value = 'rviii-provinces/leyte/tolosa/[term:name]';
  $export['pathauto_taxonomy_term_tolosa_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tubay_pattern';
  $strongarm->value = 'caraga-provinces/agusan-del-norte/tubay/[term:name]';
  $export['pathauto_taxonomy_term_tubay_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_type_of_beneficiaries_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_type_of_beneficiaries_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_villareal_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/villareal/[term:name]';
  $export['pathauto_taxonomy_term_villareal_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_western_samar_0_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/[term:name]';
  $export['pathauto_taxonomy_term_western_samar_0_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_western_samar_pattern';
  $strongarm->value = 'rviii-provinces/western-samar/[term:name]';
  $export['pathauto_taxonomy_term_western_samar_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_zumarraga_pattern';
  $strongarm->value = 'rviii-provinces/western-samar-0/zumarraga/[term:name]';
  $export['pathauto_taxonomy_term_zumarraga_pattern'] = $strongarm;

  return $export;
}
