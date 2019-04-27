#ifndef __MISC_HPP__
#define __MISC_HPP__

#include "Node.hpp"
#include "Fact.hpp"
#include "Tree.hpp"
#include "ExprSysEnums.hpp"
#include <map>
#include <string>
#include <vector>


Node*		ft_evaluate_rpart(Node* node, factValues value, bool isFalseMode);
Node*		ft_evaluate_rpart(Node* node, factValues value);
int 		yyparse (std::vector<Tree*>& treeStrg, std::map<std::string, Fact*>& factsStrg, std::vector<std::string>& factsOutput);
void 		yyrestart (FILE *input_file);
void		ft_print_dot(std::vector<Tree*>& treeStrg, std::map<std::string, Fact*> factsStrg);
void		ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact*> factsStrg);

#endif // __MISC_HPP__
