/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:55:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/04 11:31:23 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp";    

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::string& type) {
    std::cout << "PmergeMe parameterized constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    std::cout << "PmergeMe copy assignement operator called" << std::endl;
    if (this != &other) {}
    return *this;
}

PmergeMe::~PmergeMe(){
    std::cout << "PmergeMe destructor called" << std::endl;
}

int PmergeMe::_stoi(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        throw badInput();
    return value;
}

const char* PmergeMe::badInput::what() const throw() {
    return("Bad Input.");
}

const char* PmergeMe::negativeNumber::what() const throw() {
    return("Neative Number.");
}
