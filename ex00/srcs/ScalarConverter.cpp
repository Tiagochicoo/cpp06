/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:18 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/04 19:31:58 by tpereira         ###   ########.fr       */
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

void ScalarConverter::setType(int type)
{
	_type = type;
}

void ScalarConverter::setValue(double value)
{
	_value = value;
}

void ScalarConverter::getType(std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		setType(CHAR);
	else if (str == "nan" || str == "nanf")
		setType(PSEUDO);
	else if (str == "inf" || str == "inff")
		setType(PSEUDO);
	else if (str == "-inf" || str == "-inff")
		setType(PSEUDO);
	else
	{
		char *endptr;
		_value = strtod(str.c_str(), &endptr);
		if (endptr == str.c_str())
			setType(NOT);
		else if (*endptr == '\0')
		{
			if (str.find('.') != std::string::npos)
				setType(DOUBLE);
			else
				setType(INT);
		}
		else if (*endptr == 'f' && *(endptr + 1) == '\0')
		{
			if (str.find('.') != std::string::npos)
				setType(FLOAT);
			else
				setType(INT);
		}
		else
			setType(NOT);
	}
}

int ScalarConverter::calculatePrecision(std::string& str) 
{
	size_t decimalPoint = str.find('.');
	return (decimalPoint != std::string::npos) ? (str.length() - decimalPoint - 1) : 0;
}

void ScalarConverter::getValue(std::string &str)
{
	if (_type == CHAR)
	{
		setValue(static_cast<double>(str[0]));
	}
	else if (_type == INT)
	{
		setValue(static_cast<double>(atoi(str.c_str())));
	}
	else if (_type == FLOAT)
	{
		setValue(static_cast<double>(atof(str.c_str())));
	}
	else if (_type == DOUBLE)
	{
		setValue(static_cast<double>(strtod(str.c_str(), NULL)));
	}
	else if (_type == PSEUDO)
	{
		setValue(static_cast<double>(strtod(str.c_str(), NULL)));
	}
	else
	{
		setValue(0);
	}
}

void ScalarConverter::convert(std::string &str)
{
	_str = str;
	getType(_str);
	getValue(_str);
	printChar();
	printInt();
	printFloat();
	printDouble();	
}

void ScalarConverter::printChar()
{
	if (_type == CHAR)
	{
		std::cout << "char: '" << static_cast<char>(_value) << "'" << std::endl;
	}
	else if (_type == INT)
	{
		if (_value > 0 && _value <= 127)
			std::cout << "char: '" << static_cast<char>(_value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (_type == FLOAT)
	{
		if (_value >= 0 && _value <= 127)
			std::cout << "char: '" << static_cast<char>(_value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (_type == DOUBLE)
	{
		if (_value >= 0 && _value <= 127)
			std::cout << "char: '" << static_cast<char>(_value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (_type == PSEUDO)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::printInt()
{
	if (_type == CHAR)
	{
		std::cout << "int: " << static_cast<int>(_value) << std::endl;
	}
	else if (_type == INT)
	{
		std::cout << "int: " << static_cast<int>(_value) << std::endl;
	}
	else if (_type == FLOAT)
	{
		std::cout << "int: " << static_cast<int>(_value) << std::endl;
	}
	else if (_type == DOUBLE)
	{
		std::cout << "int: " << static_cast<int>(_value) << std::endl;
	}
	else if (_type == PSEUDO)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::printFloat()
{
	float f = static_cast<float>(_value);
	int precision = calculatePrecision(_str);

	std::cout << std::fixed;
	std::cout.precision(precision);
	if (_type == CHAR)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else if (_type == INT)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else if (_type == FLOAT)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else if (_type == DOUBLE)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else if (_type == PSEUDO)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble()
{
	if (_type == CHAR)
		std::cout << "double: " << _value << std::endl;
	else if (_type == INT)
		std::cout << "double: " << _value << std::endl;
	else if (_type == FLOAT)
		std::cout << "double: " << _value << std::endl;
	else if (_type == DOUBLE)
		std::cout << "double: " << _value << std::endl;
	else if (_type == PSEUDO)
		std::cout << "double: " << _value << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/




/* ************************************************************************** */