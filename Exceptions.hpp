#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <exception>
#include <string>
#include "main.hpp"

namespace ExprSys
{
	class SyntaxException : public std::exception
	{
	public:
		SyntaxException(const std::string err_msg);
		SyntaxException(const std::string err_msg, const int linenum);
		~SyntaxException();
		const std::string		what( void );
	private:
		const std::string 	err_msg_;
		const int			linenum_;
	};
	
	const std::string		what( void ) {
		return (err_msg_ + ":\t-------->P.S.: Give a quick look at line #" + std::to_string((!linenum) ? 1 : linenum));
	}

	SyntaxException::SyntaxException(const std::string err_msg) : err_msg_(err_msg) { linenum_ = -1; }

	SyntaxException::SyntaxException(const std::string err_msg, const int linenum) : err_msg_(err_msg), linenum_(linenum) {}

	class RuleEvaluatingException
	{
	public:
		RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue=5);
		~RuleEvaluatingException() {};
		const std::string		what( void );
	private:
		std::string 	oper_;
		factValues		rvalue_;
		factValues		lvalue_;
	};

	RuleEvaluatingException::RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue), oper_(oper)

	const std::string		what( void ) {
		return ("Rule resolving error was encountered while evaluating the rule: " + rvalue_ + " " + oper_ + " " + (lvalue_ == 5) ? lvalue_ : "");
	}

	class NotImplementedException
	{
	public:
		NotImplementedException();
		~NotImplementedException();
		const std::string		what( void );
	};

	const std::string		what( void ) {
		return ("Not implemented operator was encountered");
	}

	class RuleContradictionException : public std::exception
	{
	public:
		RuleContradictionException(factValues rvalue, factValues lvalue);
		~RuleContradictionException();
		const std::string		what( const int i );
	private:
		factValues	rvalue_;
		factValues	lvalue_;
	};

	const std::string		what( const int i ) {
		return ("Rule contradiction is found in rule #" + std::to_string(i) + ". " + rvalue_ " != " lvalue_);
	}

	std::string& operator+(std::string& s, const factValues& fv) {
		if (fv == factValues::False)
			s += "False";
		else if (fv == factValues::True)
			s += "True"
		else if (fv == factValues::Undetermined)
			s += "Undetermined"
		else
			s += "Processing"
		return (s);
	}
	RuleContradictionException::RuleContradictionException(factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue) {}
}
#endif