#pragma once

//std
#include <cstdint>

namespace fea
{
	class Plate;
}

namespace fea
{
	class Load
	{
	public:
		//constructor
		Load(Plate*);

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

		Plate* plate(void) const;

		double value(double);
		double value(void) const;

	private:
		//data
		Type m_type;
		Plate* m_plate;
		double m_value;
	};
}