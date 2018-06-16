#include <iostream>
#include <libft.h>
#include <assert.h>

#define ASSERT(expression) assert(expression);

int main(int argc, char const *argv[])
{
	using		std::cerr;
	using		std::cout;
	using		std::endl;

	std::vector<ast::Tree> 			treeStrg;
	std::map<std::string, bool>		factsStrg;
	std::vector<std::string> 		factsOutput;

	if (argc > 1)
	{
		if (ft_strlen(argv[1]))
			if (yyin = fopen(argv[1], "r"))
				if (yyparse(treeStrg, factsStrg, factsOutput))
					cerr << "Parsing failed ..." << endl;
	}
	else
		cerr << "Usage: ./expert_system input_file" << endl;
	return 0;
}