# Password Generator

A command-line utility for random password generation.

## Requirements

* PHP &ge; 7.1
* [Composer](https://getcomposer.org)

## Installation

```
composer global require --optimize-autoloader shiyan/passgen
```

Make sure that the `COMPOSER_HOME/vendor/bin` dir is in your `PATH` env var.
More info in the composer help: `composer global -h`

If you have the [CGR](https://github.com/consolidation/cgr) installed, than run
the following command instead of the one above:

```
cgr -o shiyan/passgen
```

## Usage

```
passgen [<length>]
```

Where `length` is an optional password length argument `[default: 20]`.
