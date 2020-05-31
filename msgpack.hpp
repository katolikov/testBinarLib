//
// Created by Артем Католиков on 31.05.2020.
//

#ifndef TESTBINARLIB_MSGPACK_HPP
#define TESTBINARLIB_MSGPACK_HPP

#include <msgpack.hpp>
#include <sstream>

namespace MsgPack {

    class Reader {

        Reader() = default;

        ~Reader() = default;

    public:
        static auto read_from_file(const std::string &filename) {

            std::ifstream binaryFileIn(filename, std::ios::in | std::ios::binary);

            std::string buffer((std::istreambuf_iterator<char>(binaryFileIn)), std::istreambuf_iterator<char>());

            if (!binaryFileIn) {
                std::cerr << "Cannot open file!\n";
            }

            binaryFileIn.close();

            msgpack::object_handle oh = msgpack::unpack(buffer.data(), buffer.size());

            msgpack::object deserialized = oh.get();

            std::stringstream buffer_new;
            buffer_new << deserialized;

            return buffer_new;

        }

        static auto read_from_buffer(std::string buffer) {
            return msgpack::unpack(buffer.data(), buffer.size());
        }
    };

    class Writer {

    public:
        static auto write_to_buffer(std::string buffer) {

            msgpack::type::tuple<std::string> buffer_data(buffer.data());
            std::stringstream buffer_new;
            msgpack::pack(buffer_new, buffer_data);

            buffer_new.seekg(0);

            return buffer_new;
        }
    };
}

#endif //TESTBINARLIB_MSGPACK_HPP
