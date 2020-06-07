//
// Created by Артем Католиков on 30.05.2020.
//

#ifndef TESTBINARLIB_LIBBSONCPP_HPP
#define TESTBINARLIB_LIBBSONCPP_HPP

#include <bson.h>
#include <iostream>
#include <memory>

namespace bsoncpp {

    class reader {

    public:

        static auto read_file(const std::string &file) {
            bson_error_t error;
            return bson_reader_new_from_file(file.c_str(), &error);
        }

        static auto read_from_buffer(bson_reader_t *read) {
            bson_reader_read(read, nullptr);
        }
    };

    class writer {

        static bson_t *doc;
    public:

        explicit writer(bson_t *d = nullptr) {
            doc = d;
        }

        ~writer() {
            delete (doc);
        }

        static auto write_to_buffer() {

            bson_error_t error;

            std::string buffer;

            auto writer = bson_writer_new(reinterpret_cast<uint8_t **>(buffer.data()),
                                          reinterpret_cast<size_t *>(buffer.size()),
                                          0, bson_realloc_ctx, nullptr);

            bson_writer_begin(writer, &doc);
            //decode переделать
            //return bson_new_from_json(reinterpret_cast<const uint8_t *>(json.data()),
            // json.size(), &error);

        }
    };
}
#endif //TESTBINARLIB_LIBBSONCPP_HPP
