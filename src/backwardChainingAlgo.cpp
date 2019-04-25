#include <vector>
#include <string>
#include "Node.hpp"
#include "Fact.hpp"
#include <cstdlib>
#include <iostream>
#include "Exceptions.hpp"
#include "Tree.hpp"
#include <map>
#include "ExprSysEnums.hpp"
#include "misc.hpp"

static void		ft_fact_appears(Node* node, Fact* fact_ptr, bool& factAppears)
{	
	if (node->GetType() == nodeType::operation_t) {
		Operation*	oper = dynamic_cast<Operation*>(node);
		ft_fact_appears(oper->GetChild(0), fact_ptr, factAppears);
		if (oper->GetChild(1))
			ft_fact_appears(oper->GetChild(0), fact_ptr, factAppears);
	}
	else {
		Fact* fact = dynamic_cast<Fact*>(node);
		std::cout << "Checking provided: " << fact_ptr->GetKey() << std::endl;
		std::cout << "Checking found: " << fact->GetKey() << std::endl;
		std::cout << "fACT FOUND: " << (fact_ptr->GetKey() == fact->GetKey()) << std::endl;
		if (fact_ptr->GetKey() == fact->GetKey())
			factAppears = true;
	}
}

static std::vector< size_t>			ft_gather_rules(Fact* fact_ptr, std::vector<Tree*> treeStrg, bool& hasRules)
{
	std::vector<size_t> 	facts_rules;
	bool					factAppearsInRule = false;

	std::cout << "LOL1" << std::endl;
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		ft_fact_appears(treeStrg[i]->GetRoot()->GetChild(1), fact_ptr, factAppearsInRule);
		std::cout << "FOUND RULE " << factAppearsInRule << std::endl; 
		if (factAppearsInRule) {
			factAppearsInRule = false;
			if ( treeStrg[i]->GetVisited() ) {
				std::cout << "Cycle" << std::endl;
				hasRules = true;
				continue ;
			}
			else {
				std::cout << "Pushing rule #" << i << std::endl;
				facts_rules.push_back(i);
			}
		}
		// if (factAppearsInRule && treeStrg[i]->GetVisited()) {
			// std::cout << "Cycle" << std::endl;
		// 	hasRules = true;
		// 	continue ;
		// }
		// else {
		// 	facts_rules.push_back(i);
		// }

		// Tree*	tree = treeStrg[i];
		// if (tree->GetRoot()->GetChild(1)->GetType() == nodeType::operation_t)
		// {
		// 	if ( fact_ptr->GetKey() == tree->GetRoot()->GetChild(1)->GetChild(0)->GetKey() )
		// 		facts_rules.push_back(i);
		// 	else if ( tree->GetRoot()->GetChild(1)->GetChild(1) && fact_ptr->GetKey() == tree->GetRoot()->GetChild(1)->GetChild(1)->GetKey() )
		// 		facts_rules.push_back(i);
		// }
		// else if ( fact_ptr->GetKey() == tree->GetRoot()->GetChild(1)->GetKey() )
		// 	facts_rules.push_back(i);
	}
	std::cout << "facts_rules size: " << facts_rules.size() << std::endl;
	return (facts_rules);
}

factValues		ft_evaluate_lpart( Node * node, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{	
	std::cout << "LOL Evaluate LPART" << std::endl;
	if (node->GetType() == nodeType::operation_t) {
		Operation*	oper = dynamic_cast<Operation*>(node);
		std::cout << "Operation" << std::endl;
		if (oper->GetChild(1))
			return (oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0), treeStrg, factsStrg), ft_evaluate_lpart(oper->GetChild(1), treeStrg, factsStrg)));
		else
			return (oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0), treeStrg, factsStrg)));
	}
	else {
		Fact* fact = dynamic_cast<Fact*>(node);
		std::cout << "Fact - " << fact->GetKey() << std::endl;
		ft_process_fact(fact->GetKey(), treeStrg, factsStrg);
		return (fact->GetValue());
	}
}

void			ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{

	bool					hasVisitedRules = false;
	Fact*					fact_ptr = factsStrg[fact];
	std::vector<size_t> 	facts_rules = ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules); // gather rules with fact in right side of expression
	factValues				rvalue = factValues::True;

	// if there is no rules to set fact with any value
	if (!facts_rules.size() && !hasVisitedRules && fact_ptr->GetValue() == factValues::Processing)
		fact_ptr->SetValue(factValues::False);
	//if all rules are visited, but couldn't resolve rules due to cycles
	// A + B => C
	// C + B => A
	// ?CA -> Undetermined
	if (fact_ptr->GetValue() == factValues::Processing && hasVisitedRules)
		fact_ptr->SetValue(factValues::Undetermined);

	if ( !facts_rules.size() )
		return ;
	for (size_t i = facts_rules.front(); facts_rules.size(); facts_rules = ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules)) {
		try {

			std::cout << "LOLB" << std::endl;
			if (fact_ptr->GetValue() == factValues::Processing) {
				std::cout << "LOLProcessing rule #" << std::to_string(i) << std::endl;
				treeStrg[i]->SetVisited();
				rvalue = treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																		treeStrg[i]->GetRoot()->GetChild(1) );
				if (rvalue == factValues::False && !ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules).size())
					fact_ptr->SetValue(rvalue);
			} else {
				if (!treeStrg[i]->GetVisited())
					treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																		treeStrg[i]->GetRoot()->GetChild(1) );
			}
		} catch (RuleContradictionException& e) {
			std::cerr << e.what_exception(i) << std::endl;
		} catch (NotImplementedException& e) {
			std::cerr << e.what_exception(i) << std::endl;
		} catch (RuleEvaluatingException& e) {
			std::cerr << e.what_exception(i) << std::endl;
		}
	}

	// //if all rules are visited, but couldn't resolve rules due to cycles
	// // A + B => C
	// // C + B => A
	// // ?CA -> Undetermined
	// if (fact_ptr->GetValue() == factValues::Processing && hasVisitedRules)
	// 	fact_ptr->SetValue(factValues::Undetermined);
}
