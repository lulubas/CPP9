/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:25:42 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/17 16:26:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<string>
#include<iostream>

class BitcoinExchange {
    private:
    public:
        BitcoinExchange();
        BitcoinExchange(std::string& type);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
};

#endif

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