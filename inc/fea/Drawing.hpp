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
			shear_11,
			shear_22,
			shear_12,
			moment_11,
			moment_22,
			moment_12
		};

		//data
		Type type(Type);
		Type type(void) const;

	private:
		//data
		Type m_type;
	};
}