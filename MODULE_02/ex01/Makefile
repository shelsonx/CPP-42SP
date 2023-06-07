NAME = fixed

SRC = Fixed.cpp main.cpp
OBJ_PATH		= ./objects/

CPLUSPLUS = c++
CPLUSPLUSFLAGS = -Wall -Wextra -Werror -std=c++98

$(OBJ_PATH)%.o: %.cpp
				mkdir -p $(OBJ_PATH)
				$(CPLUSPLUS) $(CPLUSPLUSFLAGS) -c $< -o $@

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
all: $(NAME)

$(NAME): $(OBJ)
	$(CPLUSPLUS) $(CPLUSPLUSFLAGS) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

leak:
	valgrind --track-origins=yes --show-leak-kinds=all ./$(NAME)

run:
	./$(NAME)

.PHONY: all clean fclean re leak run