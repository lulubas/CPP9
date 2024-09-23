#include "BitcoinExchange.hpp"
    
BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string& ratesFilepath, std::string& inputFilepath) {
    std::cout << "BitcoinExchange parameterized constructor called" << std::endl;
    _fillMap(ratesFilepath);
    _processInput(inputFilepath);
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

void BitcoinExchange::_fillMap(const std::string& filepath) {
    std::string line;
    std::ifstream file(filepath);

    if (!file.is_open())
        throw couldNotOpenFile(filepath);

    while(std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string value;

        if (getline(ss, date, ',') && getline(ss, value)) {
            double btcRate = atof(value.c_str());
            _rates.insert({date, btcRate});
        }
        else
            throw wrongSyntax();
    }
}

int BitcoinExchange::_stoi(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        throw badInput();
    return value;
}

float BitcoinExchange::_stof(const std::string& str) {
    std::stringstream ss(str);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        throw badInput();
    return value;
}

void BitcoinExchange::_checkDate(std::string date) {
    std::string yearStr;
    std::string monthStr;
    std::string dayStr;
    int year;
    int month;
    int day;

    std::istringstream ss(date);

    if (getline(ss, yearStr, '-') && getline(ss, monthStr, '-') && getline(ss, dayStr)) {
        year = stoi(yearStr);
        month = stoi(monthStr);
        day = stoi(dayStr);
    }
    else
        throw badInput();
    
    if (year <= 2008 || year >= 2025 || month < 1 || month > 12 || day > 31 || day < 1)
        throw badInput();
}

void BitcoinExchange::_checkValue(std::string value) {
    float fvalue = stof(value);

    if (fvalue <= 0)
        throw negativeNumber();
    else if (fvalue > 1000)
        throw tooLargeNumber();
}

void BitcoinExchange::_processInput(const std::string& filepath) {
    std::string line;
    std::ifstream file(filepath);

    if (!file.is_open())
        throw couldNotOpenFile(filepath);
    
    while(std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string value;

        if (getline(ss, date, '|') && getline(ss, value)) {
            _checkDate(date);
            _checkValue(value);

        }
        else
            throw wrongSyntax();
    }
}

BitcoinExchange::couldNotOpenFile::couldNotOpenFile(const std::string& filepath) : _filepath(filepath) {}

const char *BitcoinExchange::couldNotOpenFile::what() const throw() {
    std::stringstream ss;
    ss << "Could not open file: " << _filepath;
    std::string error = ss.str();
    return (error.c_str());
}


const char *BitcoinExchange::wrongSyntax::what() const throw() {
    return("Wrong Syntax");
}

const char *BitcoinExchange::badInput::what() const throw() {
    return("Bad Input");
}

const char *BitcoinExchange::negativeNumber::what() const throw() {
    return("Negative number");
}

const char *BitcoinExchange::tooLArgeNumber::what() const throw() {
    return("Number is too large");
}


