#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <string>
#include <Exceptions.hpp>

namespace ExprSys
{
	void		ft_print_dot(std::vector<ExprSys::Tree*>& treeStrg, std::map<std::string, ExprSys::Fact*> factsStrg);
	void		ft_process_fact(const std::string& fact, std::vector<ExpSys::Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg);
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