//
// Created by Артем Католиков on 31.05.2020.
//

#ifndef TESTBINARLIB_MSGPACK_HPP
#define TESTBINARLIB_MSGPACK_HPP

#include <msgpack.hpp>
#include <sstream>

namespace msgpackcpp {

    class reader {

    public:
        static auto read_from_buffer(std::string buffer) {

            return msgpack::unpack(buffer.data(), buffer.size());
        }
    };

    class writer {

    public:
        static auto write_to_buffer(const msgpack::type::tuple<std::string> &wrt) {

            std::stringstream buffer_out;

            msgpack::pack(buffer_out, wrt);

            return buffer_out;
        }
    };
}

#endif //TESTBINARLIB_MSGPACK_HPP
