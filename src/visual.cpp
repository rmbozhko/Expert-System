#include "Node.hpp"
#include <string>
#include "Fact.hpp"
#include <map>
#include <vector>
#include "Tree.hpp"
#include <fstream>
#include "ExprSysEnums.hpp"
#include <iostream>

static void		ft_parse_rule(Node* rule, std::string& result, std::map<std::string, Fact*> factsStrg)
{
	if (rule->GetType() == nodeType::operation_t)
	{
		Operation*	oper = dynamic_cast<Operation*>(rule);

		result += std::to_string(oper->GetId()) + " [ shape=box, label=\"" + oper->GetLabel() + "\"]\n";
		result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(0)->GetId()) + ";\n";
		std::cout << "Makarena" << oper->GetLabel() << std::endl;
		if (oper->GetChild(1) != nullptr) // for binary operations(+, |)
		{
			result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(1)->GetId()) + ";\n";
			std::cout << "Makarena11" << oper->GetChild(0)->GetKey() << std::endl;
			ft_parse_rule(oper->GetChild(0), result, factsStrg);
			std::cout << "Makarena12" << std::endl;
			ft_parse_rule(oper->GetChild(1), result, factsStrg);
		}
		else // for unary operations(!)
		{
			std::cout << "Makarena2" << std::endl;
			ft_parse_rule(oper->GetChild(0), result, factsStrg);
		}
	}
	else
	{
		Fact*	fact = dynamic_cast<Fact*>(rule);

		result += std::to_string(fact->GetId()) + " [ label=\"Fact: " + fact->GetKey() + "\\nValue: ";
		if (fact->GetValue() == factValues::False)
			result += "False\", color=\"red\"]\n";
		else if (fact->GetValue() == factValues::True)
			result += "True\", color=\"green\"]\n";
		else if (fact->GetValue() == factValues::Undetermined)
			result += "Undetermined\", color=\"blue\"]\n";
		else
			result += "Processing\", color=\"black\"]\n";
	}
}

void			ft_print_dot(std::vector<Tree*>& treeStrg, std::map<std::string, Fact*> factsStrg)
{
	static size_t		status_num = 0;
	std::string			filename = "rules/status_" + std::to_string(status_num++) + ".dot";
	std::ofstream		file(filename);
	std::string			result = "digraph a {\n";

	if (!file.is_open()) {
		std::cerr << "Fail while working with a file." << std::endl;
		exit(-1);
	}
	
	std::cout << "YO" << std::endl;
	for (size_t i = 0; i < treeStrg.size(); ++i) {
		std::cout << "YO" << i << std::endl;
		result += "Root -> " + std::to_string(treeStrg[i]->GetRoot()->GetId()) + ";\n";
		ft_parse_rule(treeStrg[i]->GetRoot(), result, factsStrg);
	}

	std::cout << "YO" << std::endl;
	file << result;
	file << "}\n";
	file.close();
}
