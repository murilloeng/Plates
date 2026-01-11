//canvas
#include "Canvas/Canvas/inc/Scene/Scene.hpp"
#include "Canvas/Canvas/inc/Vertices/Model3D.hpp"

//plates
#include "Plates/inc/fea/Plate.hpp"

namespace fea
{
	//constructor
	Plate::Plate(void) :
		m_load_value{0},
		m_load{Load::ponctual}
	{
		return;
	}

	//destructor
	Plate::~Plate(void)
	{
		return;
	}

	//data
	Mesh& Plate::mesh(void)
	{
		return m_mesh;
	}
	Geometry& Plate::geometry(void)
	{
		return m_geometry;
	}
	Material& Plate::material(void)
	{
		return m_material;
	}

	double Plate::load_value(void) const
	{
		return m_load_value;
	}
	double Plate::load_value(double load_value)
	{
		return m_load_value = load_value;
	}

	Plate::Load Plate::load(void) const
	{
		return m_load;
	}
	Plate::Load Plate::load(Load load)
	{
		return m_load = load;
	}

	//buffers
	void Plate::vbo_data_edges(void) const
	{
		//data
		const uint32_t nw = m_mesh.width();
		const uint32_t nh = m_mesh.height();
		const float w = float(m_geometry.width());
		const float h = float(m_geometry.height());
		canvas::vertices::Model3D* vbo_ptr = vbo_data_model_3D();
		//vbo data
		for(uint32_t i = 0; i <= nh; i++)
		{
			for(uint32_t j = 0; j <= nw; j++)
			{
				vbo_ptr[(nw + 1) * i + j].m_position[2] = 0;
				vbo_ptr[(nw + 1) * i + j].m_color = { 1, 1, 1 };
				vbo_ptr[(nw + 1) * i + j].m_position[0] = -w / 2 + w * j / nw;
				vbo_ptr[(nw + 1) * i + j].m_position[1] = -h / 2 + h * i / nh;
			}
		}
	}
	void Plate::vbo_data_faces(void) const
	{
		//data
		const uint32_t nw = m_mesh.width();
		const uint32_t nh = m_mesh.height();
		const float w = float(m_geometry.width());
		const float h = float(m_geometry.height());
		canvas::vertices::Model3D* vbo_ptr = vbo_data_model_3D() + (nw + 1) * (nh + 1);
		//vbo data
		for(uint32_t i = 0; i <= nh; i++)
		{
			for (uint32_t j = 0; j <= nw; j++)
			{
				vbo_ptr[(nw + 1) * i + j].m_position[2] = 0;
				vbo_ptr[(nw + 1) * i + j].m_color = { 0, 0, 1 };
				vbo_ptr[(nw + 1) * i + j].m_position[0] = -w / 2 + w * j / nw;
				vbo_ptr[(nw + 1) * i + j].m_position[1] = -h / 2 + h * i / nh;
			}
		}
	}

	void Plate::ibo_data_edges(void) const
	{
		//data
		uint32_t* ibo_ptr = ibo_data(1);
		const uint32_t nw = m_mesh.width();
		const uint32_t nh = m_mesh.height();
		//ibo data
		for (uint32_t i = 0; i <= nh; i++)
		{
			for (uint32_t j = 0; j < nw; j++)
			{
				ibo_ptr[0] = (nw + 1) * i + j + 0;
				ibo_ptr[1] = (nw + 1) * i + j + 1;
				ibo_ptr += 2;
			}
		}
		for (uint32_t i = 0; i < nh; i++)
		{
			for (uint32_t j = 0; j <= nw; j++)
			{
				ibo_ptr[0] = (nw + 1) * (i + 0) + j;
				ibo_ptr[1] = (nw + 1) * (i + 1) + j;
				ibo_ptr += 2;
			}
		}
	}
	void Plate::ibo_data_faces(void) const
	{
		//data
		uint32_t* ibo_ptr = ibo_data(2);
		const uint32_t nw = m_mesh.width();
		const uint32_t nh = m_mesh.height();
		const uint32_t offset = (nw + 1) * (nh + 1);
		//ibo data
		for (uint32_t i = 0; i < nh; i++)
		{
			for (uint32_t j = 0; j < nw; j++)
			{
				ibo_ptr[0] = (nw + 1) * (i + 0) + j + 0 + offset;
				ibo_ptr[1] = (nw + 1) * (i + 0) + j + 1 + offset;
				ibo_ptr[2] = (nw + 1) * (i + 1) + j + 1 + offset;
				ibo_ptr[3] = (nw + 1) * (i + 0) + j + 0 + offset;
				ibo_ptr[4] = (nw + 1) * (i + 1) + j + 1 + offset;
				ibo_ptr[5] = (nw + 1) * (i + 1) + j + 0 + offset;
				ibo_ptr += 6;
			}
		}
	}

	void Plate::buffers_size(void)
	{
		//data
		const uint32_t nw = m_mesh.width();
		const uint32_t nh = m_mesh.height();
		//bufers
		m_ibo_size[2] = 6 * nw * nh;
		m_vbo_size[0] = 2 * (nw + 1) * (nh + 1);
		m_ibo_size[1] = 2 * (nw + nh + 2 * nw * nh);
	}
	void Plate::buffers_data(void) const
	{
		//vbo data
		vbo_data_edges();
		vbo_data_faces();
		//ibo data
		ibo_data_edges();
		ibo_data_faces();
	}
}