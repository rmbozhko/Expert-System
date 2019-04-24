#ifndef ENUMS_HPP
#define ENUMS_HPP

enum class factValues
{
	False,
	True,
	Undetermined,
	Processing
};
factValues operator!( const factValues& fact );
factValues operator||( const factValues& rfact, const factValues& lfact );
factValues operator&&( const factValues& rfact, const factValues& lfact );
factValues operator^( const factValues& rfact, const factValues& lfact );

enum nodeType
{
	fact_t,
	operation_t
};

#endif
