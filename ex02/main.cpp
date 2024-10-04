#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Use at least one argument" << std::endl;
        return 0;
    }

    PmergeMe< std::vector<int> > mpmVector;
    PmergeMe< std::deque<int> > mpmDeque;

    try
    {
        int i;
        for (i = 1; i < argc; i++) {
            std::string numStr(argv[i]);
            mpmVector.fill(numStr);
            mpmDeque.fill(numStr);
        }
    }    
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    mpmVector.sort();
    mpmDeque.sort();

    std::cout << "Printing content of Vector :" << std::endl;
    mpmVector.print();
    std::cout << "Printing content of Deque :" << std::endl;
    mpmDeque.print();
    return 0;
}