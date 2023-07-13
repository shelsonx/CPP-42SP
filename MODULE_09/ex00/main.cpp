#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.showCalc(argv[1]);
    }
    catch (std::exception& e) {
        e.what();
    }
    return 0;
}