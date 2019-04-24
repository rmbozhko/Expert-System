#include "Operation.hpp"

Operation::Operation( void ) : Node(nodeType::operation_t) {}

Operation::Operation(const std::string oper_label, Node* lchild, Node* rchild)
    : Node(nodeType::operation_t)
    , oper_label_(oper_label)
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

Node*					Operation::GetChild( const std::size_t pos ) const
{
	return children_.at(pos);
}

const std::string					Operation::GetLabel( void ) const
{
	return (oper_label_);
}

void Operation::Assign( Node* lfact, factValues& value )
{
}

void Operation::Assign( factValues& value, Node* node )
{
}

void Operation::Assign( Node* lfact, Node* rfact, factValues& value )
{
}

factValues Operation::Evaluate( factValues lfact, factValues rfact )
{
}

factValues Operation::Evaluate( factValues fact )
{
}

factValues Operation::Evaluate( factValues lvalue, Node* node )
{
}
