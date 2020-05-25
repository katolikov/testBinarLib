#include <iostream>
#include <fstream>
#include <chrono>
#include <msgpack.hpp>

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


    auto startFirstWrite = std::chrono::system_clock::now();

    //Some check function

    auto endFirstWrite = std::chrono::system_clock::now();

    auto startSecond = std::chrono::system_clock::now();

    //Some check function

    auto endSecond= std::chrono::system_clock::now();

    std::chrono::duration<double> firstTimeRead = endFirstRead-startFirstRead;

    //std::chrono::duration<double> firstTimeWrite = endFirstWrite-startFirstWrite;

    //std::chrono::duration<double> secondTime = endSecond-startSecond;

    binaryFileIn.close();
    //binaryFileOut.close();

    std::cout << "First check READ: " << firstTimeRead.count() << "\n";

    //std::cout << "First check WRITE: " << firstTimeWrite.count() << "\n";

    //std::cout << "Second check: " << secondTime.count() << "\n";
    return 0;
}
