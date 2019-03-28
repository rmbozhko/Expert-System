#include "Operation.hpp"

Operation::Operation(const std::string oper_label, Node* const lchild, Node* const rchild) : ExpSys::Node(nodeType::Operation)
{
	if (!(lchild || rchild))
	{
		// invoke exception, because both kids are nullptr
	}
	else
	{
		children_[0] = lchild;
		children_[1] = rchild;
		oper_label_ = oper_label;
	}
}

std::array<Node const*, 2>&			ExpSys::Operation::GetChildren( void ) const
{
	return (children_.data());
}

ExpSys::Node const*					ExpSys::Operation::GetChild( const size_t pos ) const
{
	return children_.at(pos);
}

const std::string&					ExpSys::Operation::GetLabel( void ) const
{
	return (oper_label_);
}