<?php

/**
 * @file
 * Admin page callbacks for the common body class module.
 */

/**
 * Menu callback for admin/structure/common_body_class.
 */
function common_body_class_admin_display() {
  $header = array(
    array('data' => t('Class')),
    array('data' => t('Visibility')),
    array('data' => t('Page')),
    array('data' => t('Status')),
    array('data' => t('Action')),
  );
  $rows = array();
  $query = db_select('common_body_class', 'cbc');
  $query->fields('cbc', array(
    'cbcid',
    'class_name',
    'pages',
    'status',
    'visibility',
  )
  );
  $query = $query->extend('TableSort')->extend('PagerDefault')->limit(20);
  $results = $query->execute();
  while ($data = $results->fetchObject()) {
    $pages = str_replace("\n", '<br />', check_plain($data->pages));
    switch ($data->visibility) {
      case 0:
        $visible = t('All pages except those listed');
        break;

      case 1:
        $visible = t('Only the listed pages');
        break;

      case 2:
        $visible = t('Only the listed pages');
        $pages = '[PHP CODE]';
        break;

      default:
        $visible = '';
        break;
    }
    $rows[] = array(
      filter_xss($data->class_name),
      $visible,
      '<pre>' . $pages . '</pre>',
      ($data->status == 1) ? t('Enabled') : t('Disabled'),
      l(t('Edit'), 'admin/structure/common_body_class/' . $data->cbcid . '/edit') . ' | ' .
      l(t('Delete'), 'admin/structure/common_body_class/' . $data->cbcid . '/delete'),
    );
  }
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    "sticky" => TRUE,
    "empty" => t("Table has no custom common class!"),
    'attributes' => array('class' => array('common-body-class-list')),
  )) . theme('pager');

  return $output;
}

/**
 * Form constructor for the add common class form.
 *
 * @see common_body_class_add_class_form_validate()
 * @see common_body_class_add_class_form_submit()
 * @ingroup forms
 */
function common_body_class_add_class_form($form, &$form_state) {
  return common_body_class_admin_class_configure($form, $form_state, NULL);
}

/**
 * Form validation handler for common_body_class_add_class_form().
 *
 * @see common_body_class_add_class_form()
 * @see common_body_class_add_class_form_submit()
 */
function common_body_class_add_class_form_validate($form, &$form_state) {
  $cbc_exists = (bool) db_query_range('SELECT 1 FROM {common_body_class} WHERE class_name = :class_name', 0, 1, array(':class_name' => $form_state['values']['class_name']))->fetchField();

  if (empty($form_state['values']['class_name']) || $cbc_exists) {
    form_set_error('class_name', t('Ensure that each class(s) name is unique.'));
  }
}

/**
 * Form submission handler for common_body_class_add_class_form().
 *
 * Saves the new common class.
 *
 * @see common_body_class_add_class_form()
 * @see common_body_class_add_class_form_validate()
 */
function common_body_class_add_class_form_submit($form, &$form_state) {
  $transaction = db_transaction();
  try {
    $cbc_data = array(
      'visibility' => (int) $form_state['values']['visibility'],
      'pages' => trim($form_state['values']['pages']),
      'status' => (int) $form_state['values']['status'],
      'class_name' => $form_state['values']['class_name'],
    );
    drupal_write_record('common_body_class', $cbc_data);
    $cbcid = $cbc_data['cbcid'];
    // Store cbc id to allow other tables to work with new cbcid.
    $form_state['values']['cbcid'] = $cbcid;

    foreach (array_filter($form_state['values']['roles']) as $rid) {
      $cbc_role_data = array(
        'cbcid' => $form_state['values']['cbcid'],
        'rid' => $rid,
      );
      drupal_write_record('common_body_class_role', $cbc_role_data);
    }
  }
  catch (Exception $e) {
    $transaction->rollback();
    watchdog_exception('common_body_class', $e);
    throw $e;
  }

  drupal_set_message(t('The class has been created.'));
  cache_clear_all(NULL, 'cache_page');
  $form_state['redirect'] = 'admin/structure/common_body_class';
}

