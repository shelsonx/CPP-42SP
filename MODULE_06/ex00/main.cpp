#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc > 2) {
        std::cout << "Invalid argument!" << std::endl;
        return 1;
    }
    else if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else {
        std::cout << "./convert 0" << std::endl;
        ScalarConverter::convert("0");
        std::cout << std::endl;

        std::cout << "./convert nan" << std::endl;
        ScalarConverter::convert("nan");
        std::cout << std::endl;

        std::cout << "./convert *" << std::endl;
        ScalarConverter::convert("*");
        std::cout << std::endl;

        std::cout << "./convert inf" << std::endl;
        ScalarConverter::convert("inf");
        std::cout << std::endl;

        std::cout << "./convert -inf" << std::endl;
        ScalarConverter::convert("-inf");
        std::cout << std::endl;

        std::cout << "./convert inff" << std::endl;
        ScalarConverter::convert("inff");
        std::cout << std::endl;

        std::cout << "./convert -inff" << std::endl;
        ScalarConverter::convert("-inff");
        std::cout << std::endl;

        std::cout << "./convert 2147483648" << std::endl;
        ScalarConverter::convert("2147483648");
        std::cout << std::endl;

        std::cout << "./convert -2147483649" << std::endl;
        ScalarConverter::convert("-2147483649");
        std::cout << std::endl;

        std::cout << "./convert \"Hello École 42\"" << std::endl;
        ScalarConverter::convert("Hello École 42");
    }
    return 0;
}