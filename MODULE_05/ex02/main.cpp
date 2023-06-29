#include <iomanip>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int main(void) {
    ShrubberyCreationForm s1("home");
    try {
        std::cout << "is it Signed? " 
                << (s1.isSigned() ? "Yes" : "Not") << std::endl;
        s1.execute(Bureaucrat("b1", 135));
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}
