#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    
        void showDataBase();

    private:
        std::map<std::string, double> _database;
        std::ifstream _filein;

        void openFile(std::string& filename);
        void fileToDatabase(std::string filename);
};

#endif