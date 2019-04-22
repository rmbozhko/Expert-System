#ifndef MAIN_HPP
# define MAIN_HPP

#include "Tree.hpp"
#include "Fact.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "ExprSysEnums.hpp"
#include "parser.tab.hpp"

Node*		ft_evaluate_rpart(Node* node, factValues& value);
factValues	ft_evaluate_lpart( Node * node, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg);
int 		yyparse (std::vector<Tree*>& treeStrg, std::map<std::string, Fact*>& factsStrg, std::vector<std::string>& factsOutput);
void		ft_print_dot(std::vector<Tree*>& treeStrg, std::map<std::string, Fact*> factsStrg);
void		ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg);

#endif