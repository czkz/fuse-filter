#pragma once
#include <cstdint>
#include <sys/types.h>
#include <kcapi.h>

inline size_t ceil_to(size_t x, size_t n) {
    size_t m = x % n;
    if (m == 0) {
        return x;
    }
    return x - m + n;
}

inline ssize_t encrypt(char* out, size_t out_size, const char* data, size_t data_size) {
    (void) out_size;
    for (size_t i = 0; i < data_size; i++) {
        out[i] = data[i] ^ -1;
    }
    return data_size;
}

inline ssize_t decrypt(char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        data[i] ^= -1;
    }
    return size;
}
