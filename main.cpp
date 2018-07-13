#include <iostream>
#include <assert.h>
#include "Tree.hpp"
#include "parser.tab.hpp"
#include <cstring>
#include <fstream>

#define ASSERT(expression) assert(expression);
int yyparse (std::vector<ast::Tree*>& treeStrg, std::map<std::string, bool>& factsStrg, std::vector<std::string>& factsOutput);

void		ft_parse_rule(const ast::Node* rule, std::string& result, std::map<std::string, bool> factsStrg)
{
	if (rule->GetValuePair().first == "oper")
	{
		if (rule->GetChildren().size() > 2)
		{
			std::cerr << "Wrong number of operation operands" << std::endl;
			exit(-1);
		}
		ast::Visitor		v;
		result += std::to_string(rule->GetId()) + " [ shape=box, label=\"" + rule->GetValuePair().second + "\", color=\"";
		result += (ast::Visitor::evaluate_expr( rule->GetValuePair().second,
											v.visitAst(rule->GetChildren().at(0), factsStrg),
											(rule->GetChildren().size() == 2) ? 
												v.visitAst(rule->GetChildren().at(1), factsStrg) : false
											)) ? "green" : "red";
		result += "\"]\n";
		result += std::to_string(rule->GetId()) + " -> " + std::to_string(rule->GetChildren().at(0)->GetId()) + ";\n";
		if (rule->GetChildren().size() == 2) // for binary operations(+, |)
		{
			result += std::to_string(rule->GetId()) + " -> " + std::to_string(rule->GetChildren().at(1)->GetId()) + ";\n";
			ft_parse_rule(rule->GetChildren().at(0), result, factsStrg);
			ft_parse_rule(rule->GetChildren().at(1), result, factsStrg);
		}
		else // for unary operations(!)
			ft_parse_rule(rule->GetChildren().at(0), result, factsStrg);	
	}
	else
	{
		auto fact_value = factsStrg.find(rule->GetValuePair().second);
		if ( fact_value  == factsStrg.end() )
			std::cerr << "Unknown fact" << std::endl;
		else
			result += std::to_string(rule->GetId()) + " [ label=\"Fact: "
						+ rule->GetValuePair().second + "\nValue: "
						+ ((fact_value->second) ? "True" : "False") + "\", color=\"" + ((fact_value->second) ? "green" : "red") + "\"]\n";
	}
}

void			ft_print_dot(std::vector<ast::Tree*>& treeStrg, std::map<std::string, bool> factsStrg)
{
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		std::string			filename = "rules/rule" + std::to_string(i) + ".dot";
		std::ofstream		file(filename);
		std::string		result = "digraph a {\n";

		if (!file.is_open())
		{
			std::cerr << "Fail while working with a file." << std::endl;
			exit(-1);
		}
		else
		{
			ft_parse_rule(treeStrg[i]->GetRoot(), result, factsStrg);
			file << result;
		}
		file << "}\n";
		file.close();
	}
}

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
		
		for (size_t i = 0; i < factsOutput.size(); ++i)
		{
			std::cout << "OUTPUT VALUES: " << factsOutput[i] << std::endl;
		}

		for (std::map<std::string, bool>::iterator i = factsStrg.begin(); i != factsStrg.end(); ++i)
		{
			std::cout << i->first << " " << i->second << std::endl; 
		}
		std::cout << "Number pf rules: " << treeStrg.size() << std::endl;
		ft_print_dot(treeStrg, factsStrg);

		for (size_t i = 0; i < treeStrg.size(); ++i)
		{
			ast::Visitor v;
			v.visitDeleteAst(treeStrg[i]->GetRoot());
		}

		std::cout << "rule->D: " << treeStrg[0]->GetRoot()->GetId() << std::endl;
	}
	else
		cerr << "Usage: ./expert_system [input_file]" << endl;
	return 0;
}