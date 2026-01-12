#pragma once

//std
#include <cstdint>

namespace fea
{
	class Plate;
}

namespace fea
{
	class Drawing
	{
	public:
		//constructor
		Drawing(Plate*);

		//destructor
		~Drawing(void);

		//types
		enum Type: uint32_t
		{
			model,
			dof_u3, dof_t1, dof_t2,
			shear_S11, shear_S22, shear_S12,
			moment_M11, moment_M22, moment_M12,
			last
		};

		//data
		Type type(Type);
		Type type(void) const;

		Plate* plate(void) const;

		//type
		const char8_t* type_name(void) const;
		static const char8_t* type_name(Type);

	private:
		//data
		Type m_type;
		Plate* m_plate;
	};
}