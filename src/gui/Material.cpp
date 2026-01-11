//Plates
#include "Plates/inc/fea/Plate.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/gui/Material.hpp"
#include "Plates/build/uic/Material.hpp"

static double(fea::Plate::* functions_set[])(double) = {
	&fea::Plate::poisson_ratio,
	&fea::Plate::elastic_modulus
};
static double(fea::Plate::* functions_get[])(void) const = {
	&fea::Plate::poisson_ratio,
	& fea::Plate::elastic_modulus
};

namespace gui
{
	//constructor
	Material::Material(QWidget* parent, fea::Plate* plate, Canvas* canvas) :
		QDialog(parent), m_plate{ plate }, m_canvas{ canvas }, m_ui{ new Ui::Material }
	{
		//data
		m_ui->setupUi(this);
		m_ui->edit_poisson_ratio->setText(QString::asprintf("%+.6e", m_plate->poisson_ratio()));
		m_ui->edit_elastic_modulus->setText(QString::asprintf("%+.6e", m_plate->elastic_modulus()));
		//conne
	}

	//destructor
	Material::~Material(void)
	{
		delete m_ui;
	}

	//slot
	void Material::slot(void)
	{
		bool test;
		QLineEdit* edits[] = {
			m_ui->edit_poisson_ratio,
			m_ui->edit_elastic_modulus
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