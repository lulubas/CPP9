#include"PmergeMe.hpp"
#include<ctime>
#include <iomanip>


int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Use at least one argument. Try:" << std::endl;
        std::cout << "./PmergeMe `shuf -i 1-100 -n 25 | tr \"\\n\" \" \"`" << std::endl;
        return 0;
    }

    std::cout << "Before: ";
    int i;
    for (i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    //Vector
    PmergeMe< std::vector<int> > mpmVector;
    clock_t tVectorFill = clock();
    try
    {
        int i;
        for (i = 1; i < argc; i++) {
            std::string numStr(argv[i]);
            mpmVector.fill(numStr);
        }
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    tVectorFill = clock() - tVectorFill;
    clock_t tVectorSort = clock();
    mpmVector.sort();
    tVectorSort = clock() - tVectorSort;

    //Deque
    PmergeMe< std::deque<int> > mpmDeque;
    clock_t tDequeFill = clock();
    try
    {
        int i;
        for (i = 1; i < argc; i++) {
            std::string numStr(argv[i]);
            mpmDeque.fill(numStr);
        }
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    tDequeFill = clock() - tDequeFill;
    clock_t tDequeSort = clock();
    mpmDeque.sort();
    tDequeSort = clock() - tDequeSort;

    std::cout << "After: ";
    mpmVector.print(0, argc - 2);
    std::cout << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(3);

    std::cout << "Time to process " << argc - 1 << " integers with std::vector: " << (float)(tVectorFill) / CLOCKS_PER_SEC * 1000;
    std::cout << "ms[Fill] + " << (float)(tVectorSort) / CLOCKS_PER_SEC * 1000;
    std::cout << "ms[Sort] = " << (float)(tVectorFill+tVectorSort) / CLOCKS_PER_SEC * 1000 << "ms[Total]" << std::endl;

    std::cout << "Time to process " << argc - 1 << " integers with std::deque: " << (float)(tDequeFill) / CLOCKS_PER_SEC * 1000;
    std::cout << "ms[Fill] + " << (float)(tDequeSort) / CLOCKS_PER_SEC * 1000;
    std::cout << "ms[Sort] = " << (float)(tDequeFill+tDequeSort) / CLOCKS_PER_SEC * 1000 << "ms[Total]" << std::endl;

    return 0;
}