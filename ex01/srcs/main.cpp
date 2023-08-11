/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:32:05 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/11 18:59:32 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data *ptr = new Data;
    Serializer seri;
    uintptr_t num;

    ptr->name = "test";
    ptr->value = 42;
    std::cout << "Data *ptr:\n\n";
    std::cout << "ptr->name " << ptr->name << std::endl;
    std::cout << "ptr->value " << ptr->value << std::endl;
    num = seri.serialize(ptr);
    std::cout << num << std::endl;
    std::cout << ptr << std::endl;

    delete ptr;
    return 0;
}
