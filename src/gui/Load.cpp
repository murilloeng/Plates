//Plates
#include "Plates/inc/gui/Load.hpp"
#include "Plates/inc/fea/Load.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/build/uic/Load.hpp"

static double(fea::Load::* functions_set[])(double) = {
	&fea::Load::value
};
static double(fea::Load::* functions_get[])(void) const = {
	&fea::Load::value
};

namespace gui
{
	//constructor
	Load::Load(QWidget* parent, fea::Load* load, Canvas* canvas) : 
		QDialog(parent), m_ui{ new Ui::Load }, m_canvas{ canvas }, m_load{ load }
	{
		//data
		m_ui->setupUi(this);
		m_ui->combo_type->setCurrentIndex(uint32_t(m_load->type()));
		m_ui->edit_value->setText(QString::asprintf("%+.6e", m_load->value()));
		//connect
		QObject::connect(m_ui->edit_value, &QLineEdit::editingFinished, this, &Load::slot);
	}

	//destructor
	Load::~Load(void)
	{
		delete m_ui;
	}

	//slot
	void Load::slot(void)
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
				double value_old = (m_load->*functions_get[i])();
				const double value_new = edits[i]->text().toDouble(&test);
				if (test && value_new != value_old)
				{
					value_old = value_new;
					(m_load->*functions_set[i])(value_new);
				}
				edits[i]->setText(QString::asprintf("%+.6e", value_old));
			}
		}
	}
}