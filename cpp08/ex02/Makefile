NAME					=					mutantstack

CC						=					c++

CCFLAGS					=					-Wall -Werror -Wextra -Wshadow
STDFLAG					=					-std=c++98

SRC						=					main.cpp

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

.PHONY:					all clean fclean re