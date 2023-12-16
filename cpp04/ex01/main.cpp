/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:55:50 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 15:36:26 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	std::cout << "********************************************************" << std::endl;

	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	
	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
	
	std::cout << "********************************************************" << std::endl;

	Cat				cat;
	Cat				other_cat;

	Cat				ref_cat;
	
	ref_cat = cat;

	cat.setIdea("Hmmmmmm Milk!");

	other_cat = cat;

	std::cout << "HERE" << std::endl;
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << other_cat.getIdea(0) << std::endl;

	ref_cat.setIdea("This looks like a great spot to hide!");

	std::cout << "HERE" << std::endl;
	std::cout << ref_cat.getIdea(0) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << ref_cat.getIdea(1) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << cat.getIdea(1) << std::endl;

	std::cout << "********************************************************" << std::endl;

	Dog				dog;
	Dog				other_dog;

	Dog				ref_dog;
	
	ref_dog = dog;

	dog.setIdea("Where is my toy?");

	other_dog = dog;

	std::cout << "HERE" << std::endl;
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << other_dog.getIdea(0) << std::endl;

	ref_dog.setIdea("I can eat that!!");

	std::cout << "HERE" << std::endl;
	std::cout << ref_dog.getIdea(0) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << ref_dog.getIdea(1) << std::endl;
	std::cout << "HERE" << std::endl;
	std::cout << dog.getIdea(1) << std::endl;

	std::cout << "********************************************************" << std::endl;

	return (0);
}