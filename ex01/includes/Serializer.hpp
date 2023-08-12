/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:31:55 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/12 08:12:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
 #include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:

	public:

		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);

};

std::ostream &			operator<<( std::ostream & o, Serializer const & i );

#endif /* ****************************************************** SERIALIZER_H */