/**
 * Form constructor for the common body class configuration form.
 *
 * Also used by common_body_class_add_class_form().
 *
 * @param int $cbcid
 *   Unique ID of the common class.
 *
 * @see common_body_class_admin_class_configure_validate()
 * @see common_body_class_admin_class_configure_submit()
 * @ingroup forms
 */
function common_body_class_admin_class_configure($form, &$form_state, $cbcid) {
  $cbc = common_body_class_data_load($cbcid);
  $form['cbcid'] = array(
    '#type' => 'value',
    '#value' => $cbc->cbcid,
  );
  $class_description = t("The CSS class names will be added to the body tag. You may define multiples classes separated by spaces.");
  $form['class_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Class Name'),
    '#default_value' => isset($cbc->class_name) ? $cbc->class_name : '',
    '#description' => $class_description,
    '#required' => TRUE,
  );
  if (module_exists('token')) {
    $form['class_name']['#description'] .= ' ' . t('This field supports tokens.');
    $form['class_name']['#element_validate'] = array('token_element_validate');
    $form['class_name']['#token_types'] = array();
  }
  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#options' => array(1 => t('Enabled'), 0 => t('Disabled')),
    '#default_value' => isset($cbc->status) ? $cbc->status : 1,
    '#required' => TRUE,
  );

  // Visibility settings.
  $form['visibility_title'] = array(
    '#type' => 'item',
    '#title' => t('Visibility settings'),
  );
  $form['visibility'] = array(
    '#type' => 'vertical_tabs',
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'common_body_class') . '/common_body_class.js'),
    ),
  );
  // Per-path visibility.
  $form['visibility']['path'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pages'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'visibility',
    '#weight' => 0,
  );
  $access = user_access('use PHP for settings');
  if (isset($cbc->visibility) && $cbc->visibility == COMMON_BODY_CLASS_VISIBILITY_PHP && !$access) {
    $form['visibility']['path']['visibility'] = array(
      '#type' => 'value',
      '#value' => COMMON_BODY_CLASS_VISIBILITY_PHP,
    );
    $form['visibility']['path']['pages'] = array(
      '#type' => 'value',
      '#value' => isset($cbc->pages) ? $cbc->pages : '',
    );
  }
  else {
    $options = array(
      COMMON_BODY_CLASS_VISIBILITY_NOTLISTED => t('All pages except those listed'),
      COMMON_BODY_CLASS_VISIBILITY_LISTED => t('Only the listed pages'),
    );
    $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array(
      '%blog' => 'blog',
      '%blog-wildcard' => 'blog/*',
      '%front' => '<front>',
    )
    );
    if (module_exists('php') && $access) {
      $options += array(COMMON_BODY_CLASS_VISIBILITY_PHP => t('Pages on which this PHP code returns <code>TRUE</code> (experts only)'));
      $title = t('Pages or PHP code');
      $description .= ' ' . t('If the PHP option is chosen, enter PHP code between %php. Note that executing incorrect PHP code can break your Drupal site.', array('%php' => '<?php ?>'));
    }
    else {
      $title = t('Pages');
    }
    $form['visibility']['path']['visibility'] = array(
      '#type' => 'radios',
      '#title' => t('Show class(s) on specific pages'),
      '#options' => $options,
      '#default_value' => isset($cbc->visibility) ? $cbc->visibility : COMMON_BODY_CLASS_VISIBILITY_NOTLISTED,
    );
    $form['visibility']['path']['pages'] = array(
      '#type' => 'textarea',
      '#title' => '<span class="element-invisible">' . $title . '</span>',
      '#default_value' => isset($cbc->pages) ? $cbc->pages : '',
      '#description' => $description,
    );
  }
  // Per-role visibility.
  $default_role_options = common_body_class_role_load($cbcid);
  $role_options = array_map('check_plain', user_roles());
  $form['visibility']['role'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'visibility',
    '#weight' => 10,
  );
  $form['visibility']['role']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show class(s) for specific roles'),
    '#default_value' => $default_role_options,
    '#options' => $role_options,
    '#description' => t('Show common body class only for the selected role(s). If you select no roles, the common body class will be visible to all users.'),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save class'),
  );

  return $form;
}

