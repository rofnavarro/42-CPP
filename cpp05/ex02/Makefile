NAME					=					form

CC						=					c++

CCFLAGS					=					-Wall -Wextra -Werror -Wshadow
STDFLAG					=					-std=c++98

SRC						=					main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
											RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ						=					$(SRC:.cpp=.o)

%.o:					%.cpp
						$(CC) $(CCFLAGS) $(STDFLAG) -c $< -o $@

all:					$(NAME)

$(NAME):				$(OBJ)
						$(CC) $(CCFLAGS) $(STDFLAG) $(OBJ) -o $(NAME)

clean:
						rm -rf $(OBJ)

fclean:					clean
						rm -rf $(NAME)

re:						fclean all

.PHONY:					all celan fclean re