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

	class Negation
	{
	public:
		Negation(const std::string oper_label_, Node* const lchild) : Operation(oper_label_, lchild) {}
		~Negation() {};
		bool			Evaluate( const factValues& fact );
	};

	class Disjunction
	{
	public:
		Disjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Disjunction() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};

	class ExclDisjunction
	{
	public:
		ExclDisjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~ExclDisjunction() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};

	class Implication
	{
	public:
		Implication(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Implication() {};
		bool			Evaluate( factValues& value, Fact const* rpart );

	};

	class IFOIF
	{
	public:
		IFOIF(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~IFOIF() {};
		bool			Evaluate( Fact const* lfact, Fact const* rfact );

	};
}

#endif