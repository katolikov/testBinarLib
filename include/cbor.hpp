//
// Created by Артем Католиков on 04.06.2020.
//

#ifndef TESTBINARLIB_CBOR_HPP
#define TESTBINARLIB_CBOR_HPP

#include <cbor.h>
#include <iostream>
#include <memory>
#include <cassert>

namespace cborcpp {

    class reader {

    public:

        static auto read_from_buffer(size_t length, std::vector<unsigned char> &un_string) {

            struct cbor_load_result result;

            return cbor_load(&un_string[0], length, &result);
        }
    };


    class writer {

    public:

        static auto write_to_buffer(cbor_item_t *item, size_t size) {

            unsigned char buffer[size];

            return cbor_serialize(item, buffer, size);
        }
    };
}

#endif //TESTBINARLIB_CBOR_HPP
