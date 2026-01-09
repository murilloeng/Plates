//canvas
#include "Canvas/Canvas/inc/Vertices/Model3D.hpp"

//plates
#include "Plates/inc/Plate.hpp"

//constructor
Plate::Plate(void) : m_width{1}, m_height{1}, m_radius{1}
{
	return;
}

//destructor
Plate::~Plate(void)
{
	return;
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