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
			Tree(ExprSys::Operation* root);
			~Tree() {};
			ExprSys::Operation*		GetRoot(void) const;
			bool					GetVisited(void) const;
			void					SetVisited(bool isVisited = true);

		private:
			ExprSys::Operation*		root_;
			bool					isVisited_;
	};
}

#endif