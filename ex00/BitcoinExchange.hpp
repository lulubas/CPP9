/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:25:42 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/01 15:58:39 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<string>
#include<sstream>
#include<iostream>
#include<fstream>  
#include<map>
#include <stdlib.h> 

class BitcoinExchange {
    private:
        std::map<std::string, double> _rates;

        void    _checkDate(std::string date);
        void    _checkValue(std::string value);
        void    _fillMap(const std::string& filepath);
        void    _processInput(const std::string& filepath);
        void    _printResult(const std::string& date, const std::string& value);        
        int     _stoi(const std::string& str);
        float     _stof(const std::string& str);

    public:
        BitcoinExchange();
        BitcoinExchange(std::string& ratesFilepath, std::string& inputFilepath);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        class couldNotOpenFile : public std::exception {
            private:
                std::string _filepath;
                std::string _error;
            public:
                couldNotOpenFile(const std::string& filepath);
                const char *what() const throw();
                ~couldNotOpenFile() throw();
        };
        
        class wrongSyntax : public std::exception {
            public:
                const char *what() const throw();
        };
        
        class badInput : public std::exception {
            public:
                const char *what() const throw();
        };
        
        class negativeNumber : public std::exception {
            public:
                const char *what() const throw();
        };
        class tooLargeNumber : public std::exception {
            public:
                const char *what() const throw();
        };
        
};

#endif