#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <string>
#include <Exceptions.hpp>

namespace ExprSys
{
	int 		yyparse (std::vector<ExprSys::Tree*>& treeStrg, std::map<std::string, ExprSys::Fact*>& factsStrg, std::vector<std::string>& factsOutput);
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

	ExprSys::factValues				operator!( const ExprSys::factValues& fact ) {
		if (fact == ExprSys::factValues::True)
			return (ExprSys::factValues::False);
		else if (fact == ExprSys::factValues::False)
			return (ExprSys::factValues::True);
		else if (fact == ExprSys::factValues::Undetermined)
			return (fact);
		else
			throw RuleEvaluatingException("NOT", fact);
	}

	ExprSys::factValues				operator||( const ExprSys::factValues& rfact, const ExprSys::factValues& lfact ) {
		if (rfact == ExprSys::factValues::False && lfact == ExprSys::factValues::False)
			return (ExprSys::factValues::False);
		else if (rfact == ExprSys::factValues::Undetermined || lfact == ExprSys::factValues::Undetermined)
			return (ExprSys::factValues::Undetermined);
		else if (rfact == ExprSys::factValues::True || lfact == ExprSys::factValues::True)
			return (ExprSys::factValues::True);
		else
			throw RuleEvaluatingException("OR", rfact, lfact);
	}

	ExprSys::factValues				operator&&( const ExprSys::factValues& rfact, const ExprSys::factValues& lfact ) {
		if (rfact == ExprSys::factValues::True && lfact == ExprSys::factValues::True)
			return (ExprSys::factValues::True);
		else if (rfact == ExprSys::factValues::Undetermined || lfact == ExprSys::factValues::Undetermined)
			return (ExprSys::factValues::Undetermined);
		else if (rfact == ExprSys::factValues::False || lfact == ExprSys::factValues::False)
			return (ExprSys::factValues::False);
		else
			throw RuleEvaluatingException("AND", rfact, lfact);
	}

	ExprSys::factValues				operator^( const ExprSys::factValues& rfact, const ExprSys::factValues& lfact ) {
		if (rfact == ExprSys::factValues::True && lfact == ExprSys::factValues::True
			|| rfact == ExprSys::factValues::False && lfact == ExprSys::factValues::False)
			return (ExprSys::factValues::False);
		else if (rfact == ExprSys::factValues::Undetermined || lfact == ExprSys::factValues::Undetermined)
			return (ExprSys::factValues::Undetermined);
		else if (rfact == ExprSys::factValues::True && lfact == ExprSys::factValues::False
			|| rfact == ExprSys::factValues::False && lfact == ExprSys::factValues::True)
			return (ExprSys::factValues::True);
		else
			throw RuleEvaluatingException("XOR", rfact, lfact);
	}
}

#endif