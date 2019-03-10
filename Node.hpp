#ifndef NODE_HPP
#define NODE_HPP

namespace ExpSys
{
	class Node
	{
		public:
			Node();
			~Node() {};
			int 			GetId() const;

		private:
			size_t			id_;
			static int		instance_number_;

	};
}

#endif