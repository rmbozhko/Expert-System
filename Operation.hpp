#ifndef FACT_HPP
#define FACT_HPP

#include <string>
#include <iostream>
#include <vector>

namespace ExpSys
{
	class Operation : public Node
	{
	public:
		Operation();
		~Operation() {};
		std::vector<Fact*>		GetChildren() const;
		void					addChild(Fact* node);
		Fact*					GetChild(const size_t pos) const;
		bool					Evaluate( void );

	private:
		std::vector<Fact*>		children_;
	};
}

#endif