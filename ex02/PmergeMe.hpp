/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:56:52 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/10 16:07:59 by lbastien         ###   ########.fr       */
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
        }

        void _insertionSort(int start, int end) {
            for (int i = start + 1; i <= end; i++) {
                int value = _ctn[i];
                int j = i - 1;
                while (j >= start && _ctn[j] > value) {
                    _ctn[j + 1] = _ctn[j];
                    j--;
                }
                _ctn[j + 1] = value;
            }
        }

        void _mergeSort (int start, int end) {
            if (end - start < 10)
                _insertionSort(start, end);
            else {
                int mid = start + ((end - start) / 2);
                _mergeSort(start, mid);
                _mergeSort(mid + 1, end);
                _merge(start, mid, end);                    
            }
        }

        void _merge(int start, int mid, int end) {
            Container tmp;
            int i = start;
            int j = mid + 1;
            
            while (i <= mid && j <= end) {
                if (_ctn[i] <= _ctn[j])
                    tmp.push_back(_ctn[i++]);
                else
                    tmp.push_back(_ctn[j++]);
            }

            while (i <= mid)
                tmp.push_back(_ctn[i++]);
            while (j <= end)
                tmp.push_back(_ctn[j++]);
            j = 0;
            for (i = start; i <= end; i++)
                _ctn[i] = tmp[j++];     
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
            else if (std::find(_ctn.begin(), _ctn.end(), num) != _ctn.end())
                throw duplicateValue();
            else
                _ctn.push_back(num);        
        }
        
        void sort(void) {
            _mergeSort(0, _ctn.size() - 1);
        }

        void print(int start, int end) {
            int i;
            for (i = start; i <= end; i++)
                std::cout << _ctn[i] << " ";
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