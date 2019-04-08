#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <exception>
#include <string>

class SyntaxException : public std::exception
{
public:
	SyntaxException(const std::string err_msg);
	SyntaxException(const std::string err_msg, const int linenum);
	~SyntaxException();
	const std::string		what( void ) { return (err_msg_ + ":\t-------->P.S.: Give a quick look at line #" + std::to_string((!linenum) ? 1 : linenum)); }
private:
	const std::string 	err_msg_;
	const int			linenum_;
};

SyntaxException::SyntaxException(const std::string err_msg) : err_msg_(err_msg) { linenum_ = -1; }

SyntaxException::SyntaxException(const std::string err_msg, const int linenum) : err_msg_(err_msg), linenum_(linenum) {}
#endif