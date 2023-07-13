#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;
    BitcoinExchange btc;
    btc.showDataBase();
    std::cout << std::endl;
    btc.loadInput("input.txt");
    btc.showInputs();
}