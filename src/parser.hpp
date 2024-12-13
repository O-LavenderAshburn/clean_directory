#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Parser {
public:

    std::vector<int> flagArray;
    std::string expr;
    std::string filepath;

    // Constructor to initialize the string to parse
    inline explicit Parser(const std::string &input) {
        command_str = input;  // Ensure src is assigned properly

        //Flag Mapping: Force, Destroy, Expression
        flagArray = {0,0,0};
        expr ="";
        filepath ="";
    }

    inline void parseCommand() {
        // Call parse and return the result
        vectorised = vectorize(command_str);
        parse_flags();
    }

private:
    std::string command_str;
    std::vector<std::string> vectorised;

    inline void parse_filepath() {

        for (int i = 0; i < vectorised.size(); i++) {
            if (vectorised[i] == "-p" || vectorised[i] == "--path") {
                filepath = vectorised[i+1];
                return;
            }
        }
        filepath = vectorised[vectorised.size()-1];
    }

    inline void parse_flags() {




        for (int i = 0; i < vectorised.size(); i++) {
            std::string vec = vectorised[i];
            if (vec.at(0) == '-') {
                if (vec.at(1) == '-') {
                    if (vec == "--force") {
                        set_force();
                    }else if (vec == "--expression") {
                        set_expr(i);
                        i = i+1;
                    }else if (vec == "--destroy") {
                        set_destroy();
                    }else if (vec == "--path") {
                        continue;
                    }else {
                        std::cout << "unknown flag: " << vec << std::endl;
                        exit(1);
                    }

                }else
                    if (vec == "-f") {
                        set_force();
                    }else if (vec == "-e") {
                        set_expr(i);
                        i = i+1;
                    }else if (vec == "-d") {
                        set_destroy();
                    }else if (vec == "-p") {
                            continue;
                    }else {
                        std::cout << "unknown flag: " << vec << std::endl;
                        exit(1);
                    }

                }
            }

        }

    inline void set_force() {
        flagArray[0] = 1;
    }

    inline void set_destroy() {
        flagArray[1] = 1;
    }

    inline void set_expr(int i) {
        flagArray[2] = 1;
        expr = vectorised[i+1];
    }



    static inline std::vector<std::string> vectorize(const std::string &input) {
        std::vector<std::string> result;
        std::stringstream ss(input);  // Create a string stream from the input string
        std::string word;

        // Tokenize the string based on spaces and store each word in the vector
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }


};



#endif // PARSER_HPP
