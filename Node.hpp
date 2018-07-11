#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <iostream>
#include <vector>

namespace ast
{
	class Node
	{
		public:
			Node( const std::string key, const std::string value );
			~Node() {};
			const std::pair<const std::string, const std::string>		GetValuePair() const;
			std::vector<Node*>											GetChildren() const;
			void														addChild(Node* node);
			Node*														GetChild(size_t pos) const;
			int 														GetId() const;

		private:
			const std::pair<const std::string, const std::string> 		node_value_;
			std::vector<Node*> 											children_;
			size_t														id_;
			static int													instance_number_;

	};
}

#endif