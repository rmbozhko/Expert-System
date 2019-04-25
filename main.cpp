#include "src/misc.hpp"
#include "parser.tab.hpp"
#include <iostream>
#include <cstring>
#include "src/Fact.hpp"

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
		
		ft_print_dot(treeStrg, factsStrg);
		
		for (size_t i = 0; i < factsOutput.size(); ++i) {
			ft_process_fact(factsOutput[i], treeStrg, factsStrg);
		}

		// displaying resolved values from factsOutput vector
		for (int i = 0; i < factsOutput.size(); ++i) {
			std::cout << factsStrg[factsOutput[i]] << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./expert_system [input_file]" << std::endl;
	return 0;
}
