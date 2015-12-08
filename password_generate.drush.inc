<?php
/**
 * @file
 * Password generating Drush command.
 *
 * Usage:
 * drush password-generate [password-length]
 *
 * @author Mike Shiyan (https://www.drupal.org/u/pingwin4eg)
 */

/**
 * Implements hook_drush_command().
 */
function password_generate_drush_command() {
  $items['password-generate'] = array(
    'description' => 'Generates a password',
    'aliases' => array('passgen'),
    'arguments' => array(
      'length' => '(optional) Password length. Defaults to 12.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
  );

  return $items;
}

/**
 * Generates a password.
 */
function drush_password_generate($length = 12) {
  $str = 'abcdefghijklmnopqrstuvwxyz';
  $str .= strtoupper($str);
  $str .= '0123456789~!?@#$%^&*()-_+=;:.,<>[]{}\|/';

  $pass = '';
  while (strlen($pass) < $length) {
    $pass .= $str[mt_rand(0, strlen($str) - 1)];
  }

  drush_print($pass, 2);

  return TRUE;
}
