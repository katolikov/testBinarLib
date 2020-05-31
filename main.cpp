#include <iostream>
#include <fstream>
#include <chrono>
#include "msgpack.hpp"
#include "libbsoncpp.hpp"


int main(int argc, char *argv[]) {

    std::cout << "TEST READ FROM FILE\n";

    std::string msgpack = argv[1];
    std::string bson = argv[2];


    //Десерилизация из файла
    auto startFirstReadMsg = std::chrono::system_clock::now();

    std::stringstream buffer_from_file = MsgPack::Reader::read_from_file(msgpack);

    auto endFirstReadMsg = std::chrono::system_clock::now();

    //Серилизация в буффер
    auto startFirstWriteMsg = std::chrono::system_clock::now();

    std::stringstream buffer_se = MsgPack::Writer::write_to_buffer(buffer_from_file.str());

    auto endFirstWriteMsg = std::chrono::system_clock::now();

    //Десерилизация из буфера
    auto startSecondReadMsg = std::chrono::system_clock::now();

    MsgPack::Reader::read_from_buffer(buffer_se.str());

    auto endSecondReadMsg = std::chrono::system_clock::now();


    //Десерилизация из файла
    auto startFirstReadBson = std::chrono::system_clock::now();

    std::string deserialized_bson = LibBsonCpp::Reader::read_from_file_deserialization(bson);

    auto endFirstReadBson = std::chrono::system_clock::now();

    //std::cout << deserialized_bson << "\n";
    //Вывод полученного из файла bson

    //Серилизация в буффер
    auto startFirstWriteBson = std::chrono::system_clock::now();

    LibBsonCpp::Writer::serialization(deserialized_bson);

    auto endFirstWriteBson = std::chrono::system_clock::now();


    std::chrono::duration<double> firstTimeReadMsg = endFirstReadMsg - startFirstReadMsg;

    std::chrono::duration<double> secondTimeReadMsg = endSecondReadMsg - startSecondReadMsg;

    std::chrono::duration<double> firstTimeWriteMsg = endFirstWriteMsg - startFirstWriteMsg;

    std::chrono::duration<double> firstTimeReadBson = endFirstReadBson - startFirstReadBson;

    std::chrono::duration<double> firstTimeWriteBson = endFirstWriteBson - startFirstWriteBson;


    std::cout << "READ FROM FILE -> msgpack test: " << firstTimeReadMsg.count() << "\n";

    std::cout << "READ FROM FILE -> libbson test: " << firstTimeReadBson.count() << "\n";

    std::cout << "WRITE TO BUFFER -> msgpack test: " << firstTimeWriteMsg.count() << "\n";

    std::cout << "WRITE TO BUFFER -> libbson test: " << firstTimeWriteBson.count() << "\n";

    std::cout << "READ FROM BUFFER -> msgpack test: " << secondTimeReadMsg.count() << "\n";

    return 0;
}