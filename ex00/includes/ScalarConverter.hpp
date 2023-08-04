/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:13 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/04 18:51:41 by tpereira         ###   ########.fr       */
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

		void printChar() const;
		void printInt() const;
		void printFloat() const;
};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */