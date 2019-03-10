#include "Operation.hpp"

std::vector<ExpSys::Fact*>		ExpSys::Operation::GetChildren() const
{
	return (children_);
}

ExpSys::Fact*					ExpSys::Operation::GetChild(size_t pos) const
{
	if (pos <= children_.size())
		return children_[pos];
	return nullptr;
}
			
void		ExpSys::Operation::addChild(ExpSys::Fact* fact)
{
	if (fact->GetKey().size())
		children_.push_back(fact);
	// else
		// throw exception
}