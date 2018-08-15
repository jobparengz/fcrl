<?php

// @codingStandardsIgnoreFile
namespace Drupal\FCRLExtension\Context;

use Behat\Behat\Hook\Scope\BeforeFeatureScope;
use Behat\Behat\Hook\Scope\AfterFeatureScope;
use Drupal\FCRLExtension\Hook\Scope\BeforeFCRLEntityCreateScope;

/**
 * Defines application features from the specific context.
 */
class LinkcheckerContext extends RawFCRLContext {

  protected $old_global_user;
  private static $modules_before_feature = array();
  private static $users_before_feature = array();

  /**
   * @BeforeFeature @enableFCRL_Linkchecker
   */
  public static function enableFCRL_Linkchecker(BeforeFeatureScope $scope)
  {
    self::$modules_before_feature = module_list(TRUE);
    self::$users_before_feature = array_keys(entity_load('user'));
    define('MAINTENANCE_MODE', 'update');
    @module_enable(array(
      'linkchecker',
      'fcrl_linkchecker',
    ));

    drupal_flush_all_caches();
    node_access_rebuild(TRUE);
  }

  /**
   * @AfterFeature @enableFCRL_Linkchecker
   */
  public static function disableFCRL_Linkchecker(AfterFeatureScope $event)
  {
    $modules_after_feature = module_list(TRUE);
    $users_after_feature = array_keys(entity_load('user'));

    $modules_to_disable = array_diff_assoc(
      $modules_after_feature,
      self::$modules_before_feature
    );

    $users_to_delete = array_diff_assoc(
      $users_after_feature,
      self::$users_before_feature
    );

    // Clean users and disable modules.
    entity_delete_multiple('user', $users_to_delete);
    module_disable(array_values($modules_to_disable));
    drupal_flush_all_caches();
    node_access_rebuild(TRUE);
  }

}
