#include "LogicOperations.hpp"
#include "main.hpp"
	bool			ExpSys::Conjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (lfact->GetValue() && rfact->GetValue());
	}

	bool			ExpSys::Negation::Evaluate( ExpSys::Fact const* fact )
	{	
		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (!(fact->GetValue()));
	}

	bool			ExpSys::Disjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (lfact->GetValue() || rfact->GetValue());
	}

	bool			ExpSys::ExclDisjunction::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return ((lfact->GetValue() && !rfact->GetValue()) ||
			(!lfact->GetValue() && rfact->GetValue()));
	}

	bool			ExpSys::Implication::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		if (rfact->GetValue() == ExpSys::factValues::Undetermined)
			rfact->SetValue( (rvalue) ? ExpSys::factValues::True : ExpSys::factValues::False );
		else
		{
			if ( rfact->GetValue() )
		}


	}

	bool			ExpSys::IFOIF::Evaluate( ExpSys::Fact const* lfact, ExpSys::Fact const* rfact )
	{
		
	}

#endif