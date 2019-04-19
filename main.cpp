#include <iostream>
#include "Tree.hpp"
#include "parser.tab.hpp"
#include <cstring>
#include <fstream>
#include <vector>
#include "main.hpp"

int main(int argc, char const *argv[])
{
	extern FILE*							yyin;
	std::vector<ExprSys::Tree*>				treeStrg;
	std::map<std::string, ExprSys::Fact*>	factsStrg;
	std::vector<std::string> 				factsOutput;

	if (argc == 2 && strlen(argv[1]) > 0) {
		yyin = fopen(argv[1], "r");
		if (yyin) {
			try {
				if (yyparse(treeStrg, factsStrg, factsOutput)) {
					std::cerr << "Parsing failed ..." << std::endl;
					return (1);
				}
			} catch (SyntaxException& e) {
				std::err << e.what() << std::endl;
			}
		}
		else {
			std::cerr << "Provided file couldn't be opened" << std::endl;
			return (1);
		}
		
		for (size_t i = 0; i < factsOutput.size(); ++i) {
			try {
				ExprSys::ft_print_dot(treeStrg, factsStrg);
				ExprSys::ft_process_fact(factsOutput[i], treeStrg, factsStrg);
			} catch (RuleContradictionException& e) {
				std::err << e.what() << std::endl;
			}
		}
	}
	else
		cerr << "Usage: ./expert_system [input_file]" << endl;
	return 0;
}