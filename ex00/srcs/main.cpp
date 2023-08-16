/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:30 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/16 18:45:20 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	ScalarConverter converter;

	if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <C++ literal>" << std::endl;
        return 1;
    }
	else
	{
		std::string arg1(argv[1]);
		converter.convert(arg1);
	}

    return 0;
}
