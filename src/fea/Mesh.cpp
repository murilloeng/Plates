//Plates
#include "Plates/inc/fea/Mesh.hpp"

namespace fea
{
	//constructor
	Mesh::Mesh(Plate* plate) : 
		m_plate{plate}, m_angle{10}, m_width{10}, m_height{10}, m_radius{10}
	{
		return;
	}

	//destructor
	Mesh::~Mesh(void)
	{
		return;
	}

	//data
	Plate* Mesh::plate(void) const
	{
		return m_plate;
	}

	uint32_t Mesh::angle(void) const
	{
		return m_angle;
	}
	uint32_t Mesh::angle(uint32_t angle)
	{
		return m_angle = angle;
	}

	uint32_t Mesh::width(void) const
	{
		return m_width;
	}
	uint32_t Mesh::width(uint32_t width)
	{
		return m_width = width;
	}

	uint32_t Mesh::height(void) const
	{
		return m_height;
	}
	uint32_t Mesh::height(uint32_t height)
	{
		return m_height = height;
	}

	uint32_t Mesh::radius(void) const
	{
		return m_radius;
	}
	uint32_t Mesh::radius(uint32_t radius)
	{
		return m_radius = radius;
	}
}