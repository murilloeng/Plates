//canvas
#include "Canvas/Canvas/inc/Scene/Scene.hpp"
#include "Canvas/Canvas/inc/Vertices/Model3D.hpp"

//plates
#include "Plates/inc/Plate.hpp"

//constructor
Plate::Plate(void) :
	m_width{1}, m_height{1}, m_radius{1}, 
	m_load{Load::ponctual}, m_geometry{Geometry::rectangle}, 
	m_mesh_angle{10}, m_mesh_width{10}, m_mesh_height{10}, m_mesh_radius{10}
{
	return;
}

//destructor
Plate::~Plate(void)
{
	return;
}

//data
double Plate::width(void) const
{
	return m_width;
}
double Plate::width(double width)
{
	return m_width = width;
}

double Plate::height(void) const
{
	return m_height;
}
double Plate::height(double height)
{
	return m_height = height;
}

double Plate::radius(void) const
{
	return m_radius;
}
double Plate::radius(double radius)
{
	return m_radius = radius;
}

Plate::Load Plate::load(void) const
{
	return m_load;
}
Plate::Load Plate::load(Load load)
{
	return m_load = load;
}

Plate::Geometry Plate::geometry(void) const
{
	return m_geometry;
}
Plate::Geometry Plate::geometry(Geometry geometry)
{
	return m_geometry = geometry;
}

uint32_t Plate::mesh_angle(void) const
{
	return m_mesh_angle;
}
uint32_t Plate::mesh_angle(uint32_t mesh_angle)
{
	return m_mesh_angle = mesh_angle;
}

uint32_t Plate::mesh_width(void) const
{
	return m_mesh_width;
}
uint32_t Plate::mesh_width(uint32_t mesh_width)
{
	return m_mesh_width = mesh_width;
}

uint32_t Plate::mesh_height(void) const
{
	return m_mesh_height;
}
uint32_t Plate::mesh_height(uint32_t mesh_height)
{
	return m_mesh_height = mesh_height;
}

uint32_t Plate::mesh_radius(void) const
{
	return m_mesh_radius;
}
uint32_t Plate::mesh_radius(uint32_t mesh_radius)
{
	return m_mesh_radius = mesh_radius;
}

//buffers
void Plate::buffers_size(void)
{
	m_vbo_size[0] = 4;
	m_ibo_size[1] = 8;
}
void Plate::buffers_data(void) const
{
	//data
	const float w = float(m_width);
	const float h = float(m_height);
	uint32_t* ibo_ptr = ibo_data(1);
	canvas::vertices::Model3D* vbo_ptr = vbo_data_model_3D();
	//vbo data
	vbo_ptr[0].m_position = {-w / 2, -h / 2, 0};
	vbo_ptr[1].m_position = {+w / 2, -h / 2, 0};
	vbo_ptr[2].m_position = {+w / 2, +h / 2, 0};
	vbo_ptr[3].m_position = {-w / 2, +h / 2, 0};
	for(uint32_t i = 0; i < 4; i++) vbo_ptr[i].m_color = {1, 1, 1};
	//ibo data
	ibo_ptr[2 * 0 + 0] = ibo_ptr[2 * 3 + 1] = 0;
	ibo_ptr[2 * 1 + 0] = ibo_ptr[2 * 0 + 1] = 1;
	ibo_ptr[2 * 2 + 0] = ibo_ptr[2 * 1 + 1] = 2;
	ibo_ptr[2 * 3 + 0] = ibo_ptr[2 * 2 + 1] = 3;
}