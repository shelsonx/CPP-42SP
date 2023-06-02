#include "ReadFile.hpp"

ReadFile::ReadFile(){}

std::string ReadFile::read(std::string filename)
{
    std::ifstream input;
    std::string inputStr;
    std::string text("");

    input.open(filename);
    if (input.fail() || !input.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        return std::string();
    }
    if (input.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Empty file!" << std::endl;
        return std::string();
    }
    while (std::getline(input, inputStr))
        text += inputStr + "\n";
    text.pop_back();
    input.close();
    return (text);
}
