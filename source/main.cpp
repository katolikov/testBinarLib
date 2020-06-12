#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "../include/msgpack.hpp"
#include "../include/bson.hpp"
#include "../include/cbor.hpp"


auto BM_test_msg_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack_new.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    for (auto _ : state) {

        // This code gets timed
        msgpackcpp::reader::read_from_buffer(buffer_msg);
    }
}

auto BM_test_msg_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack_new.msgpack", std::ios::in);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    msgpack_file.close();

    for (auto _ : state) {

        // This code gets timed
        msgpackcpp::writer::write_to_buffer(
                msgpack::type::tuple<std::string>(buffer_msg.data()));
    }
}

auto BM_test_bson_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream bson_file("bson_new.bson", std::ios::in);

    std::string buffer_bson((std::istreambuf_iterator<char>(bson_file)),
                            std::istreambuf_iterator<char>());
    bson_file.close();

    std::vector<const uint8_t> uint8_t_v(buffer_bson.begin(), buffer_bson.end());

    for (auto _ : state) {

        // This code gets timed
        bsoncpp::reader::read_from_buffer(buffer_bson.size(), uint8_t_v);
    }
}

auto BM_test_cbor_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor_new.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    std::vector<unsigned char> un_string(buffer_cbor.begin(), buffer_cbor.end());

    for (auto _ : state) {
        // This code gets timed
        cborcpp::reader::read_from_buffer(buffer_cbor.size(), un_string);
    }
}

auto BM_test_cbor_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor_new.cbor", std::ios::in);

    std::string buffer_cbor((std::istreambuf_iterator<char>(cbor_file)),
                            std::istreambuf_iterator<char>());
    cbor_file.close();

    std::vector<unsigned char> un_string(buffer_cbor.begin(), buffer_cbor.end());

    auto item = cborcpp::reader::read_from_buffer(buffer_cbor.size(), un_string);

    auto size = cbor_string_length(item);

    for (auto _ : state) {
        // This code gets timed
        cborcpp::writer::write_to_buffer(item, size);
    }

    cbor_decref(&item);

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


