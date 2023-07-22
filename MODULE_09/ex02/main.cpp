#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        PmergeMe merge(argc, argv);
        merge.display();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
