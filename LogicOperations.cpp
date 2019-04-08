#include "LogicOperations.hpp"
#include "main.hpp"

// ExprSys::Conjunction::Conjunction(const std::string oper_label_, Node* const lchild, Node* const rchild) : ExprSys::Operation(oper_label_, lchild, rchild) {}

bool			ExprSys::Conjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact && rfact);
}

bool			ExprSys::Negation::Evaluate( ExprSys::factValues& fact )
{	
	// assert(); // ask if lfact or rfact  is Undetermined
	return (!fact);
}

bool			ExprSys::Disjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact || rfact);
}

bool			ExprSys::ExclDisjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return ((lfact && !rfact) || (!lfact && rfact));
}

bool 			ExprSys::Fact::isAssignable(ExprSys::factValues& value)
{
	if (this->GetValue() == nodeValue::Processing)
		return (true);
	else if (this->GetValue() == value)
		return (true);
	else
		return (false);
}

bool			ExprSys::Implication::Evaluate( ExprSys::factValues& value, ExprSys::Node* node )
{
	// evaluate right side's node with Processing nodeType
	evaluateRightSide(value);
	if (node->GetType() == nodeType::operation_t)
	{
		// change set value to isAssignable, !check! whether value is true, false or undertermined
		const Operation const*	oper = dynamic_cast<const ExpSys::Operation const*>(node);
		if (!oper->GetChild(0)->isAssignable(value) && !oper->GetChild(1)->isAssignable(value))
			throw RuleContradictionException();
		else if (!oper->GetChild(0)->isAssignable(value))
		{
			if (!(node->Evaluate(node->GetChild(0)->GetValue(), node->GetChild(1)->GetValue()) ==
				node->Evaluate(copy GetChild(0) with value_ = value, node->GetChild(1)->GetValue())))
					throw RuleContradictionException();
		}
		else if (!isAssignable(oper->GetChild(1)->GetValue()))
			if (!(node->Evaluate(node->GetChild(0)->GetValue(), node->GetChild(1)->GetValue()) ==
				node->Evaluate(node->GetChild(0)->GetValue(), copy GetChild(1) with value_ = value)))
					throw RuleContradictionException();
	}
	else
	{
		const Fact const*	fact = dynamic_cast<const ExpSys::Fact const*>(node);
		if (fact->isAssignable(value))
			fact->SetValue(value);
		else
			throw RuleContradictionException();
	}
	return (true);


}

bool			ExprSys::IFOIF::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	return (true);
}