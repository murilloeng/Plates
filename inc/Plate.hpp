#pragma once

//canvas
#include "Canvas/Canvas/inc/Objects/Object.hpp"

class Plate : public canvas::objects::Object
{
public:
	//constructor
	Plate(void);

	//destructor
	~Plate(void);

private:
	//buffers
	void buffers_size(void) override;
	void buffers_data(void) const override;

	//data
	double m_width;
	double m_height;
	double m_radius;
};