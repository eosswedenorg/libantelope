/**
 * MIT License
 *
 * Copyright (c) 2019-2023 EOS Sw/eden
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
#ifndef LIBANTELOPE_HASH_RIPEMD160_H
#define LIBANTELOPE_HASH_RIPEMD160_H

#include <cstddef>
#include <libantelope/internal/hash.hpp>

namespace libantelope {

typedef unsigned char ripemd160_t[20];

typedef internal::ripemd160_state ripemd160_ctx_t;

/**
 * Initialize a ripmemd160_ctx_t structure
 */
int ripemd160_init(ripemd160_ctx_t* ctx);

/**
 * Update the RipeMD160 hash value with the contents in `data` up to `len` bytes.
 * This can be called repeatedly to hash chunks of data.
 */
int ripemd160_update(ripemd160_ctx_t* ctx, const void *data, std::size_t len);

/**
 * Places the RipeMD160 message digest in out variable.
 * The ctx's internal state is reset after this operation.
 */
int ripemd160_final(ripemd160_ctx_t* ctx, ripemd160_t* out);

/**
 * RipeMD160 hashing function.
 * Hashes the content in `data` up to `len` bytes. The result is stored in `out`.
 * Returns the same pointer as `out`.
 */
ripemd160_t* ripemd160(const unsigned char *data, std::size_t len, ripemd160_t* out);

} // namespace libantelope

#endif /* LIBANTELOPE_RIPEMD160_H */
