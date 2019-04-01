#ifndef LOGOPER_HPP
#define LOGOPER_HPP

#include "Operation.hpp"
#include "Fact.hpp"

namespace ExprSys
{
	class Conjunction : public Operation
	{
	public:
		Conjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
		~Conjunction() {};
		bool			Evaluate( Fact* lfact, Fact* rfact );
	};

	class Negation : public Operation
	{
	public:
		Negation(const std::string oper_label_, Node* lchild) : Operation(oper_label_, lchild) {}
		~Negation() {};
		bool			Evaluate( factValues& fact );
	};

	class Disjunction : public Operation
	{
	public:
		Disjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
		~Disjunction() {};
		bool			Evaluate( Fact* lfact, Fact* rfact );

	};

	class ExclDisjunction : public Operation
	{
	public:
		ExclDisjunction(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
		~ExclDisjunction() {};
		bool			Evaluate( Fact* lfact, Fact* rfact );

	};

	class Implication : public Operation
	{
	public:
		Implication(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
		~Implication() {};
		bool			Evaluate( factValues& value, Fact* rpart );

	};

	class IFOIF : public Operation
	{
	public:
		IFOIF(const std::string oper_label_, Node* lchild, Node* rchild) : Operation(oper_label_, lchild, rchild) {}
		~IFOIF() {};
		bool			Evaluate( Fact* lfact, Fact* rfact );

	};
}

#endif