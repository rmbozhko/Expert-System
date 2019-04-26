#include "Tree.hpp"
#include "ExprSysEnums.hpp"

Tree::Tree(Operation* root) : root_(root), isVisited_(false) {}

Operation*		Tree::GetRoot() const {
	return (root_);
}

bool					Tree::GetVisited(void) const {
	return (isVisited_);
}

void					Tree::SetVisited(bool isVisited) {
	isVisited_ = isVisited;
}

void					Tree::DeleteNodes(Node* node) {
	if (node->GetType() == nodeType::operation_t) {
		DeleteNodes(node->GetChild(0));
		if (node->GetChild(1)) {
			DeleteNodes(node->GetChild(1));
		}
	}
	delete node;
}