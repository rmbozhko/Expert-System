#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "Node.hpp"
#include "ExprSysEnums.hpp"
#include <array>
#include <string>

class Operation : public Node
{
public:
	Operation();
	Operation(const std::string oper_label = "", Node* lchild = nullptr, Node* rchild = nullptr);
	virtual ~Operation() {};

	Node*						GetChild( const size_t pos ) const;
	const std::string			GetLabel( void ) const;

    void Assign( Node* lfact, factValues& value );
    void Assign( factValues& value, Node* node );
    void Assign( Node* lfact, Node* rfact, factValues& value );

    factValues Evaluate( factValues lfact, factValues rfact );
    factValues Evaluate( factValues fact );
    factValues Evaluate( factValues lvalue, Node* node );

private:
	std::array<Node*, 2>		children_;
	const std::string				oper_label_;
};

#endif
