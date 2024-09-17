/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:26:22 by lbastien          #+#    #+#             */
/*   Updated: 2024/09/17 21:47:01 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 3)
        std::cout << "Wrong number of arguments";
    std::string ratesFilepath = argv[1];
    std::string inputFilepath = argv[2];
    
    BitcoinExchange btc(ratesFilepath, inputFilepath);
    BitcoinExchange.printResults();

    return 0;
}

