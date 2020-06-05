//
// Created by Артем Католиков on 04.06.2020.
//
#ifndef TESTBINARLIB_CBOR_HPP
#define TESTBINARLIB_CBOR_HPP

#include <cbor.h>
#include <iostream>
#include <memory>

namespace Cbor {

    class Reader {

    public:
        static auto read_from_file(const std::string &filename) {

            std::ifstream binaryFileIn(filename, std::ios::in | std::ios::binary);

            std::string buffer((std::istreambuf_iterator<char>(binaryFileIn)),
                               std::istreambuf_iterator<char>());

            binaryFileIn.close();

            struct cbor_load_result result{};

            return cbor_load(reinterpret_cast<unsigned char *>(buffer.data()),
                             buffer.size(), &result);
        }
    };

    class Writer {

    public:
        static auto write_to_buffer(const cbor_item_t *item) {
            std::string buffer = nullptr;
            cbor_serialize(item, reinterpret_cast<unsigned char *>(buffer.data()),
                           buffer.size());
            return buffer;
        }
    };
}

#endif //TESTBINARLIB_CBOR_HPP
