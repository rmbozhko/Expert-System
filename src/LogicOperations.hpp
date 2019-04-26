#ifndef LOGOPER_HPP
#define LOGOPER_HPP

#include "Node.hpp"
#include <string>
#include "ExprSysEnums.hpp"
#include "Operation.hpp"
#include "Fact.hpp"

class Conjunction : public Operation
{
public:
	Conjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~Conjunction() {};
	virtual void				Assign( Node* lfact, Node* rfact, factValues& value );
	virtual factValues			Evaluate( factValues lfact, factValues rfact );
};

class Negation : public Operation
{
public:
	Negation(const std::string oper_label_, Node* lchild) : Operation(oper_label_, lchild) {}
	~Negation() {};
	virtual void				Assign( Node* lfact, factValues& value );
	virtual factValues			Evaluate( factValues fact );
};

class Disjunction : public Operation
{
public:
	Disjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~Disjunction() {};
	virtual void				Assign( Node* lfact, Node* rfact, factValues& value );
	virtual factValues			Evaluate( factValues lfact, factValues rfact );
};

class ExclDisjunction : public Operation
{
public:
	ExclDisjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~ExclDisjunction() {};
	virtual void				Assign( Node* lfact, Node* rfact, factValues& value );
	virtual factValues			Evaluate( factValues lfact, factValues rfact );
};

class Implication : public Operation
{
public:
	Implication(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~Implication() {};
    virtual factValues          Evaluate( factValues lvalue, Node* node );
};

class IFOIF : public Operation
{
public:
	IFOIF(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~IFOIF() {};
	virtual factValues			Evaluate( factValues value, Node* node );
};

#endif
