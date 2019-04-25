#include "ExprSysEnums.hpp"
#include "Exceptions.hpp"
#include <string>

factValues				operator!( const factValues& fact ) {
	if (fact == factValues::True)
		return (factValues::False);
	else if (fact == factValues::False)
		return (factValues::True);
	else if (fact == factValues::Undetermined)
		return (fact);
	else
		throw RuleEvaluatingException("NOT", fact, factValues::Processing);
}

factValues				operator||( const factValues& rfact, const factValues& lfact ) {
	if (rfact == factValues::False && lfact == factValues::False)
		return (factValues::False);
	else if (rfact == factValues::Undetermined || lfact == factValues::Undetermined)
		return (factValues::Undetermined);
	else if (rfact == factValues::True || lfact == factValues::True)
		return (factValues::True);
	else
		throw RuleEvaluatingException("OR", rfact, lfact);
}

factValues				operator&&( const factValues& rfact, const factValues& lfact ) {
	if (rfact == factValues::True && lfact == factValues::True)
		return (factValues::True);
	else if (rfact == factValues::Undetermined || lfact == factValues::Undetermined)
		return (factValues::Undetermined);
	else if (rfact == factValues::False || lfact == factValues::False)
		return (factValues::False);
	else
		throw RuleEvaluatingException("AND", rfact, lfact);
}

factValues				operator^( const factValues& rfact, const factValues& lfact ) {
	if ((rfact == factValues::True && lfact == factValues::True)
		|| (rfact == factValues::False && lfact == factValues::False))
		return (factValues::False);
	else if (rfact == factValues::Undetermined || lfact == factValues::Undetermined)
		return (factValues::Undetermined);
	else if ((rfact == factValues::True && lfact == factValues::False)
		|| (rfact == factValues::False && lfact == factValues::True))
		return (factValues::True);
	else
		throw RuleEvaluatingException("XOR", rfact, lfact);
}

std::ostream& 				operator<<( std::ostream& os, const factValues& lfact ){
	std::string		res;

	if (lfact == factValues::True) {
		res = "True";	
	}
	else if (lfact == factValues::False) {
		res = "False";
	}
	else if (lfact == factValues::Undetermined) {
		res = "Undetermined";
	}
	else
		res = "Processing";
	os << res;
	return (os);
}