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
		Operation(const std::string oper_label = "", Node* const lchild = nullptr, Node* const rchild = nullptr);
		virtual ~Operation() {};
		std::array<Node const*, 2>		GetChildren( void ) const;
		Node const*						GetChild( const size_t pos ) const;
		virtual bool					Evaluate( void );

	private:
		std::array<Node const*, 2>		children_;
		const std::string&				oper_label_
	};
}

#endif