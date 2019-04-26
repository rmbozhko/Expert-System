#include "Fact.hpp"
#include <ostream>
#include <iostream>
// Fact::Fact(std::string key) : key_(key), value_(factValues::Processing), Node(nodeType::fact_t)
// {}

Fact::Fact(std::string key, factValues value) : key_(key), value_(value), Node(nodeType::fact_t)
{}

const std::string 		Fact::GetKey( void ) const {
	return (key_);
}

int						Fact::SetValue(factValues new_value) {
	if (GetKey() == "E")
	{
		std::cout << "????????????????????????????????" << std::endl;
		std::cout << "NV: " << new_value << "\nOLDV: " << value_;
	}
	value_ = new_value;
	return (0);
}

const factValues&				Fact::GetValue( void ) const {
	return (value_);
}

std::ostream&				operator<<(std::ostream& os, const Fact* fact) {
	os << fact->GetKey() << " -> " << fact->GetValue() << std::endl;
	return (os);
}

// bool					Fact::operator==(const std::string rhs) const {
// 	if (rhs.size() > 0)
// 		return (GetKey() == rhs);
// 	else
// 		return (false);
// }

// bool 					Fact::operator==( const factValues rhs ) const {
// 	if (rhs == GetValue())
// 		return (true);
// 	else
// 		return (false);	
// }
