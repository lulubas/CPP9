#include "BitcoinExchange.hpp"
    
BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string& type) {
    std::cout << "BitcoinExchange parameterized constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    std::cout << "BitcoinExchange copy assignement operator called" << std::endl;
    if (this != &other) {}
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
    std::cout << "BitcoinExchange destructor called" << std::endl;
}