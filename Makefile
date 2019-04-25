NAME = expert_system
CC = g++

SRC = ExprSysEnums.cpp Exceptions.cpp Node.cpp Fact.cpp Operation.cpp Tree.cpp backwardChainingAlgo.cpp LogicOperations.cpp visual.cpp parser.tab.cpp lex.yy.c main.cpp 
OBJ = $(SRC:.cpp=.o)
CFLAGS = -c -O0 -std=c++11 #-Wall -Wextra -Werror
HEADERS = Node.hpp Fact.hpp Operation.hpp LogicOperations.hpp Tree.hpp parser.tab.hpp main.hpp Exceptions.hpp ExprSysEnums.hpp 

all: $(NAME)

PARSER:
	@bison -d -t parser.ypp
	@flex lexer.lex

$(NAME) : PARSER $(OBJ) $(HEADERS)
	@mkdir rules
	@$(CC) $(OBJ) -ll -o $(NAME)
	@echo "\033[0;36m$(NAME) is compiled\033[0m"

%.o : %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -f $(OBJ)
	@rm -rf parser.tab.cpp
	@rm -rf parser.tab.hpp
	@rm -f rules/rule*.dot
	@rm -rf rules

fclean: clean
	@rm -rf $(NAME)

re: fclean all
