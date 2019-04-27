### Required libraries:
```
1. bison 3.0.4
2. flex 2.6.1
```

### Compiler version:
```
g++ 6.3.0
```

### Makefile instructions:
```
make -- regular compilation
make re -- recompile project
make fclean -- clean *.o and expert_system exec
```

### Bulding instructions:
```
Using bison we should convert parser.ypp to .cpp file:
    bison -d parser.ypp
Using flex we should convert lexer.lex to .c file:
    flex -l lexer.lex
We should compile all files of the project(*.cpp, *.c) with -std=c++11 flag and link them together to expert_system exec. Also, we should specify flex library with -l or -L flags.
```