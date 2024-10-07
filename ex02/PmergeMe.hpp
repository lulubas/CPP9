/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:56:52 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/07 16:49:55 by lbastien         ###   ########.fr       */
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
        Container _Ctn;
        Container _sortedCtn;
        
        int _stoi(const std::string& str) {
            std::stringstream ss(str);
            int value;
            ss >> value;
            if (ss.fail() || !ss.eof())
                throw badInput();
            return value;
        }

        void _insertionSort(int start, int end) {
            for (int i = start + 1; i <= end; ++i) {
                int value = _Ctn[i];
                int j = i - 1;
                while (j >= start && _Ctn[j] > value) {
                    _Ctn[j + 1] = _Ctn[j];
                    --j;
                }
                _Ctn[j + 1] = value;
            }
        }

        void _mergeSort (int start, int end) {
            if (end - start <= 10)
                _insertionSort(start, end);
            else {
                int mid = start + ((end - start) / 2);
                _mergeSort(start, mid);
                _mergeSort(mid, end);
                _merge(start, mid, end);                    
            }
        }

        void _merge(int start, int mid, int end) {
            int lastSecond = end;
            int lastFirst = mid;

            while (lastFirst >= start) {
                if (_ctn[lastSecond] >= _ctn[lastFirst])
                    _ctn[end--] = _ctn[lastSecond--];
                else
                    _ctn[end--] = _ctn[lastFirst--];
            }

            while (lastSecond > mid)
                    _ctn[end--] = _ctn[lastSecond--];
        }

         
    public:
        PmergeMe(){}
        PmergeMe(const PmergeMe &other){(void)other;}
        PmergeMe& operator=(const PmergeMe &other){(void)other;}
        ~PmergeMe(){}

        void fill(std::string str) {
            int num = _stoi(str);
            
            if (num < 0)
                throw negativeNumber();
            else if (std::find(_unsortedCtn.begin(), _unsortedCtn.end(), num) != _unsortedCtn.end())
                throw duplicateValue();
            else
                _unsortedCtn.push_back(num);        
        }
        
        void sort(void) {
            _mergeSort();
        }

        void print(void) {
            unsigned long i;
            
            std::cout << "Unsorted=" << std::endl;
            for (i = 0; i < _unsortedCtn.size(); i++)
                std::cout << _unsortedCtn[i] << std::endl;
            std::cout << "Sorted=" << std::endl;
            for (i = 0; i < _sortedCtn.size(); i++)
                std::cout << _sortedCtn[i] << std::endl;
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