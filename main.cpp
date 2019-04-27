#include "src/misc.hpp"
#include "parser.tab.hpp"
#include <iostream>
#include <cstring>
#include "src/Fact.hpp"

void		ft_delete_trees(std::vector<Tree*>& treeStrg)
{
	for (size_t i = 0; i < treeStrg.size(); ++i) {
		treeStrg[i]->DeleteNodes(treeStrg[i]->GetRoot());
		delete treeStrg[i];
	}
}

void		ft_delete_facts(std::map<std::string, Fact*> factsStrg)
{	for (auto& factCell : factsStrg) {
		delete factCell.second;
	}
}

int main(int argc, char const *argv[])
{
	extern FILE*							yyin;
	std::vector<Tree*>				treeStrg;
	std::map<std::string, Fact*>	factsStrg;
	std::vector<std::string> 				factsOutput;

	if (argc == 2 && std::strlen(argv[1]) > 0) {
		yyin = fopen(argv[1], "r");
		if (yyin) {
			try {
				if (yyparse(treeStrg, factsStrg, factsOutput)) {
					std::cerr << "Parsing failed ..." << std::endl;
					return (1);
				}
			} catch (SyntaxException& e) {
				std::cerr << e.what_exception() << std::endl;
				return (1);
			}
		}
		else {
			std::cerr << "Provided file couldn't be opened" << std::endl;
			return (1);
		}
		try {
			// processing facts
			for (size_t i = 0; i < factsOutput.size(); ++i) {
				ft_print_dot(treeStrg, factsStrg);
				ft_process_fact(factsOutput[i], treeStrg, factsStrg);
			}
			// displaying processed facts
			for (int i = 0; i < factsOutput.size(); ++i) {
				std::cout << factsStrg[factsOutput[i]] << std::endl;
			}
		} catch (RuleContradictionException& e) {
			std::cerr << e.what_exception() << std::endl;
		} catch (NotImplementedException& e) {
			std::cerr << e.what_exception() << std::endl;
		} catch (RuleEvaluatingException& e) {
			std::cerr << e.what_exception() << std::endl;
		}
		
		ft_delete_trees(treeStrg);
		ft_delete_facts(factsStrg);
	}
	else
		std::cerr << "Usage: ./expert_system [input_file]" << std::endl;
	return 0;
}
