#include <iostream>
#include <fstream>
#include <filesystem>


int main(const int argc, char *argv[]) {
    const char* version = "1.1";
    if (argc <= 1) {
        std::cout << "Usage: cleandir <path>"<< std::endl;
        std::cout << "try: cleandir --help for more options"<< std::endl;

        return 0;
    }


    // Check for help flags using std::string
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {

        std::cout << std::endl <<"Usage: cleandir <path>"<< std::endl;
        std::cout << std::endl;

        std::cout << "-v    --version" << std::endl << "        current version" << std::endl;
        std::cout << std::endl;

        return 0;
    }

    // Print current version
    if (std::string(argv[1]) == "--version" || std::string(argv[1]) == "-v") {
        std::cout << "Version " <<version << std::endl;
        return 0;
    }


    if (argc == 2) {
        std::cout << "run basic program "<< std::endl;

    }

    return 0;
}
