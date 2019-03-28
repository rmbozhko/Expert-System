#include "Node.hpp"

ExprSys::Node::Node( ExprSys::nodeType type) : type_(type)
{
	id_ = instance_number_;
	instance_number_++;
}

const ExprSys::nodeType		ExprSys::Node::GetType( void ) const {
	return type_;
}

const int 			ExprSys::Node::GetId( void ) const {
	return id_;
}

int			ExprSys::Node::instance_number_ = 0;