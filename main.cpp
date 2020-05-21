#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]){

    std::fstream binaryFile;
    binaryFile.open(argv[1], std::ios::binary);

    auto startFirst = std::chrono::system_clock::now();

    //Some check function

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
