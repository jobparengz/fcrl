<?php
/**
 * @file
 * Unit tests for fcrl_workflow functions.
 */

module_load_include('module', 'fcrl_workflow');

/**
 * Base fcrl_workflow unit test class.
 */
class FcrlWorkflowBaseTest extends PHPUnit_Framework_TestCase {

  /**
   * Verify that email errors get removed from messages.
   *
   * @covers fcrl_workflow().
   */
  public function testFcrlWorlflowRemoveEmailErrors() {
    // When no email error.
    $error = 'This is not an email error.';
    drupal_set_message($error, 'error');
    $expected = ['error' => [$error]];
    fcrl_workflow_remove_email_errors();

    $actual = drupal_get_messages('error');
    $this->assertEquals($actual, $expected);

    // When mixed email error with regular error.
    $email_error = 'This is an email notifications error.';
    $expected = ['error' => [$error]];
    drupal_set_message($error, 'error');
    drupal_set_message($email_error, 'error');
    fcrl_workflow_remove_email_errors();

    $actual = drupal_get_messages('error');
    $this->assertEquals($actual, $expected);

    // When only an email error.
    $email_error = 'This is an email notifications error.';
    drupal_set_message($email_error, 'error');
    $expected = [];
    fcrl_workflow_remove_email_errors();

    $actual = drupal_get_messages('error');
    $this->assertEquals($actual, $expected);
  }

  public function testGetEmailReceiverUser() {
  }
}
