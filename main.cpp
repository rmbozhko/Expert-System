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
		
		for (size_t i = 0; i < factsOutput.size(); ++i) {
			ft_process_fact(factsOutput[i], treeStrg, factsStrg);
		}

		ft_print_dot(treeStrg, factsStrg);

		// displaying resolved values from factsOutput vector
		for (int i = 0; i < factsOutput.size(); ++i) {
			std::cout << factsStrg[factsOutput[i]] << std::endl;
		}
		ft_delete_trees(treeStrg);
	}
	else
		std::cerr << "Usage: ./expert_system [input_file]" << std::endl;
	return 0;
}
