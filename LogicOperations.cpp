#include "LogicOperations.hpp"
#include "main.hpp"
	bool			ExpSys::Conjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact  is Undetermined
		return (lfact && rfact);
	}

	bool			ExpSys::Negation::Evaluate( const ExpSys::factValues& fact )
	{	
		assert(); // ask if lfact or rfact  is Undetermined
		return (!fact);
	}

	bool			ExpSys::Disjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact  is Undetermined
		return (lfact || rfact);
	}

	bool			ExpSys::ExclDisjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact  is Undetermined
		return ((lfact && !rfact) || (!lfact && rfact));
	}

	bool			ExpSys::Implication::Evaluate( ExpSys::factValues& value, ExpSys::Fact const* rpart )
	{
		if (rfact == ExpSys::factValues::Undetermined)
			rfact->SetValue( (rvalue) ? ExpSys::factValues::True : ExpSys::factValues::False );
		else
		{
			// if (result != fact_ptr->GetValue())
			// {
			// 	// throw exception, that some rules are conflicting
			// }
		}


	}

	bool			ExpSys::IFOIF::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		
	}

#endif