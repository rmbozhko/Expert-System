#include "LogicOperations.hpp"
#include "main.hpp"

// ExprSys::Conjunction::Conjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : ExprSys::Operation(oper_label_, lchild, rchild) {}

bool			ExprSys::Conjunction::Evaluate( ExprSys::Fact const* lfact, ExprSys::Fact const* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact && rfact);
}

bool			ExprSys::Negation::Evaluate( const ExprSys::factValues& fact )
{	
	// assert(); // ask if lfact or rfact  is Undetermined
	return (!fact);
}

bool			ExprSys::Disjunction::Evaluate( ExprSys::Fact const* lfact, ExprSys::Fact const* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact || rfact);
}

bool			ExprSys::ExclDisjunction::Evaluate( ExprSys::Fact const* lfact, ExprSys::Fact const* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return ((lfact && !rfact) || (!lfact && rfact));
}

bool			ExprSys::Implication::Evaluate( ExprSys::factValues& value, ExprSys::Fact const* rpart )
{
	if (rpart == ExprSys::factValues::Undetermined)
		rpart->SetValue( (value == ExprSys::factValues::True) ? ExprSys::factValues::True : ExprSys::factValues::False );
	else
	{
		// if (result != fact_ptr->GetValue())
		// {
		// 	// throw exception, that some rules are conflicting
		// }
	}


}

bool			ExprSys::IFOIF::Evaluate( ExprSys::Fact const* lfact, ExprSys::Fact const* rfact )
{
	
}