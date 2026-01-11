#pragma once

//std
#include <cstdint>

namespace fea
{
	class Load
	{
	public:
		//constructor
		Load(void);

		//destructor
		~Load(void);

		//types
		enum Type : uint32_t
		{
			ponctual,
			distributed
		};

		//data
		Type type(Type);
		Type type(void) const;

		double value(double);
		double value(void) const;

	private:
		//data
		Type m_type;
		double m_value;
	};
}