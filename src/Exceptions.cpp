#include "Exceptions.hpp"
#include "misc.hpp"

// std::string& Exceptions::operator+(std::string& s, const factValues& fv) {
// 	if (fv == factValues::False)
// 		s += "False";
// 	else if (fv == factValues::True)
// 		s += "True";
// 	else if (fv == factValues::Undetermined)
// 		s += "Undetermined";
// 	else
// 		s += "Processing";
// 	return (s);
// }

const std::string		SyntaxException::what( void ) const {
	return (err_msg_ + ":\t-------->P.S.: Give a quick look at line #" + std::to_string((!linenum_) ? 1 : linenum_));
}

SyntaxException::SyntaxException(const std::string err_msg) : err_msg_(err_msg) { linenum_ = 0; }

SyntaxException::SyntaxException(const std::string err_msg, unsigned linenum) : err_msg_(err_msg), linenum_(linenum) {}

RuleEvaluatingException::RuleEvaluatingException(std::string oper, factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue), oper_(oper) {}

const std::string		RuleEvaluatingException::what( void ) const {
	std::string 		err = "Rule resolving error was encountered while evaluating the rule: ";
	// err += rvalue_;
	// err += " " + oper_;
	// err += (oper_ == "NOT") ? "" : " " + lvalue_;
	return ( err );
}

const std::string		NotImplementedException::what( void ) const {
	return ("Not implemented operator was encountered");
}

const std::string		RuleContradictionException::what( void ) const {
	std::string err = "Rule contradiction is found.";
	return (err); //+ std::to_string(i) + ". "); //+ rvalue_ " != " lvalue_);
}

RuleContradictionException::RuleContradictionException(factValues rvalue, factValues lvalue) : rvalue_(rvalue), lvalue_(lvalue) {}
