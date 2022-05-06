#pragma once
#include <cstdint>
#include <cstring>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <kcapi.h>

inline size_t ceil_to(size_t x, size_t n) {
    size_t m = x % n;
    if (m == 0) {
        return x;
    }
    return x - m + n;
}

static const char* key = "0123456789abcdef0123456789abcdef";
static const char* iv = "0123456789abcdef";
static const uint8_t* key_ = (const uint8_t*) (key);
static const uint8_t* iv_ = (const uint8_t*) (iv);

inline ssize_t encrypt(char* data, size_t buf_size, size_t data_size) {
    uint8_t* data_ = (uint8_t*) (data);
    // Need 1 extra byte to store padding info
    size_t datalen_aligned = ceil_to(data_size + 1, 16);
    if (datalen_aligned > buf_size) {
        return -EINVAL;
    }
    uint8_t padding = datalen_aligned - data_size;
    data[datalen_aligned - 1] = padding;  // Last byte stores padding info
    auto res = kcapi_cipher_enc_aes_cbc(key_, 32, data_, datalen_aligned, iv_,
            data_, datalen_aligned);
    return res;
}

inline ssize_t decrypt(char* data, size_t size) {
    uint8_t* data_ = (uint8_t*) (data);
    auto res = kcapi_cipher_dec_aes_cbc(key_, 32, data_, size, iv_,
            data_, size);
    if (res < 0) { return res; }
    uint8_t padding = data_[size - 1];
    return size - padding;
}
