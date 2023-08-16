/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 08:41:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/08/16 19:06:55 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base Destructor Called" << std::endl;
}

Base *generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C";
    }
}

void identify(Base& p) {
    identify(&p);
}
