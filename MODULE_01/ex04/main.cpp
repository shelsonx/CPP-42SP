#include "ReadFile.hpp"
#include "WriteFile.hpp"
#include "ReplaceStr.hpp"

bool validate_args(int argc)
{
    if (argc == 4)
        return true;
    else if (argc == 1)
        std::cout << "No file received as parameter" << std::endl;
    else
        std::cout << "Need file plus two str to replace" << std::endl;
    return false;
}

int main(int argc, char **argv)
{
    if (!validate_args(argc))
        return 1;
    std::string input = ReadFile::read(argv[1]);
    if (input.empty())
        return 1;
    ReplaceStr::replace(input, (std::string) argv[2], (std::string) argv[3]);
    WriteFile::write(input, (std::string) argv[1]);
    return (0);
}
