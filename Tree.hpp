#include "Node.hpp"

namespace ast
{
	class Tree
	{
		public:
			Tree(const Node& root);
			~Tree();
			Node		GetRoot() const;
			bool		GetResult() const;
			void		SetResult(bool value);

		private:
			Node		root_;
			bool		result_;
	};
}