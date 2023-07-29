/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:10:13 by tpereira          #+#    #+#             */
/*   Updated: 2023/07/29 22:15:32 by tpereira         ###   ########.fr       */
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

		char					convertToChar(std::string str);
		int						convertToInt(std::string str);
		float					convertToFloat(std::string str);
		double					convertToDouble(std::string str);

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */