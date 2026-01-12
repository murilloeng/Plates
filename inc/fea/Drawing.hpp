#pragma once

//std
#include <cstdint>

namespace fea
{
	class Drawing
	{
	public:
		//constructor
		Drawing(void);

		//destructor
		~Drawing(void);

		//types
		enum Type: uint32_t
		{
			model,
			displacement_3,
			rotation_1,
			rotation_2,
			shear_11,
			shear_22,
			shear_12,
			moment_11,
			moment_22,
			moment_12,
			last
		};

		//data
		Type type(Type);
		Type type(void) const;

		//type
		const char8_t* type_name(void) const;
		static const char8_t* type_name(Type);

	private:
		//data
		Type m_type;
	};
}