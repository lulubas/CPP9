/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:58:35 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/03 16:07:54 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    //std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(std::string& str) : _expression(str) {
    //std::cout << "RPN parameterized constructor called" << std::endl;
}

RPN::RPN(const RPN& other) {
    //std::cout << "RPN copy constructor called" << std::endl;
    (void)other;
}

RPN& RPN::operator=(const RPN &other) {
    //std::cout << "RPN copy assignement operator called" << std::endl;
    if (this != &other) {}
    return *this;
}

RPN::~RPN(){
    //std::cout << "RPN destructor called" << std::endl;
}

int RPN::processInput(void) {
    std::stringstream ss(_expression);
    std::string word;
    
    while (ss >> word) {
        if (_isValidInt(word))
            _myDeque.push_front(stoi(word));
        else if (_isValidOperand(word)) {
            int result = calculate(word[0]);
            _myDeque.push_front(result);
        }
        else
            throw badInput();
    }
    
    if(_myDeque.size() == 1)
        return _myDeque.front();
    else
        throw badInput();
}

int RPN::calculate (char operand) {
    int num1 = _myDeque.front();
    _myDeque.pop_front();
    int num2 = _myDeque.front();
    _myDeque.pop_front();
        
    switch (operand) {
            case '+' :
                return (num2 + num1);
                break;
            case '-' :
                return (num2 - num1);
                break;
            case '*':
                return (num2 * num1);
                break;
            case '/':
                if (num2 == 0)
                    throw divisionByZero();
                return (num2 / num1);
                break;
            default:
                throw badInput();
        }
}

bool RPN::_isValidInt(const std::string& str) {
    try {
        int num = stoi(str);
        if (num < 0 || num > 9)
            throw outOfRange();
        return true;
    }
    catch (std::exception &e) {
        return false;
    }
}

bool RPN::_isValidOperand(const std::string& str) {
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    else
        return false;
}

const char* RPN::outOfRange::what() const throw() {
    return("Number out of range. Only use int between 0 and 10");
}

const char* RPN::badInput::what() const throw() {
    return("Bad Input.");
}

const char* RPN::divisionByZero::what() const throw() {
    return("No NOOOOOOO. You didived by zero. World has ended.");
}