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
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <libantelope/hash.hpp>

namespace libantelope {

int sha256_init(struct sha256_ctx* ctx) {
	return SHA256_Init((SHA256_CTX*)ctx);
}

int sha256_update(sha256_ctx_t* ctx, const void *data, std::size_t len) {
	return SHA256_Update((SHA256_CTX*)ctx, data, len);
}

int sha256_final(sha256_ctx_t* ctx, sha256_t* out) {
	return SHA256_Final((unsigned char*) out, (SHA256_CTX*)ctx);
}

sha256_t* sha256(const unsigned char *data, std::size_t len, sha256_t* out) {
	return (sha256_t *) SHA256(data, len, (unsigned char*) out);
}

sha256_t* sha256d(const unsigned char *data, std::size_t len, sha256_t* out) {
	SHA256(data, len, (unsigned char*) out);
	return (sha256_t *) SHA256((unsigned char*) out, 32, (unsigned char*) out);
}

int ripemd160_init(ripemd160_ctx_t* ctx) {
	return RIPEMD160_Init((RIPEMD160_CTX*)ctx);
}

int ripemd160_update(ripemd160_ctx_t* ctx, const void *data, std::size_t len) {
	return RIPEMD160_Update((RIPEMD160_CTX*)ctx, data, len);
}

int ripemd160_final(ripemd160_ctx_t* ctx, ripemd160_t* out) {
	return RIPEMD160_Final((unsigned char*) out, (RIPEMD160_CTX*)ctx);
}

ripemd160_t* ripemd160(const unsigned char *data, std::size_t len, ripemd160_t* out) {
	return (ripemd160_t *) RIPEMD160(data, len, (unsigned char*) out);
}

} // namespace libantelope
