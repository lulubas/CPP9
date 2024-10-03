/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:58:35 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/03 13:26:19 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(std::string& expr) {
    std::cout << "RPN parameterized constructor called" << std::endl;
    _fill(expr);
}

RPN::RPN(const RPN& other) {
    std::cout << "RPN copy constructor called" << std::endl;
    (void)other;
}

RPN& RPN::operator=(const RPN &other) {
    std::cout << "RPN copy assignement operator called" << std::endl;
    if (this != &other) {}
    return *this;
}

RPN::~RPN(){
    std::cout << "RPN destructor called" << std::endl;
}

void RPN::_fill(std::string& expr) {
    std::stringstream ss(expr);
    std::string word;

    while (ss >> word) {
        _validateData(word);
        _myDeque.push_back(word);
    }
}

int RPN::calculate(void) {
    int result = 0;

    while (_myDeque.size() > 1) {
        int num1 = _checkInt(_pop());
        int num2 = _checkInt(_pop());
        char operand = _checkOperand(_pop());
                
        switch (operand) {
            case '+' :
                result = num1 + num2;
                break;
            case '-' :
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0)
                    throw divisionByZero();
                result = num1 / num2;
                break;
            default:
                throw badInput();
        }
        _myDeque.push_front(std::to_string(result));
    }
    if (_myDeque.size())
        return;
}

int RPN::_checkInt(const std::string& str) {
    try {
        int num = stoi(str);
        return num;
    }
    catch (std::exception &e) {
        throw badInput();
    }
}

void RPN::_validateData(const std::string& str) {
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return;
    try {
        int num = stoi(str);
        if (num < 0 || num > 9)
            throw outOfRange();
        return;
    }
    catch (std::exception &e) {
        throw badInput();
    }
}

char RPN::_checkOperand(const std::string& str) {
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return str[0];
    else
        throw badInput();
}

std::string RPN::_pop(void) {
    std::string str = _myDeque.front();
    _myDeque.pop_front();
    return(str);
}

const char* RPN::outOfRange::what() const throw() {
    return("Number out of range. Only use int between 0 and 10");
}

const char* RPN::badInput::what() const throw() {
    return("Bad Input. Only Ints and operands.");
}

const char* RPN::divisionByZero::what() const throw() {
    return("No NOOOOOOO. You didived by zero. World has ended.");
}