/**
 * Form validation handler for common_body_class_admin_class_configure().
 *
 * @see common_body_class_admin_class_configure()
 * @see common_body_class_admin_class_configure_submit()
 */
function common_body_class_admin_class_configure_validate($form, &$form_state) {
  $cbc_exists = (bool) db_query_range('SELECT 1 FROM {common_body_class} WHERE cbcid <> :cbcid AND class_name = :class_name', 0, 1, array(
    ':cbcid' => $form_state['values']['cbcid'],
    ':class_name' => $form_state['values']['class_name'],
  ))->fetchField();
  if (empty($form_state['values']['class_name']) || $cbc_exists) {
    form_set_error('class_name', t('Ensure that each class(s) name is unique.'));
  }
}

/**
 * Form submission handler for common_body_class_admin_class_configure().
 *
 * @see common_body_class_admin_class_configure()
 * @see common_body_class_admin_class_configure_validate()
 */
function common_body_class_admin_class_configure_submit($form, &$form_state) {
  $transaction = db_transaction();
  try {
    // Update class data.
    $cbc_data = array(
      'cbcid' => $form_state['values']['cbcid'],
      'visibility' => (int) $form_state['values']['visibility'],
      'pages' => trim($form_state['values']['pages']),
      'status' => (int) $form_state['values']['status'],
      'class_name' => $form_state['values']['class_name'],
    );
    drupal_write_record('common_body_class', $cbc_data, 'cbcid');
    // First delete all entry of role based on cbcid.
    db_delete('common_body_class_role')
      ->condition('cbcid', $form_state['values']['cbcid'])
      ->execute();
    // Insert new roles.
    foreach (array_filter($form_state['values']['roles']) as $rid) {
      $cbc_role_data = array(
        'cbcid' => $form_state['values']['cbcid'],
        'rid' => $rid,
      );
      drupal_write_record('common_body_class_role', $cbc_role_data);
    }
  }
  catch (Exception $e) {
    $transaction->rollback();
    watchdog_exception('common_body_class', $e);
    throw $e;
  }

  drupal_set_message(t('The class configuration has been saved.'));
  cache_clear_all(NULL, 'cache_page');
  $form_state['redirect'] = 'admin/structure/common_body_class';
}

/**
 * Form constructor for the common body class deletion form.
 *
 * @param int $cbcid
 *   The unique ID of the common class.
 *
 * @see common_body_class_admin_class_delete_submit()
 */
function common_body_class_admin_class_delete($form, &$form_state, $cbcid) {
  $cbc = common_body_class_data_load($cbcid);
  $form['class_name'] = array('#type' => 'hidden', '#value' => isset($cbc->class_name) ? $cbc->class_name : '');
  $form['cbcid'] = array('#type' => 'hidden', '#value' => $cbcid);

  return confirm_form($form, t('Are you sure you want to delete the class %class_name?', array('%class_name' => isset($cbc->class_name) ? $cbc->class_name : '')), 'admin/structure/common_body_class', '', t('Delete'), t('Cancel'));
}

/**
 * Form submission handler for common_body_class_admin_class_delete().
 *
 * @see common_body_class_admin_class_delete()
 */
function common_body_class_admin_class_delete_submit($form, &$form_state) {
  db_delete('common_body_class')
    ->condition('cbcid', $form_state['values']['cbcid'])
    ->execute();
  db_delete('common_body_class_role')
    ->condition('cbcid', $form_state['values']['cbcid'])
    ->execute();
  drupal_set_message(t('The class %name has been removed.', array('%name' => $form_state['values']['class_name'])));
  cache_clear_all(NULL, 'cache_page');
  $form_state['redirect'] = 'admin/structure/common_body_class';
}
