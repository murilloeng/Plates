#pragma once

//std
#include <cstdint>

namespace fea
{
	class Plate;
}

namespace fea
{
	class Geometry
	{
	public:
		//constructor
		Geometry(Plate*);

		//destructor
		~Geometry(void);

		//types
		enum Type: uint32_t
		{
			circle,
			rectangle
		};

		//data
		Type type(Type);
		Type type(void) const;

		Plate* plate(void) const;

		double width(double);
		double width(void) const;

		double height(double);
		double height(void) const;

		double radius(double);
		double radius(void) const;

		double thickness(double);
		double thickness(void) const;

	private:
		//data
		Type m_type;
		Plate* m_plate;
		double m_width;
		double m_height;
		double m_radius;
		double m_thickness;
	};
}