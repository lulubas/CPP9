/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:56:52 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/04 12:23:21 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>

template <typename Container> 
class PmergeMe {
    private:
        Container _ctn;
        
        int _stoi(const std::string& str) {
            std::stringstream ss(str);
            int value;
            ss >> value;
            if (ss.fail() || !ss.eof())
                throw badInput();
            return value;
        };

    public:
        PmergeMe(){}
        PmergeMe(const PmergeMe &other){(void)other;}
        PmergeMe& operator=(const PmergeMe &other){(void)other;}
        ~PmergeMe(){}

        void fill(std::string str) {
            int num = _stoi(str);
            
            if (num < 0)
                throw negativeNumber();
            else if (std::find(_ctn.begin(), _ctn.end(), num) != _ctn.end())
                throw duplicateValue();
            else
                _ctn.push_back(num);        
        }

        void print(void) {
            unsigned long i;
            for (i = 0; i < _ctn.size(); i++)
                std::cout << _ctn[i] << std::endl;
        }

        class duplicateValue : public std::exception {
            public:
                const char* what() const throw() {
                    return("Duplicate Value."); 
                }
        };
        
        class negativeNumber : public std::exception {
            public:
                const char* what() const throw() {
                    return("Neative Number."); 
                }
        };
        
        class badInput : public std::exception {
            public:
                const char* what() const throw() {
                    return("Bad Input.");
                }
        };
};

#endif