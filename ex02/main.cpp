#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Use at least one argument" << std::endl;
        return 0;
    }

    PmergeMe<std::vector<int>> mpmVector;
    PmergeMe<std::list<int>> mpmList;

    try
    {
        int i;
        int j;
        for (i = 1; i < argc; i++) {
            std::string numStr(argv[i]);
            mpmVector.fill(numStr);
            mpmList.fill(numStr);
        }
        return 0;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}