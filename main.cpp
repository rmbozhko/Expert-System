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

factValues		ft_evaluate(size_t i, std::vector<ExpSys::Tree*> treeStrg)
{
	Operation*		rule;

	rule = treeStrg[i]->GetRoot()->GetChild(0); // rule to resolve
	if (rule->GetType() == ExpSys::nodeType::Operation)
	{
		factValues lchild = ft_evaluate(rule->GetChild(0));
		factValues rchild = ft_evaluate(rule->GetChild(1));
		return (rule->Evaluate(lchild, rchild));
	}
	else
	{
		// handle as fact
		ft_process_fact(rule->GetKey());
		return (rule->GetValue());
	}
}

void			ft_process_fact(const std::string& fact, std::vector<ExpSys::Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg)
{
	Fact const*				fact_ptr = factsStrg[fact];
	std::vector<size_t> 	facts_rules;

	// gather rules with fact in right side of expression
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		Tree*	tree = treeStrg[i];
		if (tree->GetRoot()->GetChild(0)->GetKey() == fact_ptr->GetKey()
			|| tree->GetRoot()->GetChild(1)->GetKey() == fact_ptr->GetKey())
			facts_rules.push_back(i);
	}

	for (size_t i = 0; i <= facts_rules.size(); ++i)
	{
		if (fact_ptr->GetValue() == factValues::Undetermined)
		{
			if (!facts_rules.size())
				fact_ptr->SetValue(factValues::False);
			else
			{
				factValues	result = ft_evaluate();
				fact_ptr->SetValue(result);
			}
			// resolve rules and find value for a fact
		}
		else
		{
			if (!facts_rules.size())
				return ;
			factValues	result = ft_evaluate(i, treeStrg)
			if (result != fact_ptr->GetValue())
			{
				// throw exception, that some rules are conflicting
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	extern FILE*	yyin;

	using		std::cerr;
	using		std::cout;
	using		std::endl;

	std::vector<ExpSys::Tree*>			treeStrg;
	std::map<std::string, Fact const*>	factsStrg;
	std::vector<std::string> 			factsOutput;

	if (argc > 1)
	{
		if (strlen(argv[1]) > 0)
			if ((yyin = fopen(argv[1], "r")))
				if (yyparse(treeStrg, factsStrg, factsOutput))
					cerr << "Parsing failed ..." << endl;
		
		for (size_t i = 0; i < factsOutput.size(); ++i)
		{
			ft_print_dot(treeStrg, factsStrg);
			ft_process_fact(treeStrg, factsStrg, factsOutput[i]);
		}

		
		std::cout << "Number pf rules: " << treeStrg.size() << std::endl;

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

bool		findFact( const std::string &fact, std::map<std::string, bool> factsStrg )
{
	for (std::map<std::string, bool>::iterator i = factsStrg.begin(); i != factsStrg.end(); ++i)
		if (i->first == fact)
			return (true);

	return (false);
}

for (size_t i = 0; i < factsOutput[i]; ++i)
 {
 	if ( findFact(factsOutput[i], factsStrg) )
 	{
 		// check the correctness of other rules, where factsOutput[i] is in conclusion
 	}
 	else
 	{
 		
 	}
 }