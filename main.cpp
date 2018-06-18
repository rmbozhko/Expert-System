#include <iostream>
#include <assert.h>
#include "system.hpp"
#include "parser.tab.hpp"
#include <cstdio>

#define ASSERT(expression) assert(expression);

int main(int argc, char const *argv[])
{
	extern FILE*	yyin;

	using		std::cerr;
	using		std::cout;
	using		std::endl;

	std::vector<ast::Tree*>			treeStrg;
	std::map<std::string, bool>		factsStrg;
	std::vector<std::string> 		factsOutput;

	if (argc > 1)
	{
		// if (strlen(argv[1]))
		if (yyin = fopen(argv[1], "r"))
			if (yyparse(treeStrg, factsStrg, factsOutput))
				cerr << "Parsing failed ..." << endl;
	}
	else
		cerr << "Usage: ./expert_system input_file" << endl;
	for (int i = 0; i < factsOutput.size(); ++i)
	{
		std::cout << "OUTPUT VALUES: " << factsOutput[i] << std::endl;
	}
	for (std::map<std::string, bool>::iterator i = factsStrg.begin(); i != factsStrg.end(); ++i)
	{
		std::cout << i->first << " " << i->second << std::endl; 
	}
	std::cout << "Root ID: " << treeStrg[0]->GetRoot().GetId() << std::endl;
	return 0;
}