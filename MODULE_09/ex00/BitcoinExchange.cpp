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

    this->_filein.open(filename.c_str());
    if (this->_filein.fail() || !this->_filein.is_open())
        std::cout << "Unable to open file" << std::endl;
    if (this->_filein.peek() == std::ifstream::traits_type::eof())
        std::cout << "Empty file!" << std::endl;
}

void BitcoinExchange::fileToDatabase(std::string filename) {
    std::string buffer;
    std::string date;
    std::string value;

    this->openFile(filename);
    if (this->_filein.is_open()) {
        while (std::getline(this->_filein, buffer)) {
            date  = buffer.substr(0, buffer.find(','));
            value  = buffer.substr(date.size() + 1, buffer.find('\n'));
            this->_database[date] = std::strtod(value.c_str(), NULL);
        }
        this->_filein.close();
    }
}

void BitcoinExchange::loadInput(std::string filename) {
    std::string buffer;
    std::string value;
    input in;

    this->openFile(filename);
    if (this->_filein.is_open()) {
        while (std::getline(this->_filein, buffer)) {
            if (buffer.find("|") != std::string::npos)
                in.date  = buffer.substr(0, buffer.find('|') -1);
            else
                in.date = buffer;
            if (buffer.find("|") != std::string::npos)
                value = buffer.substr(buffer.find("|") + 2, buffer.size());
            else
                value = "0";
            in.value = std::strtod(value.c_str(), NULL);
            this->_inputs.push_back(in);
        }
        this->_filein.close();
    }
    this->_filein.close();
}

void BitcoinExchange::showDataBase() {
    std::map<std::string, double>::iterator it;
    for (it = this->_database.begin(); it != this->_database.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
}

void BitcoinExchange::showInputs() {
    std::list<input>::iterator it;
    for (it = this->_inputs.begin(); it != this->_inputs.end(); ++it)
        std::cout << (*it).date << ":" << (*it).value << std::endl;
    this->_filein.close();
}
