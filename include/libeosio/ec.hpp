/**
 * MIT License
 *
 * Copyright (c) 2019-2021 EOS Sw/eden
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef LIBEOSIO_EC_H
#define LIBEOSIO_EC_H

#include <libeosio/hash.hpp>
#include <iostream>
#include <array>

namespace libeosio {

/**
 * Elliptic curve private key size (in bytes)
 */
#define EC_PRIVKEY_SIZE 32

/**
 * Elliptic curve public key size (in bytes)
 *
 * Compressed format: z||x, where byte z specifies which (of the 2) solutions
 * of the quadratic equation y is. Each cordinate is 32 bytes.
 */
#define EC_PUBKEY_SIZE (32 + 1)

/**
 * Elliptic curve priv/pub key datastructures.
 */
typedef std::array<unsigned char, EC_PRIVKEY_SIZE> ec_privkey_t;
typedef std::array<unsigned char, EC_PUBKEY_SIZE> ec_pubkey_t;

/**
 * Elliptic curve keypair (public + private)
 */
struct ec_keypair {
	ec_privkey_t secret;
	ec_pubkey_t pub;
};

/**
 * Initialize the ec library.
 */
int ec_init();

/**
 * Generates an new random private key using the secp256k1 curve.
 */
int ec_generate_privkey(ec_privkey_t *priv);

/**
 * Get the public key from an private key.
 */
int ec_get_publickey(const ec_privkey_t *priv, ec_pubkey_t* pub);

/**
 * Generates a keypair using the secp256k1 curve.
 * public key is in compressed format.
 */
int ec_generate_key(struct ec_keypair *pair);

/**
 * Shutdown the ec library.
 */
void ec_shutdown();

} // namespace libeosio


// Stream operators

std::ostream& operator<<(std::ostream& os, const libeosio::ec_privkey_t& pk);

std::ostream& operator<<(std::ostream& os, const libeosio::ec_pubkey_t& pk);

#endif /* LIBEOSIO_EC_H */
