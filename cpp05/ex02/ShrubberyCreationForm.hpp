#pragma	once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
public:
							ShrubberyCreationForm(void);
							ShrubberyCreationForm(std::string target);
							ShrubberyCreationForm(const ShrubberyCreationForm &shrbberycreationform);

							~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);

	void					execute(Bureaucrat const &executor) const;

};

#endif