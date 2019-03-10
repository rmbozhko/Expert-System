#ifndef FACT_HPP
#define FACT_HPP

#include <string>
#include <iostream>
#include <vector>

namespace ExpSys
{
	class Fact : public Node
	{
	public:
		Fact( const std::string key );
		~Fact() {};
		factValues&				GetValue( void );
		void					SetValue( factValues );
		const std::string&		GetKey( void );
		bool 					operator==( const& rhs ) const;

	private:
		const std::string 		key_;
		factValues				value_;
		
	};
}

#endif