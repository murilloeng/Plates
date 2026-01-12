#pragma once

//std
#include <cstdint>

namespace fea
{
	class Plate;
}

namespace fea
{
	class Mesh
	{
	public:
		//constructor
		Mesh(Plate*);

		//destructor
		~Mesh(void);

		//data
		Plate* plate(void) const;

		uint32_t angle(uint32_t);
		uint32_t angle(void) const;

		uint32_t width(uint32_t);
		uint32_t width(void) const;

		uint32_t height(uint32_t);
		uint32_t height(void) const;

		uint32_t radius(uint32_t);
		uint32_t radius(void) const;

	private:
		//data
		Plate* m_plate;
		uint32_t m_angle;
		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_radius;
	};
}