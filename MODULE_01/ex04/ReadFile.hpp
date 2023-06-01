#ifndef READFILE_HPP
#define READFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class ReadFile {
    public:
        ReadFile();
        static std::string read(std::string filename);
};
#endif