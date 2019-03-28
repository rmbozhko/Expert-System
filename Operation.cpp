#include "Operation.hpp"

ExprSys::Operation::Operation( void ) : ExprSys::Node(ExprSys::nodeType::operation_t) {}

ExprSys::Operation::Operation(const std::string oper_label, ExprSys::Node* const lchild, ExprSys::Node* const rchild) : ExprSys::Node(ExprSys::nodeType::operation_t),
																														oper_label_(oper_label)
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

const ExprSys::Node* const*			ExprSys::Operation::GetChildren( void ) const
{
	return (children_.data());
}

ExprSys::Node const*					ExprSys::Operation::GetChild( const std::size_t pos ) const
{
	return children_.at(pos);
}

const std::string					ExprSys::Operation::GetLabel( void ) const
{
	return (oper_label_);
}