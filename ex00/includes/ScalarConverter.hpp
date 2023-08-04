/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:13 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/04 19:27:55 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdio>
# include <cctype>
# include <cmath>
# include <cstring>
# include <iomanip>

enum {
	NOT,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

class ScalarConverter
{
	private:
		int _type;
		double _value;
		std::string _str;

	public:

		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);

		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );

		void convert(std::string &str);

		void getType(std::string &str);
		void setType(int type);

		void getValue(std::string &str);
		void setValue(double value);

		int calculatePrecision(std::string &str);

		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */