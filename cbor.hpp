//
// Created by Артем Католиков on 04.06.2020.
//

#ifndef TESTBINARLIB_CBOR_HPP
#define TESTBINARLIB_CBOR_HPP

#include <cbor.h>
#include <iostream>
#include <memory>

namespace cborcpp {

    class reader {

    public:
        static auto read_from_buffer(const std::string &buffer) {

            struct cbor_load_result result{};

            return cbor_load(reinterpret_cast<const unsigned char *>(buffer.data()), buffer.size(), &result);
        }
    };

    class writer {

    public:
        static auto write_to_buffer(const cbor_item_t *item) {

            std::string buffer;

            cbor_serialize(item, reinterpret_cast<unsigned char *>(buffer.data()),
                           buffer.size());
            return buffer;
        }
    };
}

#endif //TESTBINARLIB_CBOR_HPP
