#include "Harl.hpp"

Harl::Harl(){}

void Harl::complain(std::string level)
{
    int index = -1;
    std::string harlsNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (level.compare(harlsNames[i]) == 0)
            index = i;
    }
    switch (index)
    {
        case 0:
            debug();
            [[fallthrough]];
        case 1:
            info();
            [[fallthrough]];
        case 2:
            warning();
            [[fallthrough]];
        case 3:
            error();
            break;
        default:
            std::cout << 
                "[ Probably complaining about insignificant problems ]" 
                << std::endl;
            break;
    }
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]: " << std::endl <<
        "I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-specialketchup burger. "
        "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]: " << std::endl <<
        "I cannot believe adding extra bacon costs more money. "
        "You didn’t put enough bacon in my burger! If you did, "
        "I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]: " << std::endl <<
        "I think I deserve to have some extra bacon for free." 
        "I’ve been coming for years whereas you started "
        "working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]: " << std::endl <<
        "This is unacceptable! I want to speak to the manager now."
        << std::endl << std::endl;
}
