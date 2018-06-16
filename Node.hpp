#pragma once
#include <string>

namespace ast
{
	class Node
	{
		public:
			Node(std::string lfact, std::string rfact, std::string oper);
			~Node();
			std::string		GetLFact() const;
			std::string		GetRFact() const;
			std::string		GetOper() const;
		
		private:
			const std::string		lfact_;
			const std::string		rfact_;
			const std::string		oper_;
	};
}