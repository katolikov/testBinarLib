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

        Reader() = default;

        ~Reader() = default;

    public:
        static auto read_from_file_deserialization(const std::string &filename) {

            bson_error_t error;

            auto reader = bson_reader_new_from_file(filename.c_str(), &error);

            if (!reader) {
                std::cout << error.message;
            }

            auto doc = bson_reader_read(reader, nullptr);

            std::string str = bson_as_canonical_extended_json(doc, nullptr);

            return str;
        }
    };

    class Writer {

    private:
        Writer() = default;

        ~Writer() = default;

    public:
        static auto serialization(std::string json) {

            bson_error_t error;

            auto bson = bson_new_from_json(reinterpret_cast<const uint8_t *>(json.data()), json.size(), &error);

            if (!bson) {
                std::cout << error.message;
            }
            bson_destroy(bson);
        }
    };
}
#endif //TESTBINARLIB_LIBBSONCPP_HPP
