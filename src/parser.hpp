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
    std::vector<std::string> input_args;
    // Constructor to initialize the string to parse
    inline explicit Parser(const std::vector<std::string> &input) {

        input_args = input;
        //Flag Mapping: Force, Destroy, Expression
        flagArray = {0,0,0};
        expr ="";
        filepath ="";
    }

    inline void parseCommand() {
        // Call parse and return the result
        parse_flags();
        parse_filepath();
    }

private:
    std::string command_str;

    inline void parse_filepath() {

        for (int i = 0; i < input_args.size(); i++) {
            if (input_args[i] == "-p" || input_args[i] == "--path") {
                filepath = input_args[i+1];
                return;
            }
        }
        filepath = input_args[input_args.size()-1];
    }

    inline void parse_flags() {

        for (int i = 0; i < input_args.size(); i++) {
            std::string vec = input_args[i];
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
        expr = input_args[i+1];
    }


};



#endif // PARSER_HPP
