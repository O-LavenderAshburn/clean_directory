#ifndef RUNNER_HPP
#define RUNNER_HPP

#include "parser.hpp"
#include <filesystem>
namespace fs = std::filesystem;

class Runner {
public:

    inline explicit Runner() = default;

    void run(const std::vector<std::string>& args) {


        Parser parser(args);
        parser.parseCommand();

        //get files to delete
        std::string path = parser.filepath;
        std::vector<std::string> fileList = getFiles(path);

        try {
            // Ask the user to delete files
            for (const auto& file : fileList) {
                // Delete without prompting
                if (parser.forceFlag.isSet) {
                    try {
                        fs::remove(path + "/" + file);
                        std::cout << "Deleted " << file << std::endl;
                    }catch (const fs::filesystem_error& e){
                        std::cerr << "Error deleting file: " << e.what() << std::endl;
                        }
                }else{
                    // Prompt user before deleting
                    char choice;
                    std::cout << "Delete File? " << file << " (y/n): ";
                    std::cin >> choice;

                    if (choice == 'y' || choice == 'Y') {
                        try {
                            fs::remove(path + "/" + file);
                            std::cout << "Deleted " << file << std::endl;

                        } catch (const fs::filesystem_error& e) {
                            std::cerr << "Error deleting file: " << e.what() << std::endl;
                        }
                    } else {
                        std::cout << "Skipped " << file << std::endl;
                    }
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error reading directory: " << e.what() << std::endl;
        }
    }

private:

    std::vector<std::string> getFiles(std::string path){
        std::vector<std::string> fileList;
        // Get the list of files (excluding directories)
        try {
            for (const auto& entry : fs::directory_iterator(path)) {
                if (fs::is_regular_file(entry)) {
                    fileList.push_back(entry.path().filename().string());
                }
            }
        }catch (const fs::filesystem_error& e) {
            std::cerr << "Error reading directory: " << e.what() << std::endl;
        }
        return fileList;
    }

};



#endif //RUNNER_HPP
