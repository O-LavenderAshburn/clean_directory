#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


enum class Flag {force, destroy, expression,verbose};

struct SetFlag {
    Flag flag;
    bool isSet;

    // Constructor to initialize the flag and its state
    explicit SetFlag(Flag f, bool set = false) : flag(f), isSet(set) {}

};


class Parser {
public:

    //Set flags
    SetFlag forceFlag = SetFlag(Flag::force, false);
    SetFlag destroyFlag = SetFlag(Flag::destroy, false);
    SetFlag exprFlag = SetFlag (Flag::expression, false);
    SetFlag verboseFlag = SetFlag (Flag::verbose, false);


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
                if (vec == "--force" || vec == "-f") {
                    forceFlag.isSet = true;
                }else if (vec == "--expression" || vec == "-e") {
                    exprFlag.isSet = true;
                    expr = input_args[i+1];
                    i = i+1;
                }else if (vec == "--destroy" || vec == "-d") {
                    destroyFlag.isSet = true;
                }else if (vec == "--path" || vec == "-p") {
                    continue;
                }else if (vec == "--verbose"){
                    verboseFlag.isSet = true;
                }else{
                    std::cout << "unknown flag: " << vec << std::endl;
                    exit(1);
                }
            }
        }
    }
};



#endif // PARSER_HPP
