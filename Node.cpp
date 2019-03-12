#include "Node.hpp"

ExpSys::Node::Node( nodeType type) : type_(type)
{
	id_ = instance_number_;
	instance_number_++;
}

const nodeType		GetType( void )
{
	return type_;
}

const int 			GetId( void )
{
	return id_;
}

int			ExpSys::Node::instance_number_ = 0;