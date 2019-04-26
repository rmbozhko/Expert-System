#include "LogicOperations.hpp"
#include "misc.hpp"
#include "Fact.hpp"
#include "Exceptions.hpp"
#include <iostream>

factValues			Conjunction::Evaluate( factValues lfact, factValues rfact ) {
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	std::cout << "LEFT Value :" << lfact << " AND RIGHT Value: " << rfact << std::endl;
	return (lfact && rfact);
}

factValues			Negation::Evaluate( factValues fact ) {
	return (!fact);
}

factValues			Disjunction::Evaluate( factValues lfact, factValues rfact ) {
	return (lfact || rfact);
}

factValues			ExclDisjunction::Evaluate( factValues lfact, factValues rfact ) {
	return ((lfact && !rfact) || (!lfact && rfact));
}

void			Conjunction::Assign( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(lfact);
		std::cout << "Assigning " << fact->GetKey() << "with key " << value << std::endl;
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(rfact);
		std::cout << "Assigning " << fact->GetKey() << "with key " << value << std::endl;
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

void			Negation::Assign( Node* lfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(lfact);
		std::cout << "|||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
		std::cout << "KEY: " << fact->GetKey() << " VALUE: " << fact->GetValue() << std::endl;
		if (fact->GetValue() == factValues::Processing && value == factValues::True)
			fact->SetValue(factValues::False);
		else if (fact->GetValue() == factValues::Processing && value == factValues::False)
			fact->SetValue(factValues::True);
		else
			if (fact->GetValue() == factValues::Processing)
				fact->SetValue(value);
	}
}

void			Disjunction::Assign( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(lfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(rfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

void			ExclDisjunction::Assign( Node* lfact, Node* rfact, factValues& value ) {
	if (lfact->GetType() == nodeType::fact_t) {
		Fact* fact = dynamic_cast<Fact*>(lfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}

	if (rfact->GetType() == nodeType::fact_t) {
		Fact * fact = dynamic_cast<Fact*>(rfact);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(value);
	}
}

factValues 		EvaluateAST(Node* node) {
	if (node->GetType() == nodeType::operation_t) {
		Operation*	oper = dynamic_cast<Operation*>(node);

		if (oper->GetChild(1))
			return ( oper->Evaluate(EvaluateAST( oper->GetChild(0)), EvaluateAST(oper->GetChild(1))) );
		else
			return ( oper->Evaluate(EvaluateAST( oper->GetChild(0))) );
	}
	else {
		return (dynamic_cast<Fact*>(node)->GetValue());
	}
}

void			checkRuleContracdiction( Node* node, factValues& lvalue ) {
	factValues rvalue = EvaluateAST(node);
	std::cout << "±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±§" << std::endl;
	std::cout << "Rule contradiction: " << lvalue << " = " << rvalue << std::endl;
	if (rvalue != lvalue)
		throw RuleContradictionException(rvalue, lvalue);
}

factValues      Implication::Evaluate( factValues lvalue, Node* node ) {
	std::cout << "I was here$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	std::cout << "Assignable value:" << lvalue << std::endl;
	if (lvalue == factValues::False)
		return (factValues::False); // ignoring rule with lside result False

	if (node->GetType() == nodeType::operation_t) {
		ft_evaluate_rpart(node, lvalue);
	}
	else {
		Fact*	fact = dynamic_cast<Fact*>(node);
		if (fact->GetValue() == factValues::Processing)
			fact->SetValue(lvalue);
	}
	checkRuleContracdiction(node, lvalue);
    return (factValues::True);
}

factValues			IFOIF::Evaluate( factValues value, Node* node ) {
	throw NotImplementedException();
    return (factValues::True);
}
