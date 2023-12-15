/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:36 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/15 16:58:34 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*ani_dog = new Dog();
	const Animal	*ani_cat = new Cat();
	const Animal	*ani1;

	const Animal	cat5("Generic");

	Cat		cat1;
	Cat		*cat2;

	
	std::cout << "HERE" << std::endl;

	ani1 = meta;

	cat2 = &cat1;

	std::cout << "HERE"  << std::endl;

	std::cout << "Animal: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "Dog: " << ani_dog->getType() << std::endl;
	ani_dog->makeSound();
	std::cout << "Cat: " << ani_cat->getType() << std::endl;
	ani_cat->makeSound();
	std::cout << "Generic: " << ani1->getType() << std::endl;
	ani1->makeSound();
	std::cout << "Cat: " << cat1.getType() << std::endl;
	cat1.makeSound();
	std::cout << "Cat: " << cat2->getType() << std::endl;
	cat2->makeSound();

	delete meta;
	delete ani_dog;
	delete ani_cat;

	return (0);
}