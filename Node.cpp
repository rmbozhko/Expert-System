#include "Node.hpp"

ast::Node(std::string value, std::string key) : node_value_(std::make_pair(value, key))
{}

const std::pair<const std::string, const std::string>		GetValuePair() const
{
	return (node_value_);
}

std::vector<Node>		GetChildren() const
{
	return (children_);
}
			
void		addChild(Node node)
{
	if (node)
	{
		auto& value = GetValuePair(node);
		if (value.first.size() && value.second.size())
			children_.push_back(node);
	}
}			