#ifndef __MISC_HPP__
#define __MISC_HPP__

#include "Node.hpp"
#include "Fact.hpp"
#include "Tree.hpp"
#include "ExprSysEnums.hpp"
#include <map>
#include <string>
#include <vector>

factValues	ft_evaluate_lpart( Node * node, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg);
int 		yyparse (std::vector<Tree*>& treeStrg, std::map<std::string, Fact*>& factsStrg, std::vector<std::string>& factsOutput);
void		ft_print_dot(std::vector<Tree*>& treeStrg, std::map<std::string, Fact*> factsStrg);
void		ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact*> factsStrg);

#endif // __MISC_HPP__
