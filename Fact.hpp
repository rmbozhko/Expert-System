#ifndef FACT_HPP
#define FACT_HPP

#include <string>
#include "main.hpp"

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
		
		factValues				operator!( void )
		{
			if (this->GetValue() == factValues::True)
				return (factValues::False);
			else if (this->GetValue() == factValues::False)
				return (factValues::True);
			else
			{
				// rise exception
			}
		}

		factValues				operator||( const Fact* rfact )
		{
			if (this->GetValue() == factValues::False && rfact->GetValue() == factValues::False)
				return (factValues::False);
			else if (this->GetValue() == factValues::Undetermined || rfact->GetValue() == factValues::Undetermined)
			{
				// rise exception
			}
			else
				return (factValues::True);
		}

		factValues				operator&&( const Fact* rfact )
		{
			if (this->GetValue() == factValues::True && rfact->GetValue() == factValues::True)
				return (factValues::True);
			else if (this->GetValue() == factValues::Undetermined || rfact->GetValue() == factValues::Undetermined)
			{
				// rise exception
			}
			else
				return (factValues::False);
		}

	private:
		const std::string 		key_;
		factValues				value_;
		
	};
}

#endif