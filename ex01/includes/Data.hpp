/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:31:40 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/11 18:54:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	private:

	public:

		Data();
		Data(Data const & src);
		~Data();

		Data &		operator=( Data const & rhs );

		int value;
		std::string name;
};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ****************************************************** DATA_H */