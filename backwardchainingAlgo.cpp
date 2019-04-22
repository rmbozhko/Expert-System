static std::vector< size_t>			ft_gather_rules(Fact * fact_ptr, bool& hasRules)
{
	std::vector<size_t> 	facts_rules;

	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		if (treeStrg[i]->GetVisited()) {
			hasRules = true;
			continue ;
		}

		Tree*	tree = treeStrg[i];
		if (tree->GetRoot()->GetChild(1)->GetType() == nodeType::Operation)
		{
			if ( fact_ptr == tree->GetRoot()->GetChild(1)->GetChild(0)->GetKey() )
				facts_rules.push_back(i);
			else if ( tree->GetRoot()->GetChild(1)->GetChild(1) && fact_ptr == tree->GetRoot()->GetChild(1)->GetChild(1)->GetKey() )
				facts_rules.push_back(i);
		}
		else if ( fact_ptr == tree->GetRoot()->GetChild(1)->GetKey() )
			facts_rules.push_back(i);
	}

	return (facts_rules);
}

factValues		ft_evaluate_lpart( Node * node, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{	
	if (node->GetType() == nodeType::Operation) {
		 Operation *	oper = dynamic_cast< Operation *>(node);

		if (oper->GetChild(1))
			return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0)), ft_evaluate_lpart(oper->GetChild(1))) );
		else
			return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0))) );
	}
	else {
		Fact * fact = dynamic_cast<Fact *>(node)
		ft_process_fact(fact->GetKey(), treeStrg, factsStrg);
		return (fact->GetValue());
	}
} 

Node*		ft_evaluate_rpart(Node* node, factValues& value)
{	
	if (node->GetType() == nodeType::Operation) {
		 Operation *	oper = dynamic_cast< Operation *>(node);
		
		if (oper->GetChild(1))
			return ( oper->Evaluate(ft_evaluate_rpart(oper->GetChild(0)), ft_evaluate_rpart(oper->GetChild(1)), value) );
		else
			return ( oper->Evaluate(ft_evaluate_rpart(oper->GetChild(0)), value) );
	}
	else {
		return (node);
	}
}

void			ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact *> factsStrg)
{
	bool						hasRules = false;
	Fact *					fact_ptr = factsStrg[fact]; // what if unexisting fact will be asked
	 std::vector<size_t> 	facts_rules = ft_gather_rules(fact_ptr, hasRules); // gather rules with fact in right side of expression


	for (size_t j = 0; j <= facts_rules.size(); ++j) {
		size_t i = facts_rules[j];
		if (fact_ptr->GetValue() == factValues::Processing) {
			if (!facts_rules.size()) {
				if (hasRules)
					fact_ptr->SetValue(actValues::Undetermined)
				else
					fact_ptr->SetValue(factValues::False);
			}
			else {
				try {
					treeStrg[i]->SetVisited();
					treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																			treeStrg[i]->GetRoot()->GetChild(1) );
				} catch (RuleContradictionException& e) {
					std::cerr << e.what(i) << std::endl;
				} catch (NotImplementedException& e) {
					std::cerr << e.what(i) << std::endl;
				} catch (RuleEvaluatingException& e) {
					std::cerr << e.what(i) << std::endl;
				}
			}
		}
		else {
			if (!facts_rules.size())
				return ;
			else {
				try {
					if (!treeStrg[i]->GetVisited())
						treeStrg[i]->GetRoot()->Evaluate( ft_evaluate_lpart(treeStrg[i]->GetRoot()->GetChild(0), treeStrg, factsStrg),
																			treeStrg[i]->GetRoot()->GetChild(1) );
				} catch (RuleContradictionException& e) {
					std::cerr << e.what(i) << std::endl;
				} catch (NotImplementedException& e) {
					std::cerr << e.what(i) << std::endl;
				} catch (RuleEvaluatingException& e) {
					std::cerr << e.what(i) << std::endl;
				}
			}
		}
	}
}