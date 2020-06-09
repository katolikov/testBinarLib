//
// Created by Артем Католиков on 30.05.2020.
//

#ifndef TESTBINARLIB_BSON_HPP
#define TESTBINARLIB_BSON_HPP

#include <bson.h>
#include <iostream>
#include <memory>

namespace bsoncpp {

    class reader {

    public:

        static auto read_from_buffer(const std::string &buffer) {
            bson_validate(bson_reader_read(bson_reader_new_from_data(reinterpret_cast<const uint8_t *>(buffer.c_str()),
                                                                     buffer.size()), nullptr), BSON_VALIDATE_NONE,
                          nullptr);
        }
    };
}
#endif //TESTBINARLIB_BSON_HPP
