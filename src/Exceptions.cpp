#include "Exceptions.hpp"
#include "misc.hpp"

std::string& 	operator+=(std::string& s, const factValues& fv) {
	if (fv == factValues::False)
		s += "False";
	else if (fv == factValues::True)
		s += "True";
	else if (fv == factValues::Undetermined)
		s += "Undetermined";
	else
		s += "Processing";
	return (s);
}

std::string		SyntaxException::what_exception() const {
	return (err_msg_ + ":" + std::to_string(linenum_));
}

SyntaxException::SyntaxException(const std::string& err_msg)
    : err_msg_(err_msg)  { linenum_ = 0; }

SyntaxException::SyntaxException(const std::string& err_msg, unsigned linenum) 
    : err_msg_(err_msg), linenum_(linenum) {}

RuleEvaluatingException::RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue), oper_(oper) {}

std::string		RuleEvaluatingException::what_exception() const {
	std::string 		err = "Rule resolving error was encountered while evaluating the rule: ";
	err += rvalue_;
	return ( err );
}

NotImplementedException::NotImplementedException() {}

std::string		NotImplementedException::what_exception() const {
	return ("Not implemented operator was encountered");
}

std::string		RuleContradictionException::what_exception() const {
	std::string err = "Rule contradiction is found.";
	return (err);
}

RuleContradictionException::RuleContradictionException(factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue) {}
