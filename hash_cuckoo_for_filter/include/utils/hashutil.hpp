#ifndef CUCKOO_FILTER_HASHUTIL_H_
#define CUCKOO_FILTER_HASHUTIL_H_

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string>
#include <array>

#include <openssl/evp.h>
#include <random>

namespace cuckoofilter {

    class HashUtil {
    public:

        static uint32_t BobHash(const void *buf, size_t length, uint32_t seed = 0);

        static uint32_t BobHash(const std::string &s, uint32_t seed = 0);


        static void BobHash(const void *buf, size_t length, uint32_t *idx1,
                            uint32_t *idx2);

        static void BobHash(const std::string &s, uint32_t *idx1, uint32_t *idx2);


        static uint32_t MurmurHash(const void *buf, size_t length, uint32_t seed = 0);

        static uint32_t MurmurHash(const std::string &s, uint32_t seed = 0);


        static uint32_t SuperFastHash(const void *buf, size_t len);

        static uint32_t SuperFastHash(const std::string &s);


        static uint32_t NullHash(const void *buf, size_t length, uint32_t shiftbytes);


        static std::string MD5Hash(const char *inbuf, size_t in_length);

        static std::string SHA1Hash(const char *inbuf, size_t in_length);

    private:
        HashUtil();
    };


    class TwoIndependentMultiplyShift {
        unsigned __int128 multiply_, add_;

    public:
        TwoIndependentMultiplyShift() {
            ::std::random_device random;
            for (auto v: {&multiply_, &add_}) {
                *v = random();
                for (int i = 1; i <= 4; ++i) {
                    *v = *v << 32;
                    *v |= random();
                }
            }
        }

        uint64_t operator()(uint64_t key) const {
            return (add_ + multiply_ * static_cast<decltype(multiply_)>(key)) >> 64;
        }
    };


    class SimpleTabulation {
        uint64_t tables_[sizeof(uint64_t)][1 << CHAR_BIT];

    public:
        SimpleTabulation() {
            ::std::random_device random;
            for (unsigned i = 0; i < sizeof(uint64_t); ++i) {
                for (int j = 0; j < (1 << CHAR_BIT); ++j) {
                    tables_[i][j] = random() | ((static_cast<uint64_t>(random())) << 32);
                }
            }
        }

        uint64_t operator()(uint64_t key) const {
            uint64_t result = 0;
            for (unsigned i = 0; i < sizeof(key); ++i) {
                result ^= tables_[i][reinterpret_cast<uint8_t *>(&key)[i]];
            }
            return result;
        }
    };


    class XXHash64 {
    public:
        XXHash64() = default;

        uint64_t operator()(uint64_t key) const;

        uint64_t operator()(const char *key) const;

        uint64_t operator()(const std::array<char, 16> &key) const;
    };


}

#include "hashutil_impl.hpp"

#endif
