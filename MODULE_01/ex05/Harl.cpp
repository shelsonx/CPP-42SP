#include "Harl.hpp"

Harl::Harl(){}

static int getLevelIndex(const std::string level)
{
    std::string harlsNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i=0; i < 4; i++)
    {
        if (level.compare(harlsNames[i]) == 0)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    void (Harl::*harls[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    int index = getLevelIndex(level);
    if (index != -1)
        (this->*harls[index])();
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]: " << std::endl <<
        "I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-specialketchup burger. "
        "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]: " << std::endl <<
        "I cannot believe adding extra bacon costs more money. "
        "You didn’t put enough bacon in my burger! If you did, "
        "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]: " << std::endl <<
        "I think I deserve to have some extra bacon for free." 
        "I’ve been coming for years whereas you started "
        "working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]: " << std::endl <<
        "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}
