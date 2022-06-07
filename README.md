# BigDecimal

*An implemenation of `uint256` in C++*


Project   | BigDecimal
:---      | ---:
Author    | [M. Massenzio](https://github.com/massenz)
Release   | 0.1.0
Updated   | 2022-06-07

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

# Overview

A simple implementation of a 256-bit integer in C++.

# Install & Build

## Conan packages

This project use [Conan](https://conan.io) to build dependencies; please see
[this post](https://medium.com/swlh/converting-a-c-project-to-cmake-conan-61ba9a998cb4)
for more details on how to use inside a CMake project.

The `build` script will automatically re-build dependencies.


### Build & Test

Prior to building the project, you must define `$INSTALL_DIR` in your environment: libraries, include files and executables will be installed, respectively, in the `lib`, `include` and `bin` subdirectories.

To build the project:

```shell
$ export INSTALL_DIR=/some/path
$ export LD_LIBRARY_PATH=.:build/lib:$INSTALL_DIR/lib:$LD_LIBRARY_PATH
$ ./bin/build && ./bin/test
```

To install the generated binaries (`.so` or `.dylib` shared libraries)
and headers so that other projects can find them:

    $ cd build && make install

See the scripts in the [common utils project](https://github.com/massenz/common-utils) folder for more options.

# Documentation

All the classes are documented using [Doxygen](http://www.doxygen.nl/), just run:

    $ doxygen

from the main project directory and all docs will be generated in `docs/apidocs/html`.

## Simple usage

`TODO`
