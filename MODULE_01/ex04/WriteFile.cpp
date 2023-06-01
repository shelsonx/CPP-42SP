#include "WriteFile.hpp"
#include <fstream>

void WriteFile::write(std::string text, std::string fileoutput)
{
    std::ofstream output(fileoutput + ".replace");
    output << text;
    output.close();
}
