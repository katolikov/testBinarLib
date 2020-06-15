//
// Created by Артем Католиков on 30.05.2020.
//

#ifndef TESTBINARLIB_BSON_HPP
#define TESTBINARLIB_BSON_HPP

#include <bson.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <exception>

namespace bsoncpp {

    class reader {

    public:

        static auto read_from_buffer(std::vector<uint8_t> &uint8_t_v) {

            bool eof = false;

            auto reader = bson_reader_new_from_data(&uint8_t_v[0],
                                                    uint8_t_v.size());
            if (!(reader)) {
                throw std::invalid_argument("[ERROR] received bad bson document");
            }

            auto doc = bson_reader_read(reader, &eof);

            if (!(doc)) {
                throw std::invalid_argument("[ERROR] received bad bson reader");
            }

            auto item = bson_validate(doc, BSON_VALIDATE_NONE, nullptr);

            if (!(item)) {
                throw std::invalid_argument("[ERROR] error in the byte offset");
            }

            return reader;

        }
    };
}
#endif //TESTBINARLIB_BSON_HPP
