#ifndef TREE_HPP
# define TREE_HPP

#include "Operation.hpp"
#include <map>
#include <string>
#include <iostream>

namespace ExprSys
{
	class Tree
	{
		public:
			Tree(const ExprSys::Operation* root);
			~Tree() {};
			const ExprSys::Operation*		GetRoot() const;

		private:
			const ExprSys::Operation*		root_;
	};
}

#endif