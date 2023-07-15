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
    else if (this->_filein.peek() == std::ifstream::traits_type::eof())
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

void BitcoinExchange::checkFormat(input& in, const std::string& buffer) {
    size_t finded;
    std::string leftInput;
    std::string rightInput;

    in.validFormat = true;
    finded = buffer.find("|");
    if (finded == std::string::npos) {
        in.validFormat = false;
    }
    else {
        leftInput = buffer.substr(0, finded);
        rightInput = buffer.substr(finded);
        if (leftInput[leftInput.size() - 1] != ' ') 
            in.validFormat = false;
        if (rightInput[1] != ' ' || rightInput.size() < 3)
            in.validFormat = false;
    }
}

void BitcoinExchange::loadInput(std::string filename) {
    std::string buffer;
    std::string value;
    input in;

    this->openFile(filename);
    if (this->_filein.is_open()) {
        while (std::getline(this->_filein, buffer)) {
            checkFormat(in, buffer);
            if (in.validFormat) {
                in.date = buffer.substr(0, buffer.find("|") -1);
                value = buffer.substr(buffer.find("|") + 2);
            }
            else {
                in.date = buffer;
                value = "";
            }
            in.value = std::strtod(value.c_str(), NULL);
            this->_inputs.push_back(in);
        }
        this->_filein.close();
    }
}

bool BitcoinExchange::checkValue(double& value) const {
    bool result = true;

    if (value < 0) {
        result = false;
        std::cout << "Error: not a positive number." << std::endl;
    }
    if (value > 1000) {
        result = false;
        std::cout << "Error: too large a number." << std::endl;
    }
    return result;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    bool leapYear;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    if (month == 2) {
        leapYear = ((year % 4 == 0 && year && 100 != 0) || (year % 400 == 0)) ? true : false;
        if (leapYear && month > 29)
            return false;
        if (!leapYear && month > 28)
            return false;
    }
    return true;
}

 void BitcoinExchange::display(
        std::map<std::string, double>::const_iterator& search, 
        std::list<input>::iterator& it) {
    if (!(*it).validFormat) {
        std::cout << "Error: bad input => " << (*it).date << std::endl;
        return; 
    }
    if (!isValidDate((*it).date)) {
        std::cout << "Error: Date is not valid  => " << (*it).date << std::endl;
        return ;
    }
    if (!checkValue((*it).value))
        return ;
    std::cout
        << (*it).date
        << " => " << (*it).value << " = "
        << ((*it).value * search->second)
        << std::endl;
}

void BitcoinExchange::checkFinded(
    std::map<std::string, double>::const_iterator& search, 
    std::list<input>::iterator& it) {
    display(search, it);
}

void BitcoinExchange::checkNotFound(std::list<input>::iterator& it) {
    std::map<std::string, double>::const_iterator search;

    search = this->_database.lower_bound((*it).date);
    if (search != this->_database.begin())
        search--;
    display(search, it);
}

void BitcoinExchange::checkInputs(
    std::map<std::string, double>::const_iterator& search, 
    std::list<input>::iterator& it) {  
    if (search != this->_database.end())
        checkFinded(search, it);
    else
        checkNotFound(it);
}

void BitcoinExchange::showCalc(std::string filename) {
    std::map<std::string, double>::const_iterator search;
    std::list<input>::iterator it;
    
    this->loadInput(filename);
    it = this->_inputs.begin();
    while (++it != this->_inputs.end()) {
        search = this->_database.find((*it).date);       
        checkInputs(search, it);
    }
}
