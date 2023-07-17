/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:13 by tpereira          #+#    #+#             */
/*   Updated: 2023/07/17 22:08:28 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdio>
# include <cctype>
# include <cmath>
# include <cstring>

class ScalarConverter
{
	private:

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );

		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );

		// convert methods that take a string and convert it to the other types
		// int, float, double and char
		char					convertToChar(const char* str);
		int						convertToInt(const char* str);
		float					convertToFloat(const char* str);
		double					convertToDouble(const char* str);

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */