#include <iostream>
#include <fstream>
#include "benchmark.hpp"
#include "msgpack.hpp"
#include "libbsoncpp.hpp"
#include "cbor.hpp"

auto deserialization_msg(const std::string &msgpack_file) {
    return MsgPack::Reader::read_from_file(msgpack_file);
}

auto serialization_msg(const msgpack::type::tuple<std::string> &reader) {
    return MsgPack::Writer::write_to_buffer(reader);
}

auto deserialization_bson(const std::string &bson) {
    return LibBsonCpp::Reader::read_from_file(bson);
}

auto serialization_bson(const std::string &str) {
    return LibBsonCpp::Writer::write_to_buffer(str);
}

/*auto dserialization_cbor(const std::string &cbor) {
    return Cbor::Reader::read_from_file(cbor);
}

auto serialization_cbor(const cbor_item_t *item) {
    Cbor::Writer::write_to_buffer(item);
}*/


int main(int argc, char *argv[]) {

    const std::string msgpack = argv[1];

    const std::string bson = argv[2];

    const std::string cbor = argv[3];


    //Десерилизация из файла

    COLLECT_METRIC("msgpack", "msgpack", "deserilization", 5) {
            benchmark::doNotOptimizeAway(deserialization_msg(msgpack));
        }

    auto pac = deserialization_msg(msgpack);

    msgpack::object_handle oh;

    std::stringstream buffer;

    while (pac.next(oh)) {
        msgpack::object msg = oh.get();
        buffer << msg << std::endl;
    }

    //Серилизация в буффер


    COLLECT_METRIC("msgpack", "msgpack", "serilization", 5) {
            benchmark::doNotOptimizeAway(serialization_msg(msgpack::type::tuple<std::string>(buffer.str())));
        }

    //auto buffer_out = sirilization_msg(msgpack::type::tuple<std::string>(buffer.str()));

    //std::cout << buffer_out.str();

    //Десерилизация из файла

    COLLECT_METRIC("bson", "libson", "deserilization", 5) {
            benchmark::doNotOptimizeAway(deserialization_bson(bson));
        }

    auto doc = deserialization_bson(bson);


    std::string str = bson_as_canonical_extended_json(doc, nullptr);

    //Серилизация в буффер

    COLLECT_METRIC("bson", "libbson", "serilization", 5) {
            benchmark::doNotOptimizeAway(serialization_bson(str));
        }

    //sirilization_bson(str);

    //auto item = desirilization_cbor(cbor);


    //sirilization_cbor(item);

    return 0;
}
