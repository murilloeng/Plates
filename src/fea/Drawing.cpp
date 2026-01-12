//Plates
#include "Plates/inc/fea/Drawing.hpp"

namespace fea
{
	//constructor
	Drawing::Drawing(Plate* plate) : m_type{Type::model}, m_plate{plate}
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

	Plate* Drawing::plate(void) const
	{
		return m_plate;
	}

	//type
	const char8_t* Drawing::type_name(Type type)
	{
		const char8_t* names[] =
		{
			u8"Model",
			u8"DOF u3",
			u8"DOF θ1",
			u8"DOF θ2",
			u8"Shear S11",
			u8"Shear S22",
			u8"Shear S12",
			u8"Moment M11",
			u8"Moment M22",
			u8"Moment M12"
		};
		return names[uint32_t(type)];
	}
	const char8_t* Drawing::type_name(void) const
	{
		return type_name(m_type);
	}
}