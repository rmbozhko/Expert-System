#include "Node.hpp"

ast::Node(std::string lfact, std::string rfact, std::string oper) : 
			lfact_(lfact), rfact_(rfact), oper_(oper)
{}

std::string		ast::Node::GetLFact() const { return (lfact); }

std::string		ast::Node::GetRFact() const { return (rfact); }

std::string		ast::Node::GetOper() const { return (oper); }