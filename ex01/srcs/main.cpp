/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:32:05 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/11 19:24:09 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data *ptr = new Data();
    Serializer seri;
    uintptr_t num;

    ptr->name = "Cast";
    ptr->value = 42;
    std::cout << "Original Data *ptr:\n";
    std::cout << "ptr->name: " << ptr->name << std::endl;
    std::cout << "ptr->value: " << ptr->value << std::endl;
    num = seri.serialize(ptr);
	std::cout << "\nSerialized Data *ptr:\n";
    std::cout << "ptr->name: " << ptr->name << std::endl;
    std::cout << "ptr->value: " << ptr->value << std::endl;
	ptr = seri.deserialize(num);
	std::cout << "\nDeserialized Data *ptr:\n";
    std::cout << "ptr->name: " << ptr->name << std::endl;
    std::cout << "ptr->value: " << ptr->value << std::endl;

    delete ptr;
    return 0;
}
