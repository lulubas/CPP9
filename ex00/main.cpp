/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:26:22 by lbastien          #+#    #+#             */
/*   Updated: 2024/10/01 15:34:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Wrong number of arguments. Try:" << std::endl;
        std::cout << "./btc data.csv input.txt" << std::endl;
        return 0;
    }
    std::string ratesFilepath = argv[1];
    std::string inputFilepath = argv[2];
    
    BitcoinExchange btc(ratesFilepath, inputFilepath);

    return 0;
}

