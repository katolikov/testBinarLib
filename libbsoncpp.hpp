//
// Created by Артем Католиков on 30.05.2020.
//

#ifndef TESTBINARLIB_LIBBSONCPP_HPP
#define TESTBINARLIB_LIBBSONCPP_HPP

#include <bson.h>
#include <iostream>
#include <memory>

namespace LibBsonCpp {

    class Reader {

    public:

        //static bson_reader_t *reader;

        Reader() = default;

        ~Reader() = default;

        static auto read_from_file(const std::string &filename) {

            bson_error_t error;

            return bson_reader_read(bson_reader_new_from_file(filename.c_str(),
                                                              &error), nullptr);
        }
    };

    class Writer {

    public:
        static auto write_to_buffer(std::string json) {

            bson_error_t error;
            //decode переделать
            return bson_new_from_json(reinterpret_cast<const uint8_t *>(json.data()),
                                      json.size(), &error);

        }
    };
}
#endif //TESTBINARLIB_LIBBSONCPP_HPP
