<?php
/**
 * @file
 * Entity scope.
 */
namespace Drupal\FCRLExtension\Hook\Scope;

use Behat\Testwork\Hook\Scope\HookScope;

/**
 * Represents an Entity hook scope.
 */
final class BeforeFCRLEntityCreateScope extends FCRLEntityScope {

  /**
   * Return the scope name.
   *
   * @return string
   */
  public function getName() {
    return self::BEFORE;
  }

}
