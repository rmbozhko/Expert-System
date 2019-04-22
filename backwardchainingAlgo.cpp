static std::vector<const size_t>			ft_gather_rules(Fact const* fact_ptr, bool& hasRules)
{
	std::vector<const size_t> 	facts_rules;

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

static factValues		ft_evaluate_lpart(const Node const* node, std::vector<Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg)
{	
	if (node->GetType() == nodeType::Operation) {
		const Operation const*	oper = dynamic_cast<const Operation const*>(node);

		if (oper->GetChild(1))
			return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0)), ft_evaluate_lpart(oper->GetChild(1))) );
		else
			return ( oper->Evaluate(ft_evaluate_lpart(oper->GetChild(0))) );
	}
	else {
		Fact const* fact = dynamic_cast<Fact const*>(node)
		ft_process_fact(fact->GetKey(), treeStrg, factsStrg);
		return (fact->GetValue());
	}
}

static 

static Node*		ft_evaluate_rpart(Node* node, factValues& value)
{	
	if (node->GetType() == nodeType::Operation) {
		const Operation const*	oper = dynamic_cast<const Operation const*>(node);
		
		if (oper->GetChild(1))
			return ( oper->Evaluate(ft_evaluate_rpart(oper->GetChild(0)), ft_evaluate_rpart(oper->GetChild(1)), value) );
		else
			return ( oper->Evaluate(ft_evaluate_rpart(oper->GetChild(0)), value) );
	}
	else {
		return (node);
	}
}

void			ft_process_fact(const std::string& fact, std::vector<Tree*> treeStrg, std::map<std::string, Fact const*> factsStrg)
{
	bool						hasRules = false;
	Fact const*					fact_ptr = factsStrg[fact]; // what if unexisting fact will be asked
	const std::vector<size_t> 	facts_rules = ft_gather_rules(fact_ptr, hasRules); // gather rules with fact in right side of expression


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