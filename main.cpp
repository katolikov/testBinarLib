#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]){

    size_t size = 1000000;
    char buffer[size];

    std::cout << "Test READ FROM FILE: \nFILE SIZE: 10GB\n";

    std::ifstream binaryFile (argv[1], std::ios::in | std::ios::binary);

    if(!binaryFile){
        std::cerr << "Cannot open file!\n";
        return 1;
    }

    auto startFirst = std::chrono::system_clock::now();

    binaryFile.read(buffer, size); //check first

    auto endFirst = std::chrono::system_clock::now();

    auto startSecond = std::chrono::system_clock::now();

    //Some check function

    auto endSecond= std::chrono::system_clock::now();

    std::chrono::duration<double> firstTime = endFirst-startFirst;
    std::chrono::duration<double> secondTime = endSecond-startSecond;

    binaryFile.close();

    std::cout << "First check: " << firstTime.count() << "\n";

    std::cout << "Second check: " << secondTime.count() << "\n";

	return 0;
}
