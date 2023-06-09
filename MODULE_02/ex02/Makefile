NAME = fixed

SRC = Fixed.cpp main.cpp
OBJ_PATH		= ./objects/

CPLUSPLUS = c++
CPLUSPLUSFLAGS = -Wall -Wextra -Werror -std=c++98
DOCTEST_HEADER = doctest.h

$(OBJ_PATH)%.o: %.cpp
				mkdir -p $(OBJ_PATH)
				$(CPLUSPLUS) $(CPLUSPLUSFLAGS) -c $< -o $@

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
all: $(NAME)

$(NAME): $(OBJ)
	$(CPLUSPLUS) $(CPLUSPLUSFLAGS) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ)
	$(RM) $(DOCTEST_HEADER)
	$(RM) tests
	rm -rf $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

leak:
	valgrind --track-origins=yes --show-leak-kinds=all ./$(NAME)

config-tests:
	@test -f $(DOCTEST_HEADER) || wget https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h

tests: config-tests tests.cpp Fixed.cpp $(DOCTEST_HEADER)
	g++ tests.cpp Fixed.cpp -o tests
	./tests

run:
	./$(NAME)

.PHONY: all clean fclean re leak run config-tests tests