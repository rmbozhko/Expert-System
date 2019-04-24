#ifndef NODE_HPP
#define NODE_HPP

#include <cstdlib>
#include "ExprSysEnums.hpp"

class Node
{
	public:
		Node( nodeType type );
		virtual ~Node() {};
		const int 			GetId( void ) const;
		const nodeType		GetType( void ) const;

	private:
		const nodeType		type_;
		int					id_;
		static int					instance_number_;
};

#endif
