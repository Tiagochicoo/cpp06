/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:18 by tpereira          #+#    #+#             */
/*   Updated: 2023/07/29 22:16:16 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;	
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	(void)i;
	o << "ScalarConverter Object" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

char					ScalarConverter::convertToChar(const char* str)
{
	char c = str[0];
	if (!isprint(c) || c == '0')
	{
		c = static_cast<char>(std::stoi(str));
		if (!std::isprint(c))
			std::cout << "Non displayable";
	}
	catch(const std::exception& e)
	{
		std::cerr << "impossible";
	}
	return c;
}

int						ScalarConverter::convertToInt(const char* str)
{
	int num;
	if (std::sscanf(str, "%d", &num) != 1)
	{
		std::cout << "Error: Invalid int literal format";
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "impossible";
	}
	return i;
}

float					ScalarConverter::convertToFloat(const char* str)
{
	float f;

	try
	{
		f = std::atof(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return f;
}

double					ScalarConverter::convertToDouble(const char* str)
{
	double d;

	try
	{
		d = std::atof(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return d;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */