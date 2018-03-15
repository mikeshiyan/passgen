<?php

namespace Shiyan\Passgen;

/**
 * Password generating Symfony Console application.
 */
class Passgen {

  /**
   * Generates a password.
   *
   * @command passgen
   *
   * @param int $length
   *   Password length.
   *
   * @return string
   *   Generated password.
   */
  public function generate(int $length = 20): string {
    $password = '';

    // Allowable characters for the password. The number 0 and the letter 'O'
    // have been removed to avoid confusion between the two. The same is true
    // for 'I', 1, 'l' and '|'.
    $characters = 'abcdefghijkmnopqrstuvwxyz';
    $characters .= 'ABCDEFGHJKLMNPQRSTUVWXYZ';
    $characters .= '23456789~!?@#$%^&*()-_+=;:.,<>[]{}\/';

    while (strlen($password) < $length) {
      $password .= $characters[mt_rand(0, strlen($characters) - 1)];
    }

    return $password;
  }

}
