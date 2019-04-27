#ifndef FACT_HPP
#define FACT_HPP

#include "ExprSysEnums.hpp"
#include "Node.hpp"
#include <string>
#include <ostream>

class Fact : public Node
{
public:
	Fact( const std::string key, factValues value = factValues::Processing );
	~Fact() {};
	const factValues&		GetValue( void ) const;
	int						SetValue( factValues );
	virtual const std::string		GetKey( void ) const;

private:
	const std::string 		key_;
	factValues		value_;
	
};

std::ostream&				operator<<(std::ostream& os, const Fact* fact);

#endif
