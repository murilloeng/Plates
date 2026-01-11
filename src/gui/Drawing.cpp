//Plate
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/fea/Drawing.hpp"
#include "Plates/inc/gui/Drawing.hpp"

#include "Plates/build/uic/Drawing.hpp"

namespace gui
{
	//constructor
	Drawing::Drawing(QWidget* parent, fea::Drawing* drawing, Canvas* canvas) :
		QDialog(parent), m_drawing{ drawing}, m_canvas{ canvas }, m_ui{ new Ui::Drawing }
	{
		//data
		m_ui->setupUi(this);
	}

	//destructor
	Drawing::~Drawing(void)
	{
		delete m_ui;
	}

	//slot
	void Drawing::slot(void)
	{
		return;
	}
}