#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Invalid arguments." << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        std::string inputs(argv[1]);
        rpn.execute(inputs);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
