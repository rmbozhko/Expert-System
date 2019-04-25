#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "ExprSysEnums.hpp"
#include <string>

class SyntaxException
{
public:
    SyntaxException(const std::string& err_msg);
    SyntaxException(const std::string& err_msg, unsigned linenum);
    ~SyntaxException() {};

    std::string what_exception() const;

private:
    const std::string 	err_msg_;
    unsigned			linenum_;
};

class RuleEvaluatingException
{
public:
	RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue);
	~RuleEvaluatingException() {};

    std::string what_exception(size_t i) const;

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

    std::string what_exception(size_t i) const;
};

class RuleContradictionException
{
public:
	RuleContradictionException(factValues rvalue, factValues lvalue);
	~RuleContradictionException() {};

    std::string what_exception(size_t i) const;

private:
	factValues	rvalue_;
	factValues	lvalue_;
};

std::string& 	operator+=(std::string& s, const factValues& fv);

#endif
