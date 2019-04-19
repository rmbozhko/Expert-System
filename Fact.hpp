#ifndef FACT_HPP
#define FACT_HPP

#include "main.hpp"
#include "Node.hpp"

namespace ExprSys
{
	class Fact : public Node
	{
	public:
		Fact( const std::string key );
		~Fact() {};
		const factValues&		GetValue( void ) const;
		int						SetValue( factValues );
		const std::string&		GetKey( void ) const;
		
		bool 					operator==( const std::string& rhs ) const;
		bool 					operator==( const ExprSys::factValues rhs ) const;

	private:
		const std::string 		key_;
		ExprSys::factValues		value_;
		
	};
}

#endif