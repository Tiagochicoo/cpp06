/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:13 by tpereira          #+#    #+#             */
/*   Updated: 2023/07/11 00:12:10 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

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
		char					convertToChar(std::string str);
		int						convertToInt(std::string str);
		float					convertToFloat(std::string str);
		double					convertToDouble(std::string str);

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */