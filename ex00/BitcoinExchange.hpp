/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:25:42 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/17 21:49:10 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<string>
#include<iostream>
#include <fstream>  
#include<map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _btcRates;
        std::map<std::string, float> _btcInput;
        
    public:
        BitcoinExchange();
        BitcoinExchange(std::string& ratesFilepath, std::string& inputFilepath);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        fillMap(std::string& filepath, char separator);
        void printResults(void);
        
};

#endif