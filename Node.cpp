#include "Node.hpp"

ExpSys::Node::Node()
{
	id_ = instance_number_;
	instance_number_++;
}

int			ExpSys::Node::instance_number_ = 0;