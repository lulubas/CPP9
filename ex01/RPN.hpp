/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:40:46 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/10 15:26:56 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include<string>
#include<sstream>
#include<iostream>
#include<stack>

class RPN {
    private:
        std::stack<int> _stack;
        std::string     _expression;
        
        bool _isValidInt(const std::string& str);
        bool _isValidOperand(const std::string& str);
        int _stoi(const std::string& str);

    public:
        RPN();
        RPN(std::string& expr);
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();
        
        int processInput(void);
        int calculate(char c);

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