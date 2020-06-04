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

        ~Reader() {
            //bson_reader_destroy(reader);
        }

        static auto read_from_file_deserialization(const std::string &filename) {

            bson_error_t error;

            //bson_reader_t *reader;

            auto reader = bson_reader_new_from_file(filename.c_str(), &error);

            if (!reader) {
                std::cout << error.message;
            }
            return bson_reader_read(reader, nullptr);
        }
    };

    class Writer {

    public:
        static auto serialization(std::string json) {

            bson_error_t error;

            bson_new_from_json(reinterpret_cast<const uint8_t *>(json.data()), json.size(), &error);

            std::cout << error.message;
        }
    };
}
#endif //TESTBINARLIB_LIBBSONCPP_HPP
