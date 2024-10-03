/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:26:22 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/03 12:03:56 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong number of arguments. Try:" << std::endl;
        std::cout << "./rpn \"8 3 + 5 +\"" << std::endl;
        return 0;
    }
    try
    {
        std::string str(argv[1]);
        RPN myRPN(str);
        std::cout << "Reusult=" << myRPN.calculate() << std::endl;
        return 0;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}

