//
// Created by Артем Католиков on 04.06.2020.
//

#ifndef TESTBINARLIB_CBOR_HPP
#define TESTBINARLIB_CBOR_HPP

#include <cbor.h>
#include <iostream>
#include <memory>
#include <exception>


namespace cborcpp {

    class reader {

    public:

        static auto read_from_buffer(std::vector<uint8_t> &uint8_t_v) {

            struct cbor_load_result result;

            auto item = cbor_load(&uint8_t_v[0], uint8_t_v.size(), &result);

            if (result.error.code != CBOR_ERR_NONE) {
                throw std::invalid_argument("[ERROR] received bad cbor document");
            }
            return item;
        }
    };


    class writer {

    public:
        static auto write_to_buffer(std::shared_ptr<cbor_item_t *> item) {

            uint8_t *buffer;

            size_t buffer_size = cbor_serialize_alloc(*item, &buffer, &buffer_size);

            if (!(buffer_size)) {
                throw std::invalid_argument("[ERROR] received bad item or else");
            }
            return buffer;
        }
    };
}

#endif //TESTBINARLIB_CBOR_HPP
