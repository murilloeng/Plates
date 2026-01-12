//Plates
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/fea/Material.hpp"
#include "Plates/inc/gui/Material.hpp"
#include "Plates/build/uic/Material.hpp"

static double(fea::Material::* functions_set[])(double) = {
	&fea::Material::poisson_ratio,
	&fea::Material::elastic_modulus
};
static double(fea::Material::* functions_get[])(void) const = {
	&fea::Material::poisson_ratio,
	& fea::Material::elastic_modulus
};

namespace gui
{
	//constructor
	Material::Material(QWidget* parent, fea::Material* material, Canvas* canvas) :
		QDialog(parent), m_canvas{ canvas }, m_ui{ new Ui::Material }, m_material{ material }
	{
		//data
		m_ui->setupUi(this);
		m_ui->edit_poisson_ratio->setText(QString::asprintf("%+.6e", m_material->poisson_ratio()));
		m_ui->edit_elastic_modulus->setText(QString::asprintf("%+.6e", m_material->elastic_modulus()));
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
				double value_old = (m_material->*functions_get[i])();
				const double value_new = edits[i]->text().toDouble(&test);
				if (test && value_new != value_old)
				{
					value_old = value_new;
					(m_material->*functions_set[i])(value_new);
				}
				edits[i]->setText(QString::asprintf("%+.6e", value_old));
			}
		}
	}
}