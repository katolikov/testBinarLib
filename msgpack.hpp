//
// Created by Артем Католиков on 31.05.2020.
//

#ifndef TESTBINARLIB_MSGPACK_HPP
#define TESTBINARLIB_MSGPACK_HPP

#include <msgpack.hpp>
#include <sstream>

namespace MsgPack {

    class Reader {

    public:
        static auto read_from_file(const std::string &filename) {

            std::ifstream binaryFileIn(filename, std::ios::in | std::ios::binary);

            std::string buffer((std::istreambuf_iterator<char>(binaryFileIn)),
                               std::istreambuf_iterator<char>());

            binaryFileIn.close();

            return msgpack::unpack(buffer.data(), buffer.size());
        }

        static auto read_from_buffer(std::string buffer) {
            return msgpack::unpack(buffer.data(), buffer.size());
        }
    };

    class Writer {

    public:
        static auto write_to_buffer(const msgpack::type::tuple<std::string> &wrt) {

            std::stringstream buffer_new;

            msgpack::pack(buffer_new, wrt);

            return buffer_new;
        }
    };
}

#endif //TESTBINARLIB_MSGPACK_HPP
