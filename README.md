![](https://github.com/eosswedenorg/libantelope/workflows/CI/badge.svg)
[![GitHub release](https://img.shields.io/github/v/release/eosswedenorg/libantelope?include_prereleases)](https://github.com/eosswedenorg/libantelope/releases/latest)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# libantelope

libantelope is an independent C++ library designed for Antelope IO (formerly known as libeosio). Please note that this repository is not affiliated with the official Antelope code.

## Compiling the library

To compile this project, you will need the following:

- `openssl` development files (version 1.1 or later)
- `cmake 3.15` or later

### Elliptic curve backend

The library offers two different backend implementations for the elliptic curve functionality:

- `libsecp256k1`
- `OpenSSL`: Although the default is to use `libsecp256k1` for optimization, you still need to link to OpenSSL as other parts of the codebase rely on it.

To switch the implementation, modify the `EC_LIB` variable in the cmake.

### CMake

You can install `cmake` by referring to the [official guide](https://cmake.org/install).

### Linux

**NOTE:** Only Ubuntu versions `20.04` and `22.04` are officially supported.

While the project should compile fine on most versions/distros, it is only tested and distributed for Ubuntu `20.04` and `22.04` by [Sw/eden](https://www.eossweden.org).

#### Dependencies

**Ubuntu (or other Debian-based distros)**

To install the necessary dependencies (compiler, `openssl`, and `cmake`), use the following `apt` command:

```sh
apt-get install gcc g++ cmake libssl-dev
```

If you require a newer version of `cmake`, you can refer to the [official CMake APT repository](https://apt.kitware.com/).

**Other**

For other distros, please consult your package manager's manual to install `openssl`, `g++`, and `cmake`. If you need a newer version of `cmake`, you can follow the [official installation guide](https://cmake.org/install).

### MacOS

#### Dependencies

Ensure that you have a compiler installed. This project is known to build with `Xcode 11.0`, but other versions should work as well.

To install `openssl` and `cmake`, you can use the following `brew` command:

```sh
brew install openssl cmake
```

If you require a newer version of `cmake`, refer to the [official installation guide](https://cmake.org/install).

#### Build

```sh
mkdir build && cd build
cmake .. && make
```

**MacOS:** If your `openssl` installation is not located at `/usr/local/opt/openssl@1.1`, you may need to pass the argument `-D OPENSSL_ROOT_DIR=/path/to/openssl` to `cmake` and specify the correct path.

### Windows

#### Dependencies

First, ensure that you have a compiler installed.

It is recommended to use [Build Tools for Visual Studio 2019](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16) and select C++ during installation.

By default, `cmake` will utilize the bundled OpenSSL package located at `vendor/openssl-1.1.1e-win-static.zip`. If you prefer to use a different version of OpenSSL, set the `OPENSSL_ROOT_DIR` to the directory where OpenSSL is located on your system:

```sh
cmake -D OPENSSL_ROOT_DIR=C:/path/to/openssl -B build
```

**NOTE:** `cmake` uses forward slashes `/` for paths, even on Windows, so ensure that you use them when setting

 `OPENSSL_ROOT_DIR`.

#### Build

Run `cmake`:

```sh
cmake -B build
cmake --build build --config Release
```

## Security Notice

The library performs elliptic curve cryptographic operations using either the `OpenSSL` or `libsecp256k1` libraries. The `libantelope` library ensures that sensitive cryptographic information is only stored in computer memory and not exposed to external sources. You are encouraged to inspect the source code and compile it yourself for verification purposes.

However, please use this library at your own risk. While both OpenSSL and libsecp256k1 are widely used and considered safe, we cannot guarantee the cryptographic security of the keys as it depends on the elliptic curve implementation.

Please refer to the `LICENSE` file for more information.

## Author

Henrik Hautakoski - [henrik@eossweden.org](mailto:henrik@eossweden.org)
