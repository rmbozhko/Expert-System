#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace ast
{
	class Node
	{
		public:
			Node( const std::string key, const std::string value );
			~Node();
			const std::pair<const std::string, const std::string>		GetValuePair() const;
			std::vector<Node>											GetChildren() const;
			void														addChild(Node node);

		private:
			const std::pair<const std::string, const std::string> 		node_value_;
			std::vector<Node> 											children_;

	};
}