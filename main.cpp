#include <iostream>
#include <fstream>
#include <benchmark/benchmark.h>
#include "msgpack.hpp"
#include "libbsoncpp.hpp"
#include "cbor.hpp"

auto desirilization_msg(const std::string &msgpack_file) {
    return MsgPack::Reader::read_from_file(msgpack_file);
}

auto sirilization_msg(const msgpack::object reader) {
    return MsgPack::Writer::write_to_buffer(reader);
}

auto desirilization_bson(const std::string &bson) {
    return LibBsonCpp::Reader::read_from_file_deserialization(bson);
}

auto sirilization_bson(const std::string &str) {
    LibBsonCpp::Writer::serialization(str);
}

auto desirilization_cbor(const std::string &cbor) {
    return Cbor::Reader::read_from_file(cbor);
}

auto sirilization_cbor(const cbor_item_t *item) {
    Cbor::Writer::write_to_buffer(item);
}


int main(int argc, char *argv[]) {

    const std::string msgpack = argv[1];

    const std::string bson = argv[2];

    const std::string cbor = argv[3];

    /*
    BENCHMARK(BM_test_desirilization_msg);
    BENCHMARK(BM_test_sirilization_msg);

    BENCHMARK(BM_test_desirilization_bson);
    BENCHMARK(BM_test_sirilization_bson);

    ::benchmark::Initialize(&argc, argv);
    if(::benchmark::ReportUnrecognizedArguments(argc, argv)){
        return 1;
    }
    ::benchmark::RunSpecifiedBenchmarks();
     */

    // const std::string cbor = argv[3];

    //Десерилизация из файла


    const auto reader_handel = desirilization_msg(msgpack);


    //Серилизация в буффер


    sirilization_msg(reader_handel.get());


    //Десерилизация из файла



    auto doc = desirilization_bson(bson);


    std::string str = bson_as_canonical_extended_json(doc, nullptr);

    //std::cout << deserialized_bson << "\n";
    //Вывод полученного из файла bson

    //Серилизация в буффер


    sirilization_bson(str);

    auto item = desirilization_cbor(cbor);


    sirilization_cbor(item);

    return 0;
}
