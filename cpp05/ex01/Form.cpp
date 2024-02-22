/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:54:56 by rferrero          #+#    #+#             */
/*   Updated: 2024/02/21 15:58:55 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
:_name("Default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << this->getName() << " form constructor called" << std::endl;
	return ;
}