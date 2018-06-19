#include "Tree.hpp"

using namespace ast;

bool		Visitor::visitAst(const ast::Node* root, std::map<std::string, bool>& factsStrg)
{
	bool	result;
	
	if (root->GetValuePair().first == "oper")
	{
		if (root->GetChildren().size() > 2)
			std::cerr << "Wrong number of operation operands" << std::endl;
		// visit both operands
		std::cout << "Operation: " << root->GetValuePair().second << " ---- " << root->GetId() << std::endl;
		if (root->GetChildren().size() == 2) // for binary operations(+, |)
			result = Visitor::evaluate_expr( root->GetValuePair().second,
											visitAst(root->GetChildren().at(0), factsStrg),
											visitAst(root->GetChildren().at(1), factsStrg)
											);
		else // for unary operations(!)
			result = Visitor::evaluate_expr( root->GetValuePair().second, visitAst(root->GetChildren().at(0), factsStrg) );	
	}
	else
	{
		auto fact_value = factsStrg.find(root->GetValuePair().second);
		if ( fact_value  == factsStrg.end() )
			std::cerr << "Unknown fact" << std::endl;
		else
			result = fact_value->second;
		std::cout << "Fact: " << fact_value->first << " ---- " << root->GetId() << std::endl;
	}
	return (result);
}

bool		Visitor::evaluate_expr(const std::string oper, bool lfact, bool rfact)
{
	bool result;

	if (oper == "+")
		result = lfact && rfact;
	else if (oper == "|")
		result = lfact || rfact;
	else if (oper == "!") // special case, how could be handled?
		result = !lfact;
	else if (oper == "^")
		result = (lfact && !rfact ) || (!lfact && rfact);
	else if (oper == "=>")
		result = !lfact || rfact; // come up with updating the left operand on imply operation
	else if (oper == "<=>")
		result = !((lfact && !rfact ) || (!lfact && rfact));
	else
		std::cerr << "Unknown operation" << std::endl;
	return (result);
}



// Modify using enums for each operation
// bool		Visitor::evaluate_expr(const std::string oper, bool lfact, bool rfact)
// {
// 	bool result;

// 	switch (oper)
// 	{
// 		case "+":
// 			result = lfact && rfact;
// 			break ;
// 		case "|":
// 			result = lfact || rfact;
// 			break ;
// 		case "!": // special case, how could be handled?
// 			result = !lfact;
// 			break ;
// 		case "^":
// 			result = (lfact && !rfact ) || (!lfact && rfact);
// 			break ;
// 		case "=>":
// 			result = !lfact || rfact; // come up with updating the left operand on imply operation
// 			break ;
// 		case "<=>":
// 			result = !((lfact && !rfact ) || (!lfact && rfact));
// 			break ;
// 		default:
// 			std::cerr << "Unknown operation" << std::endl;
// 	}
// 	return (result);
// }

const Node*		Tree::GetRoot() const
{
	return (root_);
}

Tree::Tree(const ast::Node* root, std::map<std::string, bool>& factsStrg) : root_(root)
{
	Visitor		v;
	v.visitAst(root, factsStrg);
}
