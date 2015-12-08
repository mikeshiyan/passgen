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
    'description' => 'Generates a password.',
    'aliases' => array('passgen'),
    'arguments' => array(
      'length' => '(optional) Password length. Defaults to 20.',
    ),
    'examples' => array(
      'drush password-generate 10' => 'Generate a password 10 characters long.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
  );

  return $items;
}

/**
 * Generates a password.
 */
function drush_password_generate($length = 20) {
  $password = '';

  // Allowable characters for the password. The number 0 and the letter 'O' have
  // been removed to avoid confusion between the two. The same is true for 'I',
  // 1, 'l' and '|'.
  $characters = 'abcdefghijkmnopqrstuvwxyz';
  $characters .= 'ABCDEFGHJKLMNPQRSTUVWXYZ';
  $characters .= '23456789~!?@#$%^&*()-_+=;:.,<>[]{}\/';

  while (strlen($password) < $length) {
    $password .= $characters[mt_rand(0, strlen($characters) - 1)];
  }

  return $password;
}
