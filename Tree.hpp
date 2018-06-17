#include "Node.hpp"

namespace ast
{
	class Visitor
	{
	public:
		Visitor();
		~Visitor();
		bool			visitAst(const Node& node, std::map<std::string, bool>& factsStrg);
		static bool		evaluate_expr(bool lfact, bool rfact = false, const std::string oper);
	};

	class Tree
	{
		public:
			Tree(const Node& root);
			~Tree();
			Node		GetRoot() const;

		private:
			Node		root_;
	};
}