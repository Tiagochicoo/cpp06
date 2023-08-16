/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:30 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/16 19:06:13 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() 
{
	Base *obj = generate();

	std::cout << "Identifying using Base* pointer: ";
	identify(obj);
	std::cout << std::endl;

	std::cout << "Identifying using Base& reference: ";
	identify(*obj);
	std::cout << std::endl;

	delete obj;
	
	return 0;
}
