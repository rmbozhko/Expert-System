#ifndef NODE_HPP
#define NODE_HPP

namespace ExpSys
{
	class Node
	{
		public:
			Node( nodeType type );
			virtual ~Node() {};
			const int 			GetId( void ) const;
			const nodeType		GetType( void ) const;

		private:
			const nodeType		type_;
			size_t				id_;
			static int			instance_number_;
	};
}

#endif