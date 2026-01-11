#pragma once

namespace fea
{
	class Material
	{
	public:
		//constructor
		Material(void);

		//destructor
		~Material(void);

		//data
		double poisson_ratio(double);
		double poisson_ratio(void) const;

		double elastic_modulus(double);
		double elastic_modulus(void) const;

	private:
		//data
		double m_poisson_ratio;
		double m_elastic_modulus;

	};
}