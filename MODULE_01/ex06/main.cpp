#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc == 2)
        harl.complain((std::string) argv[1]);
    else if (argc > 2)
        std::cout << "Only one parameter is allowed" << std::endl;
    else
        std::cout << "Need a level as a parameter " << std::endl;
        exit (1);
    return (0);
}
