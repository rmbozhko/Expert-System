#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "Node.hpp"
#include <iostream>
#include <array>

namespace ExprSys
{
	class Operation : public Node
	{
	public:
		Operation();
		Operation(const std::string oper_label = "", ExprSys::Node* const lchild = nullptr, ExprSys::Node* const rchild = nullptr);
		virtual ~Operation();
		const ExprSys::Node* const*			GetChildren( void ) const;
		ExprSys::Node const*						GetChild( const size_t pos ) const;
		virtual bool					Evaluate( void );
		const std::string				GetLabel( void ) const;

	private:
		std::array<ExprSys::Node const*, 2>		children_;
		const std::string				oper_label_;
	};
}

#endif