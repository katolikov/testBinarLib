#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "../include/msgpack.hpp"
#include "../include/bson.hpp"
#include "../include/cbor.hpp"

auto deserialization_msg(const std::string &msgpack_file) {
    return msgpackcpp::reader::read_from_buffer(msgpack_file);
}

auto serialization_msg(const msgpack::type::tuple<std::string> &reader) {
    return msgpackcpp::writer::write_to_buffer(reader);
}

auto deserialization_bson(const std::string &buffer) {
    return bsoncpp::reader::read_from_buffer(buffer);
}

auto deserialization_cbor(const std::string &cbor) {
    return cborcpp::reader::read_from_buffer(cbor);
}

auto serialization_cbor(const cbor_item_t *item) {
    cborcpp::writer::write_to_buffer(item);
}

auto BM_test_msg_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    for (auto _ : state) {

        // This code gets timed
        deserialization_msg(buffer_msg);
    }
}

auto BM_test_msg_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    for (auto _ : state) {

        // This code gets timed
        serialization_msg(msgpack::type::tuple<std::string>(buffer_msg.data()));
    }
}

auto BM_test_bson_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream bson_file("bson.bson", std::ios::in);

    std::string buffer_bson((std::istreambuf_iterator<char>(bson_file)),
                            std::istreambuf_iterator<char>());
    bson_file.close();

    for (auto _ : state) {
        // This code gets timed
        deserialization_bson(buffer_bson);
    }
}

auto BM_test_cbor_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    for (auto _ : state) {
        // This code gets timed
        deserialization_cbor(buffer_cbor);
    }
}

auto BM_test_cbor_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    auto item = deserialization_cbor(buffer_cbor);

    for (auto _ : state) {
        // This code gets timed
        serialization_cbor(item);
    }
}

// Register the function as a benchmark

// MSGPACK
BENCHMARK(BM_test_msg_deser);
BENCHMARK(BM_test_msg_ser);

// BSON
BENCHMARK(BM_test_bson_deser);

// CBOR
BENCHMARK(BM_test_cbor_deser);
BENCHMARK(BM_test_cbor_ser);

// Run the benchmark
BENCHMARK_MAIN();


