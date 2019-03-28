#ifndef FACT_HPP
#define FACT_HPP

#include "Node.hpp"

namespace ExpSys
{
	class Conjunction : public : Operation
	{
	public:
		Conjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Conjunction() {};
		bool			Evaluate( void );
	};

	class Negation
	{
	public:
		Negation(const std::string oper_label_, Node* const lchild) : Operation(oper_label_, lchild) {}
		~Negation() {};
		bool			Evaluate( void );
	};

	class Disjunction
	{
	public:
		Disjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Disjunction() {};
		bool			Evaluate( void );

	};

	class ExclDisjunction
	{
	public:
		ExclDisjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~ExclDisjunction() {};
		bool			Evaluate( void );

	};

	class Implication
	{
	public:
		Implication(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~Implication() {};
		bool			Evaluate( void );

	};

	class IFOIF
	{
	public:
		IFOIF(const std::string oper_label_, Node* const lchild, Node* const rchild) : Operation(oper_label_, lchild, rchild) {}
		~IFOIF() {};
		bool			Evaluate( void );

	};
}

#endif