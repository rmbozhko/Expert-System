#include "LogicOperations.hpp"
#include "main.hpp"

factValues			Conjunction::Evaluate( factValues& lfact, factValues& rfact ) {
	return (lfact && rfact);
}

factValues			Negation::Evaluate( factValues& fact ) {
	return (!fact);
}

factValues			Disjunction::Evaluate( factValues& lfact, factValues& rfact ) {
	return (lfact || rfact);
}

factValues			ExclDisjunction::Evaluate( factValues& lfact, factValues& rfact ) {
	return ((lfact && !rfact) || (!lfact && rfact));
}

void			Conjunction::Evaluate( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

void			Negation::Evaluate( Node* lfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == factValues::Processing && value == factValues::True)
			fact->SetValue(factValues::False);
		else if (fact->GetValue() == factValues::Processing && value == factValues::False)
			fact->SetValue(factValues::True);
		else
			if (fact->GetValue() == factValues::Processing)
				fact->SetValue(value);
	}
}

void			Disjunction::Evaluate( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

void			ExclDisjunction::Evaluate( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(node);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact const* fact = dynamic_cast<Fact const*>(rfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

void			checkRuleContracdiction( Node* node, factValues& lvalue ) {
	factValues evaluateAST = [](Node* node, factValues& lvalue) -> factValues& {
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
	factValues	rvalue = evaluateAST(node, lvalue)
	if (rvalue != lvalue)
		throw RuleContradictionException(rvalue, lvalue);
}

void			Implication::Evaluate( factValues& lvalue, Node* node ) {
	if (lvalue == factValues::False)
		return ; // ignoring rule with lside result False

	if (node->GetType() == nodeType::operation_t) {
		ft_evaluate_rpart(node, lvalue);
	}
	else {
		const Fact const*	fact = dynamic_cast<const ExpSys::Fact const*>(node);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
	checkRuleContracdiction(node, lvalue);
}

void			IFOIF::Evaluate( Fact* lfact, Fact* rfact ) {
	throw NotImplementedException();
}