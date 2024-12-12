#include <iostream>
#include <fstream>
#include <filesystem>




int main(const int argc, char *argv[]) {

    if (argc < 1) {
        std::cout << "Usage: cleandir <path>"<< std::endl;
        return 0;
    }

    // Check for help flags using std::string
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        std::cout << "Usage: cleandir <path>" << std::endl;
        return 0;
    }


    std::filesystem::path execPath = std::filesystem::current_path();
    execPath /= argv[1];

    std::cout << "Executable Path: " << execPath << std::endl;


    return 0;
}
