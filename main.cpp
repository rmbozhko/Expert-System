#include <iostream>
#include <assert.h>
#include "Tree.hpp"
#include "parser.tab.hpp"
#include <cstring>

#define ASSERT(expression) assert(expression);
int yyparse (std::vector<ast::Tree*>& treeStrg, std::map<std::string, bool>& factsStrg, std::vector<std::string>& factsOutput);

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
		if (strlen(argv[1]) > 0)
			if ((yyin = fopen(argv[1], "r")))
				if (yyparse(treeStrg, factsStrg, factsOutput))
					cerr << "Parsing failed ..." << endl;
		
		for (int i = 0; i < factsOutput.size(); ++i)
		{
			std::cout << "OUTPUT VALUES: " << factsOutput[i] << std::endl;
		}

		for (std::map<std::string, bool>::iterator i = factsStrg.begin(); i != factsStrg.end(); ++i)
		{
			std::cout << i->first << " " << i->second << std::endl; 
		}

		for (int i = 0; i < treeStrg.size(); ++i)
		{
			ast::Visitor v;
			v.visitDeleteAst(treeStrg[i]->GetRoot());
		}

		std::cout << "Root ID: " << treeStrg[0]->GetRoot()->GetId() << std::endl;
	}
	else
		cerr << "Usage: ./expert_system input_file" << endl;
	return 0;
}