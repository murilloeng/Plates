#pragma once

//std
#include <cstdint>

//canvas
#include "Canvas/Canvas/inc/Objects/Object.hpp"

//Plates
#include "Plates/inc/fea/Mesh.hpp"
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

		//types
		enum Load : uint32_t
		{
			ponctual,
			distributed
		};
		enum Canvas : uint32_t
		{
			model,
			shear_11,
			shear_22,
			shear_12,
			moment_11,
			moment_22,
			moment_12
		};

		//data
		Mesh& mesh(void);
		Geometry& geometry(void);
		Material& material(void);

		double load_value(double);
		double load_value(void) const;

		Load load(Load);
		Load load(void) const;

	private:
		//buffers
		void vbo_data_edges(void) const;
		void vbo_data_faces(void) const;

		void ibo_data_edges(void) const;
		void ibo_data_faces(void) const;

		void buffers_size(void) override;
		void buffers_data(void) const override;

		//data
		Mesh m_mesh;
		Geometry m_geometry;
		Material m_material;

		Load m_load;
		double m_load_value;
	};
}