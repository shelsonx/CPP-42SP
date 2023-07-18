#ifndef RPN_HPP

#define RPN_HPP
#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void execute(std::string& inputs);
        int convertCharToInt(char& c);
        int stoi( std::string& s );

    private:
        std::stack<int> _stack;

        void checkLessTen(std::string inputs);
        void checkValidChar(char& c);

        int applyOperation(char& op);
        void skipSpace(std::string::iterator& it);
};

#endif