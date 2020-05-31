//
// Created by Артем Католиков on 30.05.2020.
//

#ifndef TESTBINARLIB_LIBBSONCPP_HPP
#define TESTBINARLIB_LIBBSONCPP_HPP

#include <bson.h>
#include <iostream>

namespace libbsoncpp {

    class reader {

    public:
        static auto read_from_file(const char *filename) {
            bson_error_t error;
            auto reader = bson_reader_new_from_file(filename, &error);

            if (!reader) {
                std::cout << error.message;
            }

            return reader;

        }
    };
}
#endif //TESTBINARLIB_LIBBSONCPP_HPP
