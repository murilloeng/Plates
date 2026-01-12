#pragma once

namespace fea
{
	class Plate;
}

namespace fea
{
	class Material
	{
	public:
		//constructor
		Material(Plate*);

		//destructor
		~Material(void);

		//data
		Plate* plate(void) const;

		double poisson_ratio(double);
		double poisson_ratio(void) const;

		double elastic_modulus(double);
		double elastic_modulus(void) const;

	private:
		//data
		Plate* m_plate;
		double m_poisson_ratio;
		double m_elastic_modulus;
	};
}