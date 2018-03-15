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
   *
   * @throws \Exception
   *   If an appropriate source of randomness cannot be found.
   */
  public function generate(int $length = 20): string {
    $password = '';

    // Allowable characters for the password. The number 0 and the letter 'O'
    // have been removed to avoid confusion between the two. The same is true
    // for 'I', 1, 'l' and '|'.
    $characters = '23456789~!?@#$%^&*()-_+=;:.,<>[]{}\/'
      . 'abcdefghijkmnopqrstuvwxyz'
      . 'ABCDEFGHJKLMNPQRSTUVWXYZ';
    $max_character_pos = strlen($characters) - 1;

    while ($length-- > 0) {
      $password .= $characters[random_int(0, $max_character_pos)];
    }

    return $password;
  }

}
