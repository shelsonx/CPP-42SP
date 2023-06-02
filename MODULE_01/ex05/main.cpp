#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc == 2)
        harl.complain((std::string) argv[1]);
    else if (argc == 1)
    {
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
    }
    else
        exit (1);
    return (0);
}
