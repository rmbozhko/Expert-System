#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "Node.hpp"
#include "ExprSysEnums.hpp"
#include <array>

class Operation : public Node
{
public:
	Operation();
	Operation(const std::string oper_label = "", Node* lchild = nullptr, Node* rchild = nullptr);
	virtual ~Operation() {};
	// const Node* const*			GetChildren( void ) const;
	Node*						GetChild( const size_t pos ) const;
	virtual bool					Evaluate( void ) { return (true); };
	const std::string				GetLabel( void ) const;

private:
	std::array<Node*, 2>		children_;
	const std::string				oper_label_;
};

#endif