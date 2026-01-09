#pragma once

//std
#include <cstdint>

//canvas
#include "Canvas/Canvas/inc/Objects/Object.hpp"

class Plate : public canvas::objects::Object
{
public:
	//constructor
	Plate(void);

	//destructor
	~Plate(void);

	//types
	enum Geometry : uint32_t
	{
		circle,
		rectangle
	};
	enum Load : uint32_t
	{
		ponctual,
		distributed
	};

	//data
	double width(double);
	double width(void) const;

	double height(double);
	double height(void) const;

	double radius(double);
	double radius(void) const;

	Load load(Load);
	Load load(void) const;

	Geometry geometry(Geometry);
	Geometry geometry(void) const;

	uint32_t mesh_angle(uint32_t);
	uint32_t mesh_angle(void) const;

	uint32_t mesh_width(uint32_t);
	uint32_t mesh_width(void) const;

	uint32_t mesh_height(uint32_t);
	uint32_t mesh_height(void) const;

	uint32_t mesh_radius(uint32_t);
	uint32_t mesh_radius(void) const;

private:
	//buffers
	void buffers_size(void) override;
	void buffers_data(void) const override;

	//data
	double m_width;
	double m_height;
	double m_radius;

	Load m_load;
	Geometry m_geometry;

	uint32_t m_mesh_angle;
	uint32_t m_mesh_width;
	uint32_t m_mesh_height;
	uint32_t m_mesh_radius;
};