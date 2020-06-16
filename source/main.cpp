#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "../include/msgpack.hpp"
#include "../include/bson.hpp"
#include "../include/cbor.hpp"


auto BM_test_msg_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack_new_100.msgpack", std::ios::in | std::ios::binary);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(msgpackcpp::reader::read_from_buffer(buffer_msg));
    }
}

auto BM_test_msg_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream msgpack_file("msgpack_new_100.msgpack", std::ios::in | std::ios::binary);

    std::string buffer_msg((std::istreambuf_iterator<char>(msgpack_file)),
                           std::istreambuf_iterator<char>());
    auto oh = msgpackcpp::reader::read_from_buffer(buffer_msg);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(msgpackcpp::writer::write_to_buffer(
                msgpack::type::tuple<msgpack::object>(oh.get())));
    }
}

auto BM_test_bson_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream bson_file("bson_new_100.bson", std::ios::in | std::ios::binary);

    std::vector<uint8_t> uint8_t_v((std::istreambuf_iterator<char>(bson_file)),
                                   std::istreambuf_iterator<char>());
    bson_reader_t *reader;

    try {
        for (auto _ : state) {
            // This code gets timed
            benchmark::DoNotOptimize(reader = bsoncpp::reader::read_from_buffer(uint8_t_v));

            state.PauseTiming();
            bson_reader_destroy(reader);
            state.ResumeTiming();
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        exit(1);
    }
}

auto BM_test_cbor_deser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor_new_100.cbor", std::ios::in | std::ios::binary);

    std::vector<uint8_t> uint8_t_v((std::istreambuf_iterator<char>(cbor_file)),
                                   std::istreambuf_iterator<char>());
    cbor_item_t *item;

    try {
        for (auto _ : state) {
            // This code gets timed
            benchmark::DoNotOptimize(item = cborcpp::reader::read_from_buffer(uint8_t_v));

            state.PauseTiming();
            cbor_decref(&item);
            state.ResumeTiming();
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        exit(1);
    }
}

auto BM_test_cbor_ser(benchmark::State &state) {

    // Perform setup

    std::ifstream cbor_file("cbor_new_100.cbor", std::ios::in | std::ios::binary);

    std::vector<uint8_t> uint8_t_v((std::istreambuf_iterator<char>(cbor_file)),
                                   std::istreambuf_iterator<char>());
    uint8_t *buffer;

    try {
        auto item = std::make_shared<cbor_item_t *>(cborcpp::reader::read_from_buffer(uint8_t_v));

        for (auto _ : state) {
            // This code gets timed
            benchmark::DoNotOptimize(buffer = cborcpp::writer::write_to_buffer(item));

            state.PauseTiming();
            free(buffer);
            state.ResumeTiming();
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        exit(1);
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


