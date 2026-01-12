//Plates
#include "Plates/inc/fea/Load.hpp"

namespace fea
{
	//constructor
	Load::Load(Plate* plate) : 
		m_type{Type::ponctual}, m_plate{plate}, m_value{0}
	{
		return;
	}

	//destructor
	Load::~Load(void)
	{
		return;
	}

	//data
	Load::Type Load::type(void) const
	{
		return m_type;
	}
	Load::Type Load::type(Type type)
	{
		return m_type = type;
	}

	Plate* Load::plate(void) const
	{
		return m_plate;
	}

	double Load::value(void) const
	{
		return m_value;
	}
	double Load::value(double value)
	{
		return m_value = value;
	}
}