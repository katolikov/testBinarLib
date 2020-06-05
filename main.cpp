#include <iostream>
#include <fstream>
#include "benchmark.hpp"
#include "msgpack.hpp"
#include "libbsoncpp.hpp"
#include "cbor.hpp"

auto desirilization_msg(const std::string &msgpack_file) {
    return MsgPack::Reader::read_from_file(msgpack_file);
}

auto sirilization_msg(const msgpack::type::tuple<std::string> reader) {
    return MsgPack::Writer::write_to_buffer(reader);
}

auto desirilization_bson(const std::string &bson) {
    return LibBsonCpp::Reader::read_from_file_deserialization(bson);
}

auto sirilization_bson(const std::string &str) {
    return LibBsonCpp::Writer::serialization(str);
}

/*auto desirilization_cbor(const std::string &cbor) {
    return Cbor::Reader::read_from_file(cbor);
}

auto sirilization_cbor(const cbor_item_t *item) {
    Cbor::Writer::write_to_buffer(item);
}*/


int main(int argc, char *argv[]) {

    const std::string msgpack = argv[1];

    const std::string bson = argv[2];

    const std::string cbor = argv[3];


    //Десерилизация из файла

    COLLECT_METRIC("msgpack", "msgpack", "deserilization", 5000) {
            benchmark::doNotOptimizeAway(desirilization_msg(msgpack));
        }

    auto reader_handel = desirilization_msg(msgpack);
    auto reader = reader_handel.get();

    std::stringstream buffer;

    buffer << reader;

    //Серилизация в буффер


    COLLECT_METRIC("msgpack", "msgpack", "serilization", 5000) {
            benchmark::doNotOptimizeAway(sirilization_msg(msgpack::type::tuple<std::string>(buffer.str())));
        }

    auto buffer_out = sirilization_msg(msgpack::type::tuple<std::string>(buffer.str()));

    //Десерилизация из файла

    COLLECT_METRIC("bson", "libson", "deserilization", 5000) {
            benchmark::doNotOptimizeAway(desirilization_bson(bson));
        }

    auto doc = desirilization_bson(bson);


    std::string str = bson_as_canonical_extended_json(doc, nullptr);

    //Серилизация в буффер

    COLLECT_METRIC("bson", "libbson", "serilization", 5000) {
            benchmark::doNotOptimizeAway(sirilization_bson(str));
        }

    //sirilization_bson(str);

    //auto item = desirilization_cbor(cbor);


    //sirilization_cbor(item);

    return 0;
}
