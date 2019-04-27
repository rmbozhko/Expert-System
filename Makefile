NAME = expert_system
CC = g++

SRC = ./src/ExprSysEnums.cpp ./src/Exceptions.cpp ./src/Node.cpp ./src/Fact.cpp ./src/Operation.cpp ./src/Tree.cpp ./src/backwardChainingAlgo.cpp ./src/LogicOperations.cpp ./src/visual.cpp ./src/parser.cpp lex.yy.c main.cpp 
OBJ = $(SRC:.cpp=.o)
CFLAGS = -c -O0 -std=c++11 -Wc++11-extensions -Wall -Wextra -Werror
HEADERS = ./src/Node.hpp ./src/Fact.hpp ./src/Operation.hpp ./src/LogicOperations.hpp ./src/Tree.hpp ./src/parser.hpp ./src/misc.hpp ./src/Exceptions.hpp ./src/ExprSysEnums.hpp 

all: $(NAME)

PARSER:
	@bison -d parser.ypp -o src/parser.cpp
	@flex lexer.lex

$(NAME) : PARSER $(OBJ) $(HEADERS)
	@rm -rf rules
	@mkdir rules
	@$(CC) $(OBJ) -ll -o $(NAME)
	@echo "\033[0;36m$(NAME) is compiled\033[0m"

./src/%.o : %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -f $(OBJ)
	@rm -f lex.yy.c 
	@rm -f ./src/parser.cpp
	@rm -f ./src/parser.hpp
	@rm -f rules/rule*.dot
	@rm -rf rules

fclean: clean
	@rm -rf $(NAME)

re: fclean all
