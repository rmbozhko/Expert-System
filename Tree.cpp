#include "Tree.hpp"

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

void			Visitor::visitDeleteAst(const Node* root)
{
	if (root->GetChildren().size() == 1)
		visitDeleteAst(root->GetChild(0));
	else if (root->GetChildren().size() == 2)
	{
		visitDeleteAst(root->GetChild(0));
		visitDeleteAst(root->GetChild(1));
	}
	delete root;
}

const Operation*		Tree::GetRoot() const
{
	return (root_);
}

Tree::Tree(const ExprSys::Operation* root, std::map<std::string, bool>& factsStrg) : root_(root)
{
	Visitor		v;
	v.visitAst(root, factsStrg);
}
