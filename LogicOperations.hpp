#ifndef FACT_HPP
#define FACT_HPP

#include "Node.hpp"

namespace ExpSys
{
	class Conjunction : public : Operation
	{
	public:
		Conjunction(Node* const lchild, Node* const rchild) : Operation(lchild, rchild) {}
		~Conjunction() {};
		bool			Evaluate( void );
	};

	class Negation
	{
	public:
		Negation(Node* const lchild) : Operation(lchild) {}
		~Negation() {};
		bool			Evaluate( void );
	};

	class Disjunction
	{
	public:
		Disjunction(Node* const lchild, Node* const rchild) : Operation(lchild, rchild) {}
		~Disjunction() {};
		bool			Evaluate( void );

	};

	class ExclDisjunction
	{
	public:
		ExclDisjunction(Node* const lchild, Node* const rchild) : Operation(lchild, rchild) {}
		~ExclDisjunction() {};
		bool			Evaluate( void );

	};

	class Implication
	{
	public:
		Implication(Node* const lchild, Node* const rchild) : Operation(lchild, rchild) {}
		~Implication() {};
		bool			Evaluate( void );

	};

	class IFOIF
	{
	public:
		IFOIF(Node* const lchild, Node* const rchild) : Operation(lchild, rchild) {}
		~IFOIF() {};
		bool			Evaluate( void );

	};
}

#endif