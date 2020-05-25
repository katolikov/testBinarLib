#include <iostream>
#include <fstream>
#include <chrono>
#include <msgpack.hpp>
#include <cbor.h>

int main(int argc, char* argv[]){

    std::cout << "Test READ FROM FILE: \nFILE SIZE: 1GB\n";

    std::ifstream binaryFileIn (argv[1], std::ios::in | std::ios::binary);

    std::string buffer((std::istreambuf_iterator<char>(binaryFileIn)), std::istreambuf_iterator<char>());

    //std::ofstream binaryFileOut (argv[1], std::ios::in | std::ios::binary);

    if(!binaryFileIn){
        std::cerr << "Cannot open file!\n";
        return 1;
    }

    msgpack::unpacked upd;

    std::size_t offset = 0;

    auto startFirstRead = std::chrono::system_clock::now();

    msgpack::unpack(upd, buffer.data(), buffer.size(), offset);

    auto endFirstRead = std::chrono::system_clock::now();

    //struct cbor_load_result result;

    auto startSecondRead = std::chrono::system_clock::now();

    //Some check function

    auto endSecondRead = std::chrono::system_clock::now();


    std::chrono::duration<double> firstTimeRead = endFirstRead-startFirstRead;

    std::chrono::duration<double> SecondTimeRead = endSecondRead - startSecondRead;

    binaryFileIn.close();

    std::cout << "READ -> msgpack test: " << firstTimeRead.count() << "\n";

    std::cout << "READ -> libcbor test: " << SecondTimeRead.count() << "\n";

    return 0;
}
