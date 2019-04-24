#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include "ExprSysEnums.hpp"
#include <string>

class SyntaxException
{
public:
	SyntaxException(const std::string err_msg);
	SyntaxException(const std::string err_msg, unsigned linenum);
	~SyntaxException() {};
	const std::string		what( void ) const;
private:
	const std::string 	err_msg_;
	unsigned			linenum_;
};

class RuleEvaluatingException
{
public:
	RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue);
	~RuleEvaluatingException() {};
	const std::string		what( void ) const;
private:
	std::string 	oper_;
	factValues		rvalue_;
	factValues		lvalue_;
};

class NotImplementedException
{
public:
	NotImplementedException();
	~NotImplementedException() {};
	const std::string		what( void ) const;
};

class RuleContradictionException
{
public:
	RuleContradictionException(factValues rvalue, factValues lvalue);
	~RuleContradictionException() {};
	const std::string		what( void ) const;
private:
	factValues	rvalue_;
	factValues	lvalue_;
};

#endif
