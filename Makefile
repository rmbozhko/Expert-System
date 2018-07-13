NAME = expert_system
CC = g++

SRC = main.cpp Node.cpp Tree.cpp parser.tab.cpp lex.yy.c
OBJ = $(SRC:.cpp=.o)
CFLAGS = -c -O0 -std=c++11# -Wall -Wextra -Werror
HEADERS = Node.hpp Tree.hpp parser.tab.hpp

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
	@rm -rf $(OBJ)
	@rm -rf parser.tab.cpp
	@rm -rf parser.tab.hpp
	@rm -f rules/rule*.dot
	@rm -rf rules

fclean: clean
	@rm -rf $(NAME)

re: fclean all