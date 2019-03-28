#include <iostream>
#include <assert.h>
#include "Tree.hpp"
#include "parser.tab.hpp"
#include <cstring>
#include <fstream>

#define ASSERT(expression) assert(expression);
int yyparse (std::vector<ExpSys::Tree*>& treeStrg, std::map<std::string, bool>& factsStrg, std::vector<std::string>& factsOutput);

void		ft_parse_rule(const ExpSys::Node* rule, std::string& result, std::map<std::string, Fact const*> factsStrg)
{
	if (rule->GetType() == ExpSys::nodeType::Operation)
	{
		ExpSys::Operation*	oper = dynamic_cast<ExpSys::Operation*>(rule);

		result += std::to_string(oper->GetId()) + " [ shape=box, label=\"" + oper->GetOperLabel() + "\"]\n";
		result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(0)->GetId()) + ";\n";
		if (oper->GetChild(1) != nullptr) // for binary operations(+, |)
		{
			result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(1)->GetId()) + ";\n";
			ft_parse_rule(oper->GetChild(0), result, factsStrg);
			ft_parse_rule(oper->GetChild(1), result, factsStrg);
		}
		else // for unary operations(!)
			ft_parse_rule(oper->GetChild(0), result, factsStrg);	
	}
	else
	{
		Fact const*	fact = dynamic_cast<ExpSys::Fact const*>(rule);

		result += std::to_string(fact->GetId()) + " [ label=\"Fact: " + fact->GetKey() + "\nValue: \"";
		if (fact->GetValue() == factValues::False)
			result += "False\", color=\"red\"]\n";
		else if (fact->GetValue() == factValues::True)
			result += "True\", color=\"green\"]\n";
		else
			result += "Undetermined\", color=\"blue\"]\n";
	}
}

void			ft_print_dot(std::vector<ast::Tree*>& treeStrg, std::map<std::string, bool> factsStrg)
{
	static size_t		status_num = 0;
	std::string			filename = "rules/status_" + std::to_string(status_num++) + ".dot";
	std::ofstream		file(filename);
	std::string			result = "digraph a {\n";

	if (!file.is_open())
	{
		std::cerr << "Fail while working with a file." << std::endl;
		exit(-1);
	}
	
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		result += "Root -> " + std::to_string(treeStrg[i]->GetRoot()->GetId()) + ";\n";
		ft_parse_rule(treeStrg[i]->GetRoot(), result, factsStrg);
		file << result;
		file << "}\n";
	}
	file.close();
}

std::vector<const size_t>			ft_gather_rules(Fact const* fact_ptr)
{
	std::vector<const size_t> 	facts_rules;

	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		Tree*	tree = treeStrg[i];
		if (tree->GetRoot()->GetChild(1)->GetType() == ExpSys::nodeType::Operation)
		{
			if ( fact_ptr == tree->GetRoot()->GetChild(1)->GetChild(0)->GetKey() )
				facts_rules.push_back(i);
			else if ( tree->GetRoot()->GetChild(1)->GetChild(1) && fact_ptr == tree->GetRoot()->GetChild(1)->GetChild(1)->GetKey() )
		}
		else if ( fact_ptr == tree->GetRoot()->GetChild(1)->GetKey() )
			facts_rules.push_back(i);
	}

	return (facts_rules);
}

factValues		ft_evaluate(const Node const* node, std::vector<ExpSys::Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg)
{	
	if (node->GetType() == ExpSys::nodeType::Operation)
	{
		const Operation const*	oper = dynamic_cast<const ExpSys::Operation const*>(node);

		if (oper->GetChild(1))
			return ( oper->Evaluate(ft_evaluate(oper->GetChild(0)), ft_evaluate(oper->GetChild(1))) );
		else
			return ( oper->Evaluate(ft_evaluate(oper->GetChild(0))) );
	}
	else
	{
		Fact const* fact = dynamic_cast<Fact const*>(node)

		ft_process_fact(fact->GetKey(), treeStrg, factsStrg);
		return (fact->GetValue());
	}
}


void			ft_process_fact(const std::string& fact, std::vector<ExpSys::Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg)
{
	Fact const*					fact_ptr = factsStrg[fact]; // what if unexisting fact will be asked
	const std::vector<size_t> 	facts_rules = ft_gather_rules(fact_ptr); // gather rules with fact in right side of expression

	for (size_t i = 0; i <= facts_rules.size(); ++i)
	{
		if (fact_ptr->GetValue() == factValues::Undetermined)
		{
			if (!facts_rules.size())
				fact_ptr->SetValue(factValues::False);
			else
			{
				fact_ptr->SetValue(ExpSys::nodeType::Processing);
				treeStrg[i]->GetRoot()->Evaluate( ft_evaluate(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg), treeStrg[i]->GetRoot()->GetChild(1) );
			}
		}
		else
		{
			if (!facts_rules.size())
				return ;
			else
			{
				treeStrg[i]->GetRoot()->Evaluate( ft_evaluate(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
													ft_evaluate(treeStrg[i]->GetRoot()->GetChild(1), treeStrg, factsStrg) );
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
			ft_process_fact(factsOutput[i], treeStrg, factsStrg);
		}

		
		std::cout << "Number pf rules: " << treeStrg.size() << std::endl;

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