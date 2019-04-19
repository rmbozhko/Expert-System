#include "Fact.hpp"
#include <iostream>

ExprSys::Fact::Fact(std::string key) : key_(key), value_(ExprSys::factValues::Undetermined), ExprSys::Node(nodeType::fact_t)
{}

const std::string& 		ExprSys::Fact::GetKey( void ) const {
	return (key_);
}

int						ExprSys::Fact::SetValue(ExprSys::factValues new_value) {
	value_ = new_value;
	return (0);
}

const ExprSys::factValues&				ExprSys::Fact::GetValue( void ) const {
	return (value_);
}

bool					ExprSys::Fact::operator==(const std::string& rhs) const {
	if (rhs.size() > 0)
		return (GetKey() == rhs);
	else
		return (false);
}

bool 					ExprSys::Fact::operator==( const ExprSys::factValues rhs ) const {
	if (rhs == GetValue())
		return (true);
	else
		return (false);	
}
