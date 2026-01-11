//Plates
#include "Plates/inc/gui/Loads.hpp"
#include "Plates/inc/fea/Plate.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/build/uic/Loads.hpp"

static double(fea::Plate::* functions_set[])(double) = {
	&fea::Plate::load_value
};
static double(fea::Plate::* functions_get[])(void) const = {
	&fea::Plate::load_value
};

namespace gui
{
	//constructor
	Loads::Loads(QWidget* parent, fea::Plate* plate, Canvas* canvas) : 
		QDialog(parent), m_plate{ plate }, m_canvas{ canvas }, m_ui{ new Ui::Loads }
	{
		//data
		m_ui->setupUi(this);
		m_ui->combo_type->setCurrentIndex(uint32_t(m_plate->load()));
		m_ui->edit_value->setText(QString::asprintf("%+.6e", m_plate->load_value()));
		//connect
		QObject::connect(m_ui->edit_value, &QLineEdit::editingFinished, this, &Loads::slot);
	}

	//destructor
	Loads::~Loads(void)
	{
		delete m_ui;
	}

	//slot
	void Loads::slot(void)
	{
		bool test;
		QLineEdit* edits[] = {
			m_ui->edit_value
		};
		const QObject* sender = QObject::sender();
		for (uint32_t i = 0; i < sizeof(edits) / sizeof(edits[0]); i++)
		{
			if (sender == edits[i])
			{
				double value_old = (m_plate->*functions_get[i])();
				const double value_new = edits[i]->text().toDouble(&test);
				if (test && value_new != value_old)
				{
					value_old = value_new;
					(m_plate->*functions_set[i])(value_new);
				}
				edits[i]->setText(QString::asprintf("%+.6e", value_old));
			}
		}
	}
}