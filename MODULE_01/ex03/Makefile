NAME = battle

SRC = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CPLUSPLUS = c++
CPLUSPLUSFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJ)
	$(CPLUSPLUS) $(CPLUSPLUSFLAGS) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re