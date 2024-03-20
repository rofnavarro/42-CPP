#pragma	once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
public:
							PresidentialPardonForm(void);
							PresidentialPardonForm(std::string target);
							PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);

							~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);

	void					beSigned(Bureaucrat &bureaucrat) const;
	void					execute(Bureaucrat const &executor) const;

};

#endif