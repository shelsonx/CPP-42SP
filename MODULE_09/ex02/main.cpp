#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        PmergeMe merge(argc, argv);
        merge.sort();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
