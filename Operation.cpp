#include "Operation.hpp"

Operation::Operation(Node* const lchild, Node* const rchild)
{
	if (!(lchild || rchild))
	{
		// invoke exception, because both kids are nullptr
	}
	else
	{
		children_[0] = lchild;
		children_[1] = rchild;
	}
}

std::array<Node const*, 2>&			ExpSys::Operation::GetChildren() const
{
	return (children_.data());
}

ExpSys::Node const*					ExpSys::Operation::GetChild( const size_t pos ) const
{
	return children_.at(pos);
}