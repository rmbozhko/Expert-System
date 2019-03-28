#include "Fact.hpp"
#include <iostream>

ExprSys::Fact::Fact(std::string key) : key_(key), value_(ExprSys::factValues::Undetermined), ExprSys::Node(nodeType::fact_t)
{}

const std::string& 		ExprSys::Fact::GetKey( void ) const
{
	return (key_);
}

void					ExprSys::Fact::SetValue(ExprSys::factValues new_value)
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

const ExprSys::factValues&				ExprSys::Fact::GetValue( void ) const {
	return (value_);
}

bool					ExprSys::Fact::operator==(const std::string& rhs) const
{
	if (rhs.size() > 0)
		return (GetKey() == rhs);
	else
		return (false);
}

// bool 					ExprSys::Fact::operator==( const ExprSys::factValues rhs ) const
// {
// 	if (rhs == GetValue())
// 		return (true);
// 	else
// 		return (false);	
// }


ExprSys::factValues				operator!( const ExprSys::factValues& fact )
{
	if (fact == ExprSys::factValues::True)
		return (ExprSys::factValues::False);
	else if (fact == ExprSys::factValues::False)
		return (ExprSys::factValues::True);
	else
	{
		std::cerr << "Negation exception" << std::endl;
		return (ExprSys::factValues::Undetermined);
	}
}

ExprSys::factValues				ExprSys::Fact::operator||( const Fact* rfact ) const
{
	if (GetValue() == ExprSys::factValues::False && rfact->GetValue() == ExprSys::factValues::False)
		return (ExprSys::factValues::False);
	else if (GetValue() == ExprSys::factValues::Undetermined || rfact->GetValue() == ExprSys::factValues::Undetermined)
	{
		// rise exception
		std::cerr << "OR exception" << std::endl;
		return (ExprSys::factValues::Undetermined);
	}
	else
		return (ExprSys::factValues::True);
}

ExprSys::factValues				ExprSys::Fact::operator&&( const Fact* rfact ) const
{
	if (GetValue() == ExprSys::factValues::True && rfact->GetValue() == ExprSys::factValues::True)
		return (ExprSys::factValues::True);
	else if (GetValue() == ExprSys::factValues::Undetermined || rfact->GetValue() == ExprSys::factValues::Undetermined)
	{
		// rise exception
		std::cerr << "AND exception" << std::endl;
		return (ExprSys::factValues::Undetermined);
	}
	else
		return (ExprSys::factValues::False);
}