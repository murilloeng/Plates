//Plates
#include "Plates/inc/fea/Load.hpp"

namespace fea
{
	//constructor
	Load::Load(void) : m_type{ Type::ponctual }, m_value{ 0 }
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

	double Load::value(void) const
	{
		return m_value;
	}
	double Load::value(double value)
	{
		return m_value = value;
	}
}