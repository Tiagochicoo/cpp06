/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:31:22 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/12 08:13:02 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer & src )
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	(void)rhs;
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Serializer const & i )
{
	(void)i;
	// o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serialized;

	serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
