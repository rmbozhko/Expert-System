#include "Tree.hpp"

Operation*		Tree::GetRoot() const {
	return (root_);
}

bool					Tree::GetVisited(void) const {
	return (isVisited_);
}

void					Tree::SetVisited(bool isVisited) {
	isVisited_ = isVisited;
}

Tree::Tree(Operation* root) : root_(root), isVisited_(false) {}
