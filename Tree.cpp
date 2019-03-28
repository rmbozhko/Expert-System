#include "Tree.hpp"

const ExprSys::Operation*		ExprSys::Tree::GetRoot() const {
	return (root_);
}

ExprSys::Tree::Tree(const ExprSys::Operation* root) : root_(root) {}
