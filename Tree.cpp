#include "Tree.hpp"
Tree::Tree(const Node& root) : root_(root), result_(SetResult(root))
{}

bool		ast::Tree::GetResult() const
{
	return (result_);
}

void		ast::Tree::SetResult(Node& root)
{
	ast::Visitor		v;

	result_ = v.visitAst(root);
}