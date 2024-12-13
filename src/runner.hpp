#ifndef RUNNER_HPP
#define RUNNER_HPP

#include "parser.hpp"

class Runner {
public:

    inline explicit Runner() = default;

    void run(const std::string& command) {

        Parser parser(command);
        parser.parseCommand();

        for (const int& element : parser.flagArray) {
            std::cout << element << " ";
        }

    }

private:




};







#endif //RUNNER_HPP
