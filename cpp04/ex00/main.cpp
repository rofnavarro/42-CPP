/* "*****************************************************"********************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:36 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/15 17:34:01 by rferrero         ###   ########.fr       */
/*                                                                            */
/* "*****************************************************"********************* */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal	meta;
	std::cout << "*****************************************************" << std::endl;
	Animal			animal;
	std::cout << "*****************************************************" << std::endl;

	const Cat		cat1;
	std::cout << "*****************************************************" << std::endl;
	Cat				cat2;
	std::cout << "*****************************************************" << std::endl;

	const Animal	*ani_dog = new Dog();
	std::cout << "*****************************************************" << std::endl;
	const Animal	*ani_cat = new Cat();
	std::cout << "*****************************************************" << std::endl;
	const Animal	*ani1 = new Dog();
	std::cout << "*****************************************************" << std::endl;

	const Animal	cat5;
	std::cout << "*****************************************************" << std::endl;

	animal = meta;
	std::cout << "*****************************************************" << std::endl;

	cat2 = cat1;
	std::cout << "*****************************************************" << std::endl;

	std::cout << "Meta Animal: " << meta.getType() << std::endl;
	meta.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Animal: " << animal.getType() << std::endl;
	animal.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Cat1: " << cat1.getType() << std::endl;
	cat1.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Cat2: " << cat2.getType() << std::endl;
	cat2.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Animal Dog: " << ani_dog->getType() << std::endl;
	ani_dog->makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Animal Cat: " << ani_cat->getType() << std::endl;
	ani_cat->makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Animal Dog: " << ani1->getType() << std::endl;
	ani1->makeSound();
	std::cout << "*****************************************************" << std::endl;

	delete ani_dog;
	std::cout << "*****************************************************" << std::endl;
	delete ani_cat;
	std::cout << "*****************************************************" << std::endl;
	delete ani1;
	std::cout << "*****************************************************" << std::endl;

	std::cout << "*****************************************************" << std::endl;
	std::cout << "*****************************************************" << std::endl;

	const WrongAnimal	wrong;
	std::cout << "*****************************************************" << std::endl;
	const WrongCat		wrat;
	std::cout << "*****************************************************" << std::endl;
	const WrongAnimal	*w = new WrongAnimal();
	std::cout << "*****************************************************" << std::endl;
	const WrongAnimal	*wcat = new WrongCat();
	std::cout << "*****************************************************" << std::endl;

	std::cout << "Wrong: " << wrong.getType() << std::endl;
	wrong.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "Wrat: " << wrat.getType() << std::endl;
	wrat.makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "W: " << w->getType() << std::endl;
	w->makeSound();
	std::cout << "*****************************************************" << std::endl;
	std::cout << "WCat: " << wcat->getType() << std::endl;
	wcat->makeSound();
	std::cout << "*****************************************************" << std::endl;
	
	delete w;
	std::cout << "*****************************************************" << std::endl;
	delete wcat;
	std::cout << "*****************************************************" << std::endl;

	return (0);
}