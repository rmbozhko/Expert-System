#include "Fact.hpp"

ExpSys::Fact::Fact(std::string key) : key_(key), value_(factValues::Undetermined), ExpSys::Node(nodeType::Fact)
{}

const std::string& 		ExpSys::Fact::GetKey( void )
{
	return (key_);
}

void					ExpSys::Fact::SetValue(factValues new_value)
{
	if (value_ == new_value)
	{
		// handle with exception
		// or return true/false to show whether the value was assigned
		// it should help with checking
	}
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

factValues				operator!( void )
{
	if (this->GetValue() == factValues::True)
		return (factValues::False);
	else if (this->GetValue() == factValues::False)
		return (factValues::True);
	else
	{
		// rise exception
	}
}

factValues				operator||( const Fact* rfact )
{
	if (this->GetValue() == factValues::False && rfact->GetValue() == factValues::False)
		return (factValues::False);
	else if (this->GetValue() == factValues::Undetermined || rfact->GetValue() == factValues::Undetermined)
	{
		// rise exception
	}
	else
		return (factValues::True);
}

factValues				operator&&( const Fact* rfact )
{
	if (this->GetValue() == factValues::True && rfact->GetValue() == factValues::True)
		return (factValues::True);
	else if (this->GetValue() == factValues::Undetermined || rfact->GetValue() == factValues::Undetermined)
	{
		// rise exception
	}
	else
		return (factValues::False);
}