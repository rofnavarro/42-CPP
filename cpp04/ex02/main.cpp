/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:55:50 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 15:37:28 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	
	delete dog;
	delete cat;

	std::cout << "___________________________________________\n" << std::endl;

	AAnimal	*arr[10];

	for (int i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (int i = 5; i < 10; i++)
		arr[i] = new Cat();

	std::cout << "Now deleting!" << std::endl;

	for(int i = 0; i < 10; i++)
   		delete arr[i];
	
	std::cout << "___________________________________________\n" << std::endl;
	
	Cat myCat;
	myCat.setIdea("LASAGNA!");
	Cat yourCat;
	
	yourCat = myCat;
	std::cout << "My cat: " << myCat.getIdea(0) << std::endl;
	std::cout << "Your cat: " << yourCat.getIdea(0) << std::endl;
	yourCat.setIdea("Cows shouldn't fly");
	std::cout << "Your cat: " << yourCat.getIdea(0) << std::endl;
	std::cout << "My cat: " << myCat.getIdea(0) << std::endl;

	Dog myDog;
	Dog yourDog;
	
	yourDog = myDog;
	
	yourDog.setIdea("Auuuuu");
	std::cout << "My Dog: " << myDog.getIdea(0) << std::endl;
	std::cout << "Your Dog: " << yourDog.getIdea(0) << std::endl;
	
	return (0);
}