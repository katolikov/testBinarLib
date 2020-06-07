#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "msgpack.hpp"
#include "libbsoncpp.hpp"
#include "cbor.hpp"

auto deserialization_msg(const std::string &msgpack_file) {
    return msgpackcpp::reader::read_from_buffer(msgpack_file);
}

auto serialization_msg(const msgpack::type::tuple<std::string> &reader) {
    return msgpackcpp::writer::write_to_buffer(reader);
}

auto deserialization_bson(bson_reader_t *reader) {
    return bsoncpp::reader::read_from_buffer(reader);
}

/*auto serialization_bson(const std::string &str) {
    return LibBsonCpp::Writer::write_to_buffer(str);
}
*/

auto deserialization_cbor(const std::string &cbor) {
    return cborcpp::reader::read_from_buffer(cbor);
}

auto serialization_cbor(const cbor_item_t *item) {
    cborcpp::writer::write_to_buffer(item);
}

auto BM_test_msg_deser(benchmark::State &state) {

    std::ifstream msgpack_file("./msgpack.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    while (state.KeepRunning()) {
        deserialization_msg(buffer_msg);
    }
}

auto BM_test_msg_ser(benchmark::State &state) {

    std::ifstream msgpack_file("./msgpack.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    while (state.KeepRunning()) {
        serialization_msg(msgpack::type::tuple<std::string>(buffer_msg.data()));
    }
}

auto BM_test_bson_deser(benchmark::State &state) {

    auto reader = bsoncpp::reader::read_file("./bson.bson");

    while (state.KeepRunning()) {
        deserialization_bson(reader);
    }
}

/*auto BM_test_bson_ser(benchmark::State& state) {

    while (state.KeepRunning()){
        deserialization_bson(reader);
    }
}*/

auto BM_test_cbor_deser(benchmark::State &state) {

    std::ifstream cbor_file("./cbor.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    while (state.KeepRunning()) {
        deserialization_cbor(buffer_cbor);
    }
}

auto BM_test_cbor_ser(benchmark::State &state) {

    std::ifstream cbor_file("./cbor.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    auto item = deserialization_cbor(buffer_cbor);

    while (state.KeepRunning()) {
        serialization_cbor(item);
    }
}


BENCHMARK(BM_test_msg_deser);
BENCHMARK(BM_test_msg_ser);
BENCHMARK(BM_test_bson_deser);
BENCHMARK(BM_test_cbor_deser);
BENCHMARK(BM_test_cbor_ser);

BENCHMARK_MAIN();


