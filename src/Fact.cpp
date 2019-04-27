#include "Fact.hpp"
#include <ostream>

Fact::Fact(std::string key, factValues value) : key_(key), value_(value), Node(nodeType::fact_t)
{}

const std::string 		Fact::GetKey( void ) const {
	return (key_);
}

int						Fact::SetValue(factValues new_value) {
	value_ = new_value;
	return (0);
}

const factValues&				Fact::GetValue( void ) const {
	return (value_);
}

std::ostream&				operator<<(std::ostream& os, const Fact* fact) {
	if (fact->GetValue() == factValues::True)
		os << "\033[32m";
	else if (fact->GetValue() == factValues::False)
		os << "\033[31m";
	else if (fact->GetValue() == factValues::Undetermined)
		os << "\033[34m";
	else
		os << "\033[35m";
	os << fact->GetKey() << " -> " << fact->GetValue() << "\033[0m" << std::endl;
	return (os);
}
