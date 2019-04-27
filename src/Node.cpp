#include "Node.hpp"
#include <iostream>

Node::Node( nodeType type) : type_(type) {
	id_ = instance_number_;
	instance_number_++;
}

const nodeType		Node::GetType( void ) const {
	return type_;
}

const int 			Node::GetId( void ) const {
	return id_;
}

Node*				Node::GetChild( const size_t pos ) const {
	return nullptr;
}

const std::string		Node::GetKey( void ) const {
	return ("No key availiable");
}

int			Node::instance_number_ = 0;