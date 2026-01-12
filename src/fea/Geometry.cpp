//Plates
#include "Plates/inc/fea/Geometry.hpp"

namespace fea
{
	//constructor
	Geometry::Geometry(Plate* plate) : 
		m_type{Type::rectangle}, m_plate{plate}, 
		m_width{1}, m_height{1}, m_radius{1}, m_thickness{0.1}
	{
		return;
	}

	//destructor
	Geometry::~Geometry(void)
	{
		return;
	}

	//data
	Geometry::Type Geometry::type(Type type)
	{
		return m_type = type;
	}
	Geometry::Type Geometry::type(void) const
	{
		return m_type;
	}

	Plate* Geometry::plate(void) const
	{
		return m_plate;
	}

	double Geometry::width(void) const
	{
		return m_width;
	}
	double Geometry::width(double width)
	{
		return m_width = width;
	}

	double Geometry::height(void) const
	{
		return m_height;
	}
	double Geometry::height(double height)
	{
		return m_height = height;
	}

	double Geometry::radius(void) const
	{
		return m_radius;
	}
	double Geometry::radius(double radius)
	{
		return m_radius = radius;
	}

	double Geometry::thickness(void) const
	{
		return m_thickness;
	}
	double Geometry::thickness(double thickness)
	{
		return m_thickness = thickness;
	}
}