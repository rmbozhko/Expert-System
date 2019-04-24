#include "Node.hpp"

Node::Node( nodeType type) : type_(type)
{
	id_ = instance_number_;
	instance_number_++;
}

const nodeType		Node::GetType( void ) const {
	return type_;
}

const int 			Node::GetId( void ) const {
	return id_;
}

int			Node::instance_number_ = 0;