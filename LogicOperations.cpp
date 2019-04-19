#include "LogicOperations.hpp"
#include "main.hpp"

ExprSys::factValues			ExprSys::Conjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact && rfact);
}

ExprSys::factValues			ExprSys::Negation::Evaluate( ExprSys::factValues& fact )
{	
	// assert(); // ask if lfact or rfact  is Undetermined
	return (!fact);
}

ExprSys::factValues			ExprSys::Disjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return (lfact || rfact);
}

ExprSys::factValues			ExprSys::ExclDisjunction::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	return ((lfact && !rfact) || (!lfact && rfact));
}

void			ExprSys::Conjunction::Evaluate( ExprSys::Node* lfact, ExprSys::Node* rfact, ExprSys::factValues& value )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	if (lfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}
}

void			ExprSys::Negation::Evaluate( ExprSys::Node* lfact, ExprSys::factValues& value )
{	
	// assert(); // ask if lfact or rfact  is Undetermined
	if (lfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == ExprSys::factValues::Processing && value == ExprSys::factValues::True)
			fact->SetValue(ExprSys::factValues::False);
		else if (fact->GetValue() == ExprSys::factValues::Processing && value == ExprSys::factValues::False)
			fact->SetValue(ExprSys::factValues::True);
		else
			if (fact->GetValue() == ExprSys::factValues::Processing)
				fact->SetValue(value);
	}
}

void			ExprSys::Disjunction::Evaluate( ExprSys::Node* lfact, ExprSys::Node* rfact, ExprSys::factValues& value )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	if (lfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}
}

void			ExprSys::ExclDisjunction::Evaluate( ExprSys::Node* lfact, ExprSys::Node* rfact, ExprSys::factValues& value )
{
	// assert(); // ask if lfact or rfact  is Undetermined
	if (lfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == ExprSys::nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}
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

void			ExprSys::checkRuleContracdiction( ExprSys::Node* node, ExprSys::factValues& lvalue )
{
	ExprSys::factValues evaluateAST = [](ExprSys::Node* node, ExprSys::factValues& lvalue) -> ExprSys::factValues&
	{
		if (node->GetType() == ExpSys::nodeType::Operation) {
			const Operation const*	oper = dynamic_cast<const ExpSys::Operation const*>(node);

			if (oper->GetChild(1))
				return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0)), ft_evaluate_lpart(oper->GetChild(1))) );
			else
				return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0))) );
		}
		else {
			return (dynamic_cast<Fact const*>(node)->GetValue());
		}
	}
	ExprSys::factValues	rvalue = evaluateAST(node, lvalue)
	if (rvalue != lvalue)
		throw RuleContradictionException(rvalue, lvalue);
}

void			ExprSys::Implication::Evaluate( ExprSys::factValues& lvalue, ExprSys::Node* node )
{
	if (lvalue == ExprSys::factValues::False)
		return ; // ignoring rule with lside result False

	if (node->GetType() == nodeType::operation_t) {
		ft_evaluate_rpart(node, lvalue);
	}
	else {
		const Fact const*	fact = dynamic_cast<const ExpSys::Fact const*>(node);
		if (fact->GetValue() == ExprSys::factValues::Processing)
			fact->SetValue(value);
	}
	checkRuleContracdiction(node, lvalue);
}

void			ExprSys::IFOIF::Evaluate( ExprSys::Fact* lfact, ExprSys::Fact* rfact )
{
	return (true);
}