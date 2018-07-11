#include "Node.hpp"

ast::Node::Node(std::string key, std::string value) : node_value_(std::make_pair(key, value))
{
	id_ = instance_number_;
	instance_number_++;
}

const std::pair<const std::string, const std::string>		ast::Node::GetValuePair() const
{
	return (node_value_);
}

std::vector<ast::Node*>		ast::Node::GetChildren() const
{
	return (children_);
}

int 						ast::Node::GetId() const
{
	return (id_);
}

ast::Node*					ast::Node::GetChild(size_t pos) const
{
	if (pos <= children_.size())
		return children_[pos];
	return nullptr;
}
			
void		ast::Node::addChild(ast::Node* node)
{
	const std::pair<const std::string, const std::string> value = node->GetValuePair();
	if (value.first.size() && value.second.size())
		children_.push_back(node);
}

int			ast::Node::instance_number_ = 0;