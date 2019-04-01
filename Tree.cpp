#include "Tree.hpp"

ExprSys::Operation*		ExprSys::Tree::GetRoot() const {
	return (root_);
}

ExprSys::Tree::Tree(ExprSys::Operation* root) : root_(root) {}
