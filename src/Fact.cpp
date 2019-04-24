#include "Fact.hpp"

Fact::Fact(std::string key) : key_(key), value_(factValues::Processing), Node(nodeType::fact_t)
{}

const std::string& 		Fact::GetKey( void ) const {
	return (key_);
}

int						Fact::SetValue(factValues new_value) {
	value_ = new_value;
	return (0);
}

const factValues&				Fact::GetValue( void ) const {
	return (value_);
}

bool					Fact::operator==(const std::string& rhs) const {
	if (rhs.size() > 0)
		return (GetKey() == rhs);
	else
		return (false);
}

bool 					Fact::operator==( const factValues rhs ) const {
	if (rhs == GetValue())
		return (true);
	else
		return (false);	
}