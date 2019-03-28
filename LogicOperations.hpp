#ifndef LOGOPER_HPP
#define LOGOPER_HPP

#include "Operation.hpp"
#include "Fact.hpp"

namespace ExprSys
{
	class Conjunction : public Operation
	{
	public:
		Conjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Conjunction() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );
	};

	class Negation : public Operation
	{
	public:
		Negation(const std::string oper_label_, Node* const lchild) : Operation(oper_label_, lchild) {}
		~Negation() {};
		bool			Evaluate( const factValues& fact );
	};

	class Disjunction : public Operation
	{
	public:
		Disjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Disjunction() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};

	class ExclDisjunction : public Operation
	{
	public:
		ExclDisjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~ExclDisjunction() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};

	class Implication : public Operation
	{
	public:
		Implication(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Implication() {};
		bool			Evaluate( factValues& value, Fact* rpart );

	};

	class IFOIF : public Operation
	{
	public:
		IFOIF(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~IFOIF() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};
}

#endif