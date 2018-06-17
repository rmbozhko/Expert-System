#include "Tree.hpp"

bool		Visitor::visitAst(const Node& root, std::map<std::string, bool>& factsStrg)
{
	bool	resutl;
	
	if (root.GetValuePair().first == "oper")
	{

		if (root.GetChildren().size() > 2)
			std::cerr << "Wrong number of operation operands" << std::endl;
		// visit both operands
		if (root.GetChildren.size() == 2) // for binary operations(+, |)
			result = Tree::evaluate_expr( visitAst(root.GetChildren().at(0), factsStrg),
										visitAst(root.GetChildren().at(1), factsStrg),
										root.GetValuePair().second );
		else // for unary operations(!)
			result = Tree::evaluate_expr( visitAst(root.GetChildren().at(0), factsStrg), root.GetValuePair().second );	
	}
	else
	{
		auto fact_value = factsStrg.find(root.GetValuePair().second);
		if ( fact_value  == factsStrg.end() )
			std::cerr << "Unknown fact" << std::endl;
		else
			result = fact_value->second;
	}
	return (result);
}

bool		Tree::evaluate_expr(bool lfact, bool rfact, const std::string oper)
{
	bool result;

	switch (oper)
	{
		case "+":
			result = lfact && rfact;
			break ;
		case "|":
			result = lfact || rfact;
			break ;
		case "!": // special case, how could be handled?
			result = !lfact;
			break ;
		case "^":
			result = (lfact && !rfact ) || (!lfact && rfact);
			break ;
		case "=>":
			result = !lfact || rfact; // come up with updating the left operand on imply operation
			break ;
		case "<=>":
			result = !((lfact && !rfact ) || (!lfact && rfact));
			break ;
		default:
			std::cerr << "Unknown operation" << std::endl;
	}
	return (result);
}

Tree::Tree(const Node& root, std::map<std::string, bool>& factsStrg) : root_(root)
{
	ast::Visitor		v;
	v.visitAst(root, factsStrg);
}
