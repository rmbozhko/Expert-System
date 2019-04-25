#ifndef NODE_HPP
#define NODE_HPP

#include <cstdlib>
#include "ExprSysEnums.hpp"
#include <string>

class Node
{
	public:
		Node( nodeType type );
		virtual ~Node() {};
		const int 				GetId( void ) const;
		const nodeType			GetType( void ) const;
		virtual Node*					GetChild( const size_t pos ) const;
		virtual const std::string		GetKey( void ) const;

	private:
		const nodeType		type_;
		int					id_;
		static int					instance_number_;
};

#endif
