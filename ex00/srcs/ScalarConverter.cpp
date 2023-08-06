/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:18 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/06 15:14:39 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
	// std::cout << "Default constructor called" << std::endl;	
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
	// std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor called" << std::endl;
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
	{
		if (isprint(str[0]))
			setType(CHAR);
		else
			setType(NOT);
	}
	else if (str == "nan" || str == "nanf")
		setType(PSEUDO);
	else if (str == "inf" || str == "inff")
		setType(PSEUDO);
	else if (str == "-inf" || str == "-inff")
		setType(PSEUDO);
	else if (str == "+inf" || str == "+inff")
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
	bool hasF = str.find('f') != std::string::npos;
	if (hasF)
		str.erase(str.find('f'));
	return (decimalPoint != std::string::npos) ? (str.length() - decimalPoint - 1) : 0;
}

void ScalarConverter::getValue(std::string &str)
{
	if (_type == CHAR)
	{
		setValue(static_cast<double>(str[0]));
	}
	else if (_type == INT || _type == DOUBLE)
	{
		std::istringstream stream(_str);
		stream >> _value;
	}
	else if (_type == FLOAT)
	{
		setValue(static_cast<double>(atof(str.c_str())));
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
	char c = static_cast<char>(_value);
	if (_type == CHAR)
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else if (_type == INT || _type == DOUBLE || _type == FLOAT)
	{
		if (_value >= 32 && _value <= 127)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::printInt()
{
	int i = static_cast<int>(_value);
	if (_type == NOT || _type == PSEUDO)
		std::cout << "int: impossible" << std::endl;
	else if (_value > INT_MAX || _value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;	
}

void ScalarConverter::printFloat()
{
	float f = static_cast<float>(_value);
	int precision = calculatePrecision(_str);

	std::cout << std::fixed;
	std::cout.precision(precision);
	if (_type == CHAR || _type == INT)
		std::cout << "float: " << f << ".0f" << std::endl;
	else if (_type == FLOAT || _type == DOUBLE || _type == PSEUDO)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble()
{
    switch (_type)
    {
    case CHAR:
        std::cout << "double: " << _value << std::endl;
        break;
    case INT:
        std::cout << "double: " << _value << ".0" << std::endl;
        break;
    case FLOAT:
        std::cout << "double: " << _value << std::endl;
        break;
    case DOUBLE:
        std::cout << "double: " << _value << std::endl;
        break;
    case PSEUDO:
        std::cout << "double: " << _value << std::endl;
        break;
    default:
        std::cout << "double: impossible" << std::endl;
        break;
    }
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/




/* ************************************************************************** */
