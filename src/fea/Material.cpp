//Plates
#include "Plates/inc/fea/Material.hpp"

namespace fea
{
	//constructor
	Material::Material(void) :
		m_poisson_ratio(3.00e-01), m_elastic_modulus(2.00e+11)
	{
		return;
	}

	//destructor
	Material::~Material(void)
	{
		return;
	}

	//data
	double Material::poisson_ratio(void) const
	{
		return m_poisson_ratio;
	}
	double Material::poisson_ratio(double poisson_ratio)
	{
		return m_poisson_ratio = poisson_ratio;
	}

	double Material::elastic_modulus(void) const
	{
		return m_elastic_modulus;
	}
	double Material::elastic_modulus(double elastic_modulus)
	{
		return m_elastic_modulus = elastic_modulus;
	}
}