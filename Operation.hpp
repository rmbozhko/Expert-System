#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "Node.hpp"
#include <iostream>
#include <array>

namespace ExpSys
{
	class Operation : public Node
	{
	public:
		Operation(Node* const lchild = nullptr, Node* const rchild = nullptr);
		~Operation() {};
		std::array<Node const*, 2>		GetChildren( void ) const;
		Node const*						GetChild( const size_t pos ) const;
		bool							Evaluate( void );

	private:
		std::array<Node const*, 2>		children_;		
	};
}

#endif