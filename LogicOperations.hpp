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
	void				Assign( Node* lfact, Node* rfact, factValues& value );
	factValues			Evaluate( factValues& lfact, factValues& rfact );
};

class Negation : public Operation
{
public:
	Negation(const std::string oper_label_, Node* lchild) : Operation(oper_label_, lchild) {}
	~Negation() {};
	void				Assign( Node* lfact, factValues& value );
	factValues			Evaluate( factValues& fact );
};

class Disjunction : public Operation
{
public:
	Disjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~Disjunction() {};
	void				Assign( Node* lfact, Node* rfact, factValues& value );
	factValues			Evaluate( factValues& lfact, factValues& rfact );
};

class ExclDisjunction : public Operation
{
public:
	ExclDisjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~ExclDisjunction() {};
	void				Assign( Node* lfact, Node* rfact, factValues& value );
	factValues			Evaluate( factValues& lfact, factValues& rfact );
};

class Implication : public Operation
{
public:
	Implication(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~Implication() {};
	void			Evaluate( factValues& lvalue, Node* node );
};

class IFOIF : public Operation
{
public:
	IFOIF(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
	~IFOIF() {};
	void			Evaluate( factValues& value, Node* node );
};

#endif