#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    this->fileToDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_database = other._database;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::openFile(std::string& filename) {
    std::ifstream in;

    this->_filein.open(filename.c_str());
    if (this->_filein.fail() || !this->_filein.is_open())
        std::cout << "Unable to open file" << std::endl;
    if (this->_filein.peek() == std::ifstream::traits_type::eof())
        std::cout << "Empty file!" << std::endl;
}

void BitcoinExchange::fileToDatabase(std::string filename) {
    std::string buffer;
    std::string data;
    std::string value;

    this->openFile(filename);
    if (this->_filein.is_open()) {
        while (std::getline(this->_filein, buffer)) {
            data  = buffer.substr(0, buffer.find(','));
            value  = buffer.substr(data.size() + 1, buffer.find('\n'));
            this->_database[data] = std::strtod(value.c_str(), NULL);
        }
        this->_filein.close();
    }
}

void BitcoinExchange::showDataBase(){
    std::map<std::string, double>::iterator it;
    for (it = this->_database.begin(); it != this->_database.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
}
