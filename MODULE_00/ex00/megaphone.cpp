#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int x = 1; x < argc; x++)
    {
        for (int y = 0; y < strlen(argv[x]); y++)
        {
            std::cout << (char)std::toupper(argv[x][y]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
