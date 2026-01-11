//Plates
#include "Plates/inc/fea/Drawing.hpp"

namespace fea
{
	//constructor
	Drawing::Drawing(void) : m_type(Type::model)
	{
		return;
	}

	//destructor
	Drawing::~Drawing(void)
	{
		return;
	}

	//data
	Drawing::Type Drawing::type(Type type)
	{
		return m_type = type;
	}
	Drawing::Type Drawing::type(void) const
	{
		return m_type;
	}
}