#pragma	once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
public:
							RobotomyRequestForm(void);
							RobotomyRequestForm(std::string target);
							RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);

							~RobotomyRequestForm(void);

	RobotomyRequestForm		&operator=(const RobotomyRequestForm &rhs);

	void					execute(Bureaucrat const &executor) const;

};

#endif