NAME = expert_system
CC = g++

SRC = main.cpp Node.cpp Tree.cpp parser.tab.cpp lex.yy.c
OBJ = $(SRC:.cpp=.o)
CFLAGS = -c -O0 -std=c++11
HEADERS = Node.hpp Tree.hpp parser.tab.hpp

all: $(NAME)

PARSER:
	bison -d parser.ypp
	flex lexer.lex

$(NAME) : PARSER $(OBJ)
	#bison -d parser.ypp
	#flex lexer.lex
	@$(CC) $(OBJ) -lfl -I$(HEADERS) -o $(NAME)
	@echo "\033[0;37mExpertSystem is compiled\033[0m"

%.o : %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -rf $(OBJ)
	@rm -rf parser.tab.cpp
	@rm -rf parser.tab.hpp

fclean: clean
	@rm -rf $(NAME)

re: fclean all