#ifndef FACT_HPP
#define FACT_HPP

#include "Node.hpp"

namespace ExpSys
{
	class Conjunction : public : Operation
	{
	public:
		Conjunction(Node* const lchild, Node* const rchild) : lchild_(lchild), rchild_(rchild)
		~Conjunction() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
		Node* const		rchild_;
	};

	class Negation
	{
	public:
		Negation(Node* const lchild) : lchild_(lchild)
		~Negation() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
	};

	class Disjunction
	{
	public:
		Disjunction(Node* const lchild, Node* const rchild) : lchild_(lchild), rchild_(rchild)
		~Disjunction() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
		Node* const		rchild_;
	};

	class ExclDisjunction
	{
	public:
		ExclDisjunction(Node* const lchild, Node* const rchild) : lchild_(lchild), rchild_(rchild)
		~ExclDisjunction() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
		Node* const		rchild_;
	};

	class Implication
	{
	public:
		Implication(Node* const lchild, Node* const rchild) : lchild_(lchild), rchild_(rchild)
		~Implication() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
		Node* const		rchild_;
	};

	class IFOIF
	{
	public:
		IFOIF(Node* const lchild, Node* const rchild) : lchild_(lchild), rchild_(rchild)
		~IFOIF() {};
		bool			Evaluate( void );
	private:
		Node* const		lchild_;
		Node* const		rchild_;
	};
}

#endif