#include "LogicOperations.hpp"
#include "main.hpp"
	bool			ExpSys::Conjunction::Evaluate( void )
	{
		ExpSys::Node const*	lfact = static_cast<ExpSys::Fact*>this->GetChild(0);
		ExpSys::Node const*	rfact = static_cast<ExpSys::Fact*>this->GetChild(1);

		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (lfact->GetValue() && rfact->GetValue());
	}

	bool			ExpSys::Negation::Evaluate( void )
	{
		ExpSys::Fact*	lfact = this->GetChild(0);
		
		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (!(lfact->GetValue()));
	}

	bool			ExpSys::Disjunction::Evaluate( void )
	{
		ExpSys::Fact*	lfact = this->GetChild(0);
		ExpSys::Fact*	rfact = this->GetChild(1);

		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return (lfact->GetValue() || rfact->GetValue());
	}

	bool			ExpSys::ExclDisjunction::Evaluate( void )
	{
		ExpSys::Fact*	lfact = this->GetChild(0);
		ExpSys::Fact*	rfact = this->GetChild(1);

		assert(); // ask if lfact or rfact ->GetValue() is Undetermined
		return ((lfact->GetValue() && !rfact->GetValue()) ||
			(!lfact->GetValue() && rfact->GetValue()));
	}

	bool			ExpSys::Implication::Evaluate( bool rvalue )
	{
		ExpSys::Fact*	lfact = this->GetChild(0);
		ExpSys::Fact*	rfact = this->GetChild(1);

		if (rfact->GetValue() == ExpSys::factValues::Undetermined)
			rfact->SetValue( (rvalue) ? ExpSys::factValues::True : ExpSys::factValues::False );
		else
		{
			if ( rfact->GetValue() )
		}


	}

	bool			ExpSys::IFOIF::Evaluate( void )
	{
		
	}

#endif