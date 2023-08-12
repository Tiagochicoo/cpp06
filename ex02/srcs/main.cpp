/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:30 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/12 08:59:29 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() 
{
    Base *obj = generate();

    std::cout << "Identifying using Base* pointer:" << std::endl;
    identify(obj);

    std::cout << "Identifying using Base& reference:" << std::endl;
    identify(*obj);

    delete obj;
    
    return 0;
}
