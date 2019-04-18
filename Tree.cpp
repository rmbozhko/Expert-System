#include "Tree.hpp"

ExprSys::Operation*		ExprSys::Tree::GetRoot() const {
	return (root_);
}

bool					ExprSys::GetVisited(void) const {
	return (isVisited_);
}

void					ExprSys::SetVisited(bool isVisited) {
	isVisited_ = isVisited;
}

ExprSys::Tree::Tree(ExprSys::Operation* root) : root_(root), isVisited_(false) {}
