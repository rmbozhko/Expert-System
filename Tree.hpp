#ifndef TREE_HPP
# define TREE_HPP

#include "Node.hpp"
#include <map>
#include <string>
#include <iostream>

namespace ast
{
	class Visitor
	{
	public:
		Visitor() {};
		~Visitor() {};
		bool			visitAst(const Node* root, std::map<std::string, bool>& factsStrg);
		static bool		evaluate_expr(const std::string oper, bool lfact, bool rfact = false);
	};

	class Tree
	{
		public:
			Tree(const Node* root, std::map<std::string, bool>& factsStrg);
			~Tree() {};
			Node		GetRoot() const;

		private:
			Node		root_;
	};
}

#endif