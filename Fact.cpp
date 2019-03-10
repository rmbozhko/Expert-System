#include "Fact.hpp"

ExpSys::Fact::Fact(std::string key) : key_(key), value_(factValues::Undetermined)
{}

const std::string& 		ExpSys::Fact::GetKey( void )
{
	return (key_);
}

void					ExpSys::Fact::SetValue(factValues new_value)
{
	if (value_ == new_value)
		// handle with exception
	else
		value_ = new_value;
}

factValues&				ExpSys::Fact::GetValue( void )
{
	return (value_);
}

bool					ExpSys::Fact::operator==(const& rhs) const
{
	if (rhs.size() > 0)
		return (this->GetKey() == rhs);
	else
		return (false);
}