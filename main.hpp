#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <string>

namespace ExprSys
{
	enum factValues
	{
		False,
		True,
		Undetermined,
		Processing
	};

	enum nodeType
	{
		fact_t,
		operation_t
	};
}

#endif