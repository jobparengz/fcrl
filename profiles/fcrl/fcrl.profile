<?php

/**
 * @file
 * Additional setup tasks for FCRL.
 */

/**
 * Implements hook_install_tasks().
 */
function fcrl_install_tasks() {
  return array(
    'fcrl_additional_setup' => array(
      'display_name' => t('FCRL final setup tasks'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    ),
  );
}

/**
 * FCRL setup task. Runs a series of helper functions defined below.
 */
function fcrl_additional_setup() {
  return array(
    'operations' => array(
      array('fcrl_theme_config', array()),
      array('fcrl_change_block_titles', array()),
      array('fcrl_markdown_setup', array()),
      array('fcrl_enable_optional_module', array('fcrl_permissions')),
      array('fcrl_enable_optional_module', array('fcrl_default_topics')),
      array('fcrl_revert_feature',
        array(
          'fcrl_sitewide_menu',
          array('content_menu_links', 'menu_links'),
        ),
      ),
      array('fcrl_revert_feature',
        array(
          'fcrl_dataset_content_types',
          array('field_base', 'field_instance'),
        ),
      ),
      array('fcrl_revert_feature',
        array(
          'fcrl_dataset_groups',
          array('field_base'),
        ),
      ),
      array('fcrl_revert_feature',
        array(
          'fcrl_dataset_groups_perms',
          array('og_features_permission'),
        ),
      ),
      array('fcrl_revert_feature',
        array(
          'fcrl_permissions',
          array('roles_permissions'),
        ),
      ),
      array('fcrl_revert_feature', array('fcrl_sitewide', array('variable'))),
      array('fcrl_revert_feature',
        array(
          'fcrl_sitewide_menu',
          array('custom_menu', 'menu_links'),
        ),
      ),
      // The module needs to be enabled after the revert on fcrl_dataset_groups
      // is done. If not, a warning will appear during install about
      // og_group_ref not being present.
      array('fcrl_enable_optional_module', array('fcrl_default_content')),
      array('fcrl_add_default_menu_links', array()),
      array('fcrl_build_menu_links', array()),
      array('fcrl_flush_image_styles', array()),
      array('fcrl_colorizer_reset', array()),
      array('fcrl_misc_variables_set', array()),
      array('fcrl_group_link_delete', array()),
      array('fcrl_set_adminrole', array()),
      array('fcrl_set_roleassign_roles', array()),
      array('fcrl_set_bueditor_excludes', array()),
      array('fcrl_post_install', array()),
    ),
  );
}

/**
 * Set up theme options for fishcoral_project on install.
 *
 * @param array &$context
 *   Batch context.
 */
function fcrl_theme_config(array &$context) {
  $context['message'] = t('Setting theme options.');
  theme_enable(array('fishcoral_project'));
  theme_enable(array('seven'));
  variable_set('theme_default', 'fishcoral_project');
  variable_set('admin_theme', '0');

  // Disable the default Bartik theme.
  theme_disable(array('bartik'));
  theme_disable(array('seven'));
}

/**
 * Change block titles for selected blocks.
 */
function fcrl_change_block_titles(&$context) {
  $context['message'] = t('Changing block titles for selected blocks');
  db_query("UPDATE {block} SET title ='<none>' WHERE delta = 'main-menu' OR delta = 'login'");
  variable_set('node_access_needs_rebuild', FALSE);
  variable_set('gravatar_size', 190);
}

/**
 * Make sure markdown editor installs correctly.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_markdown_setup(array &$context) {
  $context['message'] = t('Installing Markdown');
  module_load_include('install', 'markdowneditor', 'markdowneditor');
  _markdowneditor_insert_latest();
  $data = array(
    'pages' => "node/*\ncomment/*\nsystem/ajax",
    'eid' => 5,
  );
  drupal_write_record('bueditor_editors', $data, array('eid'));
  // Remove unsupported markdown options.
  fcrl_delete_markdown_buttons($context);

  return $context;
}

/**
 * Enable a module on install we don't want as a dependency for existing sites.
 *
 * @param string $module
 *   The module name.
 * @param array $context
 *   Batch context.
 */
function fcrl_enable_optional_module($module, array &$context) {
  module_enable(array($module));
  $module_info = system_get_info('module', $module);
  $context['message'] = t('Enabled %module', array('%module' => $module_info['name']));
}

/**
 * Revert particular feature components that have been overridden during setup.
 *
 * @param string $feature
 *   The feature module name.
 * @param array $components
 *   Array of components to revert.
 * @param array $context
 *   Batch context.
 */
function fcrl_revert_feature($feature, array $components, array &$context) {
  $context['message'] = t('Reverting feature %feature_name', array('%feature_name' => $feature));
  features_revert(array($feature => $components));
}

/**
 * Import default menu links.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_add_default_menu_links(array &$context) {
  $menu_links = array();
  // Exported menu link: main-menu_dataset:search/type/dataset.
  $menu_links['main-menu_dataset:search/type/dataset'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/type/dataset',
    'router_path' => 'search/type/dataset',
    'link_title' => 'Datasets',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dataset:search/type/dataset',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 1,
  );
  // Exported menu link: main-menu_dataset:search/type/data_dashboard.
  $menu_links['main-menu_dashboard:search/type/data_dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/type/data_dashboard',
    'router_path' => 'search/type/data_dashboard',
    'link_title' => 'Dashboards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dashboard:search/type/data_dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: main-menu_stories:stories.
  $menu_links['main-menu_stories:stories'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'stories',
    'router_path' => 'stories',
    'link_title' => 'Stories',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_stories:stories',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: main-menu_groups:groups.
  $menu_links['main-menu_groups:groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Groups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_groups:groups',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  t('Datasets');
  t('Dashboards');
  t('Stories');
  t('Groups');

  foreach ($menu_links as $menu_link) {
    menu_link_save($menu_link);
  }
}

/**
 * Build menu links.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_build_menu_links(array &$context) {
  module_load_include('inc', 'features', 'features.export');
  $context['message'] = t('Building menu links and assigning custom admin menus to roles');
  $menu_links = features_get_default('menu_links', 'fcrl_sitewide_menu');
  menu_links_features_rebuild_ordered($menu_links, TRUE);
  unset($_SESSION['messages']['warning']);
}

/**
 * Flush the image styles.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_flush_image_styles(array &$context) {
  $context['message'] = t('Flushing image styles');
  $image_styles = image_styles();
  foreach ($image_styles as $image_style) {
    image_style_flush($image_style);
  }
}

/**
 * Reset colorizer cache so colors are not blank at first page view.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_colorizer_reset(array &$context) {
  $context['message'] = t('Resetting colorizer cache');
  global $theme_key;
  $instance = $theme_key;
  drupal_alter('colorizer_instance', $instance);
  $palette = colorizer_get_palette($theme_key, $instance);
  $file = colorizer_update_stylesheet($theme_key, $theme_key, $palette);
  clearstatcache();
}

/**
 * Set a number of miscellaneous variables.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_misc_variables_set(array &$context) {
  $context['message'] = t('Setting misc FCRL variables');
  variable_set('honeypot_form_user_register_form', 1);
  variable_set('page_manager_node_view_disabled', FALSE);
  variable_set('page_manager_node_edit_disabled', FALSE);
  variable_set('page_manager_user_view_disabled', FALSE);
  variable_set('jquery_update_jquery_version', '1.10');
  // Disable selected views enabled by contributed modules.
  $views_disable = array(
    'og_extras_nodes' => TRUE,
    'feeds_log' => TRUE,
    'groups_page' => TRUE,
    'og_extras_groups' => TRUE,
    'og_extras_members' => TRUE,
    'dataset' => TRUE,
    'admin_views_file' => TRUE,
    'admin_views_node' => TRUE,
  );
  variable_set('views_defaults', $views_disable);
}

/**
 * Set the user admin role.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_set_adminrole(array &$context) {
  $context['message'] = t('Setting user admin role');
  if (!variable_get('user_admin_role')) {
    if ($role = user_role_load_by_name('administrator')) {
      variable_set('user_admin_role', $role->rid);
      return t('User admin role reset to "administrator."');
    }
    else {
      return t('Administrator role not found. Skipping update.');
    }
  }
  else {
    return t('User admin role already set. Skipping update.');
  }
}

/**
 * Remove unsupported markdown options.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_delete_markdown_buttons(array &$context) {
  $context['message'] = t('Removing unsupported Markdown buttons');
  $eid = db_query('SELECT eid FROM {bueditor_editors} WHERE name = :name', array(':name' => 'Markdowneditor'))->fetchField();
  db_delete('bueditor_buttons')
    ->condition('title', 'Insert a table')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Insert an abbreviation (word or acronym with definition)')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Insert a footnote')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Insert a horizontal ruler (horizontal line)')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Teaser break')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Insert a definition list')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Format selected text as code')
    ->condition('eid', $eid)
    ->execute();

  db_delete('bueditor_buttons')
    ->condition('title', 'Format selected text as a code block')
    ->condition('eid', $eid)
    ->execute();

  // Update markdown linebreak button with html.
  db_update('bueditor_buttons')
    ->fields(array('content' => '<br>'))
    ->condition('title', 'Insert a line break', '=')
    ->condition('eid', $eid)
    ->execute();
}

/**
 * Fix extra group links.
 *
 * The groups view in og_extras creates a menu item even when the view is
 * disabled. This will delete the extra menu item until the og_extras is removed
 * from the code base.
 *
 * @param array $context
 *   Batch context.
 */
function fcrl_group_link_delete(array &$context) {
  $context['message'] = t('Removing og_extra groups link');
  db_query('DELETE FROM {menu_links} WHERE link_path = :link_path LIMIT 1', array(':link_path' => 'groups'));
}

/**
 * Set up the roles that sitemanagers are allowed to assign via roleassign.
 */
function fcrl_set_roleassign_roles(&$context) {
  $context['message'] = t('Configuring Role Assign module');
  $roles_rids = array_flip(user_roles());
  $roleassign_roles = array($roles_rids['administrator'] => 0);

  // Should be everything except admin:
  $allowed_roles = array('editor', 'site manager', 'content creator');

  foreach ($allowed_roles as $role) {
    $roleassign_roles[$roles_rids[$role]] = (string) $roles_rids[$role];
  }
  variable_set('roleassign_roles', $roleassign_roles);
}

/**
 * Configures BUEditor and markdown test format.
 */
function fcrl_bueditor_markdown_install() {
  module_enable(array('bueditor_plus'));

  $context = array();
  fcrl_set_roleassign_roles($context);

  // Delete the old bueditor settings and profile.
  db_delete('bueditor_editors')
    ->condition('name', 'Markdowneditor')
    ->execute();

  db_delete('bueditor_plus_profiles')
    ->condition('name', 'Global')
    ->execute();

  // Create the new bueditor settings and profile.
  fcrl_markdown_setup($context);
  features_revert(array('fcrl_sitewide' => array('filter')));

  $roles = user_roles();
  $bueditor_roles = array();

  foreach ($roles as $rid => $role) {
    switch ($role) {
      case 'anonymous user':
        $bueditor_roles[$rid] = array(
          'weight' => 12,
          'editor' => _fcrl_bueditor_by_name('Commenter'),
          'alt' => 0,
        );
        break;

      case 'administrator':
      case 'content creator':
      case 'editor':
      case 'site manager':
        $bueditor_roles[$rid] = array(
          'weight' => 0,
          'editor' => _fcrl_bueditor_by_name('Markdowneditor'),
          'alt' => 0,
        );
        break;

      default:
        $bueditor_roles[$rid] = array(
          'weight' => 11,
          'editor' => 0,
          'alt' => 0,
        );
        break;
    }
  }

  $eid = db_select("bueditor_editors", "bue")
    ->fields("bue", array("eid"))
    ->condition("name", "Markdowneditor")
    ->execute()
    ->fetchField();

  variable_set('bueditor_roles', $bueditor_roles);
  variable_set('bueditor_user1', $eid);

  $data = array(
    'html' => array('default' => $eid, 'alternative' => 0),
    'plain_text' => array('plain_text' => 0, 'alternative' => 0),
  );

  db_insert('bueditor_plus_profiles')
    ->fields(array(
      'name' => 'Global',
      'data' => serialize($data),
      'global' => 1,
    ))
    ->execute();
}

/**
 * Extracts the editor id for an editor name.
 *
 * @param string $name
 *   The user role name of the editor.
 *
 * @return int
 *   The eid of the editor.
 */
function _fcrl_bueditor_by_name($name = '') {
  module_load_include("inc", "bueditor");

  if ($name == '') {
    return 0;
  }

  $editors = bueditor_editors('all');

  foreach ($editors as $eid => $editor) {
    if ($editor->name == $name) {
      return $eid;
    }
  }

  return 0;
}

/**
 * Add data dictionary textarea id to bueditor excludes list.
 */
function fcrl_set_bueditor_excludes() {
  db_update('bueditor_editors')
    ->fields(array(
      'excludes' => 'edit-log
edit-menu-description
*data-dictionary*',
    ))
    ->condition('eid', '5')
    ->execute();
}

/**
 * Final post-install tasks.
 */
function fcrl_post_install() {
  variable_set('preprocess_css', 1);
  variable_set('preprocess_js', 1);
}
