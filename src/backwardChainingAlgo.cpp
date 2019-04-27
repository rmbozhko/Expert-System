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
			ft_fact_appears(oper->GetChild(1), fact_ptr, factAppears);
	}
	else {
		Fact* fact = dynamic_cast<Fact*>(node);
		if (fact_ptr->GetKey() == fact->GetKey())
			factAppears = true;
	}
}

static std::vector< size_t>			ft_gather_rules(Fact* fact_ptr, std::vector<Tree*> treeStrg, bool& hasRules)
{
	std::vector<size_t> 	facts_rules;
	bool					factAppearsInRule = false;
	hasRules = (hasRules) ? !hasRules : !hasRules;
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		ft_fact_appears(treeStrg[i]->GetRoot()->GetChild(1), fact_ptr, factAppearsInRule);
		if (factAppearsInRule) {
			factAppearsInRule = false;
			if ( treeStrg[i]->GetVisited() ) {
				hasRules = true;
				continue ;
			}
			else {
				facts_rules.push_back(i);
			}
		}
	}
	return (facts_rules);
}

factValues		ft_evaluate_lpart( Node * node, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{
	if (node->GetType() == nodeType::operation_t) {
		Operation*	oper = dynamic_cast<Operation*>(node);
		if (oper->GetChild(1))
			return (oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0), treeStrg, factsStrg), ft_evaluate_lpart(oper->GetChild(1), treeStrg, factsStrg)));
		else
			return (oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0), treeStrg, factsStrg)));
	}
	else {
		Fact* fact = dynamic_cast<Fact*>(node);
		ft_process_fact(fact->GetKey(), treeStrg, factsStrg);
		return (fact->GetValue());
	}
}

Node*		ft_evaluate_rpart(Node* node, factValues value)
{	
	if (node->GetType() == nodeType::operation_t) {
		 Operation*	oper = dynamic_cast<Operation*>(node);
		
		if (oper->GetChild(1))
			oper->Assign(ft_evaluate_rpart(oper->GetChild(0), value), ft_evaluate_rpart(oper->GetChild(1), value), value);
		else
			oper->Assign(ft_evaluate_rpart(oper->GetChild(0), value), value);
        return (node);
	}
	else {
		return (node);
	}
}

Node*		ft_evaluate_rpart(Node* node, factValues value, bool isFalseMode)
{	
	if (node->GetType() == nodeType::operation_t) {
		 Operation*	oper = dynamic_cast<Operation*>(node);
		
		if (oper->GetChild(1))
			oper->Assign(ft_evaluate_rpart(oper->GetChild(0), value, isFalseMode), ft_evaluate_rpart(oper->GetChild(1), value, isFalseMode), value);
		else
			oper->Assign(ft_evaluate_rpart(oper->GetChild(0), value, isFalseMode), value);
        return (node);
	}
	else {
		Fact*	fact = dynamic_cast<Fact*>(node);
		if (fact->GetValue() == factValues::Processing && isFalseMode) {
			fact->SetValue(value);
		}
		return (node);
	}
}

void			ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{

	bool					hasVisitedRules = true;
	Fact*					fact_ptr = factsStrg[fact];
	std::vector<size_t> 	facts_rules = ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules);
	factValues				rvalue = factValues::True;

	if (!facts_rules.size() && !hasVisitedRules && fact_ptr->GetValue() == factValues::Processing) {
		fact_ptr->SetValue(factValues::False);
	}

	if ( facts_rules.size() ) {
		for (size_t i = facts_rules.front(); facts_rules.size(); facts_rules = ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules)) {
			i = facts_rules.front();
			try {
				if (fact_ptr->GetValue() == factValues::Processing) {
					treeStrg[i]->SetVisited();
					rvalue = treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																				treeStrg[i]->GetRoot()->GetChild(1) );
					if (rvalue == factValues::False && !ft_gather_rules(fact_ptr, treeStrg, hasVisitedRules).size() && hasVisitedRules) {
						if (treeStrg[i]->GetRoot()->GetChild(1)->GetType() == nodeType::operation_t) {
							ft_evaluate_rpart(treeStrg[i]->GetRoot()->GetChild(1), rvalue, true);
						} else if (fact_ptr->GetValue() == factValues::Processing) {
							fact_ptr->SetValue(factValues::False);
						}
					}
				} else {
					if (!treeStrg[i]->GetVisited())
					{
						treeStrg[i]->SetVisited();
						treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																			treeStrg[i]->GetRoot()->GetChild(1) );
					}
				}
			} catch (RuleContradictionException& e) {
				throw;
			} catch (NotImplementedException& e) {
				throw;
			} catch (RuleEvaluatingException& e) {
				throw;
			}
		}
	}

	if (fact_ptr->GetValue() == factValues::Processing && hasVisitedRules) {
		fact_ptr->SetValue(factValues::Undetermined);
	}
}
