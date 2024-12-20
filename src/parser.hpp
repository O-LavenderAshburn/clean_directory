#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>


enum class Flag {force, destroy, regex,verbose, extension};

struct SetFlag {
    Flag flag;
    bool isSet;

    // Constructor to initialize the flag and its state
    explicit SetFlag(Flag f, bool set = false) : flag(f), isSet(set) {}

};


class Parser{
public:

    //Set flags
    SetFlag forceFlag = SetFlag(Flag::force, false);
    SetFlag destroyFlag = SetFlag(Flag::destroy, false);
    SetFlag exprFlag = SetFlag (Flag::regex, false);
    SetFlag verboseFlag = SetFlag (Flag::verbose, false);
    SetFlag extensionFlag = SetFlag (Flag::extension, false);

    std::vector<int> flagArray;
    std::string expr;
    std::string filepath;
    std::vector<std::string> input_args;
    std::string extensions;

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


    /*
     *Parse flags set in the input args
     *
     */
    inline void parse_flags() {

        for (int i = 0; i < input_args.size(); i++) {
            std::string vec = input_args[i];
            if (vec.at(0) == '-') {
                if (vec == "--force" || vec == "-f") {
                    forceFlag.isSet = true;
                }else if (vec == "--regex" || vec == "-r") {
                    exprFlag.isSet = true;
                    expr = input_args[i+1];
                    i = i+1;
                }else if (vec == "--destroy" || vec == "-d") {
                    // error if more flags are present with destroy
                    if (vec.size() > 2) {
                        std::cout << "Too many flags for destroy"  << std::endl;
                        exit(1);
                    }
                    destroyFlag.isSet = true;
                    return;
                }else if (vec == "--path" || vec == "-p") {
                    continue;
                }else if (vec == "--verbose"){
                    verboseFlag.isSet = true;
                }else if (vec == "-e" || vec == "--extension"){
                    extensionFlag.isSet = true;
                    extensions = input_args[i+1];
                }else{
                    std::cout << "unknown flag: " << vec << std::endl;
                    exit(1);
                }
            }
        }
        if (extensionFlag.isSet) {
            parse_extension(extensions);
        }
    }

    /*
     *Parse the validity of the input of the extension
     *
     */
    inline void parse_extension(const std::string& extn) {
        std::regex pattern(R"(\{(\w+)(,\w+)*\})");
        if (std::regex_match(extn, pattern)) {
            if (verboseFlag.isSet) {
                extensions = extn;
                std::cout << "Deleting files from extension set: "<< extn << std::endl;
            }
        } else {
            std::cout << "Invalid extension format. Use format: -e {jpg,py,} " << extn << std::endl;
            exit(1);
        }
    }
};



#endif // PARSER_HPP
