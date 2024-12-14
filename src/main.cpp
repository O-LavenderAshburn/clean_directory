#include <iostream>
#include <fstream>
#include <filesystem>
#include "runner.hpp"

int main(const int argc, char *argv[]) {
    const char* version = "1.1";
    if (argc <= 1) {
        std::cout << "Cleandir Removes all files in a specified directory not including folders" << std::endl;
        std::cout << "Usage: cleandir <path>"<< std::endl;
        std::cout << "try: cleandir --help for more options"<< std::endl;

        return 0;
    }


    // Check for help flags using std::string
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        std::cout << std::endl <<"Cleandir Removes all files in a specified directory not including folders"<< std::endl;

        std::cout << std::endl <<"Usage: cleandir <path>"<< std::endl;
        std::cout << std::endl;

        std::cout << "-v    --version" << std::endl << "    Current version" << std::endl;
        std::cout << std::endl;

        std::cout << "-f    --force" << std::endl << "    Forces delete with no prompt" << std::endl;
        std::cout << std::endl;

        std::cout << "-d    --destroy" << std::endl << "    Destroy directory and files" << std::endl;
        std::cout << std::endl;

        return 0;
    }

    // Print current version
    if (std::string(argv[1]) == "--version" || std::string(argv[1]) == "-v") {
        std::cout << "Version " <<version << std::endl;
        return 0;
    }

    std::vector<std::string> args(argv+1, argv + argc);


    Runner runner;

    runner.run(args);


    return 0;
}
