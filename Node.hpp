#ifndef NODE_HPP
#define NODE_HPP

#include "main.hpp"

namespace ExprSys
{
	class Node
	{
		public:
			Node( ExprSys::nodeType type );
			virtual ~Node() {};
			const int 			GetId( void ) const;
			const ExprSys::nodeType		GetType( void ) const;

		private:
			const ExprSys::nodeType		type_;
			std::size_t					id_;
			static int					instance_number_;
	};
}

#endif