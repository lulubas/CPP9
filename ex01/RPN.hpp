/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:40:46 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/03 12:52:33 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include<string>
#include<sstream>
#include<iostream>
#include<deque>

class RPN {
    private:
        std::deque<std::string> _myDeque;
        std::string _pop(void);
        void _fill(std::string& expr);
        int _checkInt(const std::string& str);
        char _checkOperand(const std::string& str);
        void _validateData(const std::string& str);

    public:
        RPN();
        RPN(std::string& expr);
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();
        
        int calculate(void);

        class outOfRange : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class badInput : public std::exception {
            public:
                const char* what() const throw();
        };
    
        class divisionByZero : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif