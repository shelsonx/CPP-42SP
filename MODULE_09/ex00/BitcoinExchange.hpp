#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <exception>

struct input {
    std::string date;
    double value;
    bool validInput;
};

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    
        void showCalc(std::string filename);

    private:
        std::map<std::string, double> _database;
        std::list<input> _inputs;
        std::ifstream _filein;

        void openFile(std::string& filename);
        void loadInput(std::string filename);
        void fileToDatabase(std::string filename);

        void checkFinded(
            std::map<std::string, double>::const_iterator& 
            search,std::list<input>::iterator& it);
        void checkNotFound(std::list<input>::iterator& it);
        bool checkValue(double& value) const;
        bool isValidDate(const std::string& date);
        void checkInputs(
            std::map<std::string, double>::const_iterator& search, 
            std::list<input>::iterator& it);
        void display(
            std::map<std::string, double>::const_iterator& search, 
            std::list<input>::iterator& it);
};

#endif