//Plate
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/fea/Drawing.hpp"
#include "Plates/inc/gui/Drawing.hpp"

#include "Plates/build/uic/Drawing.hpp"

namespace gui
{
	//constructor
	Drawing::Drawing(QWidget* parent, fea::Drawing* drawing, Canvas* canvas) :
		QDialog(parent), m_canvas{canvas}, m_ui{new Ui::Drawing}, m_drawing{drawing}
	{
		//data
		m_ui->setupUi(this);
		for(uint32_t i = 0; i < uint32_t(fea::Drawing::Type::last); i++)
		{
			m_ui->combo_type->addItem(fea::Drawing::type_name(fea::Drawing::Type(i)));
		}
		m_ui->combo_type->setCurrentIndex(uint32_t(m_drawing->type()));
		//connect
		QObject::connect(m_ui->combo_type, &QComboBox::currentIndexChanged, this, &Drawing::slot_combo);
	}

	//destructor
	Drawing::~Drawing(void)
	{
		delete m_ui;
	}

	//slot
	void Drawing::slot_combo(void)
	{
		m_drawing->type(fea::Drawing::Type(m_ui->combo_type->currentIndex()));
	}
}