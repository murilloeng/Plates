#pragma once

//std
#include <cstdint>

//canvas
#include "Canvas/Canvas/inc/Objects/Object.hpp"

//Plates
#include "Plates/inc/fea/Load.hpp"
#include "Plates/inc/fea/Mesh.hpp"
#include "Plates/inc/fea/Drawing.hpp"
#include "Plates/inc/fea/Geometry.hpp"
#include "Plates/inc/fea/Material.hpp"

namespace fea
{
	class Plate : public canvas::objects::Object
	{
	public:
		//constructor
		Plate(void);

		//destructor
		~Plate(void);

		//data
		Load& load(void);
		Mesh& mesh(void);
		Drawing& drawing(void);
		Geometry& geometry(void);
		Material& material(void);

	private:
		//buffers
		void vbo_data_edges(void) const;
		void vbo_data_faces(void) const;

		void ibo_data_edges(void) const;
		void ibo_data_faces(void) const;

		void buffers_size(void) override;
		void buffers_data(void) const override;

		//data
		Load m_load;
		Mesh m_mesh;
		Drawing m_drawing;
		Geometry m_geometry;
		Material m_material;
	};
}