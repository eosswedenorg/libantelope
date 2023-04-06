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
#ifndef LIBANTELOPE_CODEC_H
#define LIBANTELOPE_CODEC_H

#include <libantelope/WIF.hpp>
#include <vector>

namespace libantelope { namespace internal {

/**
 * Public-key encoders
 */
typedef void (*pub_encoder_t)(const ec_pubkey_t& key, unsigned char *buf);

void pub_encoder_legacy(const ec_pubkey_t& key, unsigned char *buf);

void pub_encoder_k1(const ec_pubkey_t& key, unsigned char *buf);

/**
 * Public-key decoders
 */
typedef bool (*pub_decoder_t)(const std::vector<unsigned char>& buf, ec_pubkey_t& key);

bool pub_decoder_legacy(const std::vector<unsigned char>& buf, ec_pubkey_t& key);

bool pub_decoder_k1(const std::vector<unsigned char>& buf, ec_pubkey_t& key);

/**
 * Private-key encoders
 */
typedef size_t (*priv_encoder_t)(const ec_privkey_t&, unsigned char *);

size_t priv_encoder_legacy(const ec_privkey_t& priv, unsigned char *buf);

size_t priv_encoder_k1(const ec_privkey_t& priv, unsigned char *buf);

/**
 * Private-key decoders
 */
typedef bool (*priv_decoder_t)(const std::vector<unsigned char>&, ec_privkey_t&);

bool priv_decoder_legacy(const std::vector<unsigned char>& buf, ec_privkey_t& priv);

bool priv_decoder_k1(const std::vector<unsigned char>& buf, ec_privkey_t& priv);

/**
 * Signature encoders
 */
typedef void (*sig_encoder_t)(const ec_signature_t& sig, unsigned char *buf);

void sig_encoder_k1(const ec_signature_t& sig, unsigned char *buf);

/**
 * Signature decoders
 */
typedef bool (*sig_decoder_t)(const std::vector<unsigned char>& buf, ec_signature_t& sig);

bool sig_decoder_k1(const std::vector<unsigned char>& buf, ec_signature_t& sig);

}} // namespace libantelope::internal

#endif /* LIBANTELOPE_CODEC_H */
