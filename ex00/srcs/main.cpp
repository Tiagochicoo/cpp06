/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:30 by tpereira          #+#    #+#             */
/*   Updated: 2023/07/17 22:14:16 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter sc;

	if (argc != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	std::cout << "char: ";
	try
	{
		char c = sc.convertToChar(argv[1]);
		std::cout << "'" << c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "int: ";
	try
	{
		int i = sc.convertToInt(argv[1]);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "float: ";
	try
	{
		float f = sc.convertToFloat(argv[1]);
		std::cout << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "double: ";
	try
	{
		double d = sc.convertToDouble(argv[1]);
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}