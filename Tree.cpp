#include "Tree.hpp"

Operation*		Tree::GetRoot() const {
	return (root_);
}

bool					GetVisited(void) const {
	return (isVisited_);
}

void					SetVisited(bool isVisited) {
	isVisited_ = isVisited;
}

Tree::Tree(Operation* root) : root_(root), isVisited_(false) {}
