#ifndef TREE_HPP
# define TREE_HPP

#include "Operation.hpp"
#include <map>
#include <string>
#include <iostream>

	class Tree
	{
		public:
			Tree(Operation* root);
			~Tree() {};
			Operation*		GetRoot(void) const;
			bool					GetVisited(void) const;
			void					SetVisited(bool isVisited = true);

		private:
			Operation*		root_;
			bool					isVisited_;
	};

#endif