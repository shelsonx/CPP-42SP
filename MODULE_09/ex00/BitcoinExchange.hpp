#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>

struct input {
    std::string date;
    double value;
};

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    
        void showDataBase();
        void showInputs();
        void loadInput(std::string filename);

    private:
        std::map<std::string, double> _database;
        std::list<input> _inputs;
        std::ifstream _filein;

        void openFile(std::string& filename);
        void fileToDatabase(std::string filename);
};

#endif