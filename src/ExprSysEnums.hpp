#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <ostream>

enum class factValues
{
	False,
	True,
	Undetermined,
	Processing
};
factValues 	operator!( const factValues& fact );
factValues 	operator||( const factValues& rfact, const factValues& lfact );
factValues 	operator&&( const factValues& rfact, const factValues& lfact );
factValues 	operator^( const factValues& rfact, const factValues& lfact );
std::ostream& 	operator<<( std::ostream& os, const factValues& lfact );


enum nodeType
{
	fact_t,
	operation_t
};

#endif
