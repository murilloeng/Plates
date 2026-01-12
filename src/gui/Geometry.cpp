//Plate
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/fea/Geometry.hpp"
#include "Plates/inc/gui/Geometry.hpp"

#include "Plates/build/uic/Geometry.hpp"

static double(fea::Geometry::* functions_set[])(double) = {
	&fea::Geometry::width,
	&fea::Geometry::height,
	&fea::Geometry::radius,
	&fea::Geometry::thickness
};
static double(fea::Geometry::* functions_get[])(void) const = {
	&fea::Geometry::width,
	&fea::Geometry::height,
	&fea::Geometry::radius,
	&fea::Geometry::thickness
};

namespace gui
{
	//constructor
	Geometry::Geometry(QWidget* parent, fea::Geometry* geometry, Canvas* canvas) :
		QDialog(parent), m_canvas{canvas}, m_ui{new Ui::Geometry}, m_geometry{geometry}
	{
		//data
		m_ui->setupUi(this);
		m_ui->combo_type->setCurrentIndex(uint32_t(m_geometry->type()));
		m_ui->edit_width->setText(QString::asprintf("%+.6e", m_geometry->width()));
		m_ui->edit_height->setText(QString::asprintf("%+.6e", m_geometry->height()));
		m_ui->edit_radius->setText(QString::asprintf("%+.6e", m_geometry->radius()));
		m_ui->edit_thickness->setText(QString::asprintf("%+.6e", m_geometry->thickness()));
		//visibility
		m_ui->edit_radius->setVisible(m_geometry->type() == fea::Geometry::Type::circle);
		m_ui->label_radius->setVisible(m_geometry->type() == fea::Geometry::Type::circle);
		m_ui->edit_width->setVisible(m_geometry->type() == fea::Geometry::Type::rectangle);
		m_ui->label_width->setVisible(m_geometry->type() == fea::Geometry::Type::rectangle);
		m_ui->edit_height->setVisible(m_geometry->type() == fea::Geometry::Type::rectangle);
		m_ui->label_height->setVisible(m_geometry->type() == fea::Geometry::Type::rectangle);
		//connect
		QObject::connect(m_ui->edit_width, &QLineEdit::editingFinished, this, &Geometry::slot);
		QObject::connect(m_ui->edit_height, &QLineEdit::editingFinished, this, &Geometry::slot);
		QObject::connect(m_ui->edit_radius, &QLineEdit::editingFinished, this, &Geometry::slot);
		QObject::connect(m_ui->edit_thickness, &QLineEdit::editingFinished, this, &Geometry::slot);
	}

	//destructor
	Geometry::~Geometry(void)
	{
		delete m_ui;
	}

	//slot
	void Geometry::slot(void)
	{
		bool test;
		QLineEdit* edits[] = {
			m_ui->edit_width,
			m_ui->edit_height,
			m_ui->edit_radius,
			m_ui->edit_thickness
		};
		const QObject* sender = QObject::sender();
		for (uint32_t i = 0; i < sizeof(edits) / sizeof(edits[0]); i++)
		{
			if (sender == edits[i])
			{
				double value_old = (m_geometry->*functions_get[i])();
				const double value_new = edits[i]->text().toDouble(&test);
				if (test && value_new != value_old)
				{
					//data
					value_old = value_new;
					(m_geometry->*functions_set[i])(value_new);
					//canvas
					m_canvas->scene()->update(true);
					m_canvas->scene()->camera().bound();
					m_canvas->update();
				}
				edits[i]->setText(QString::asprintf("%+.6e", value_old));
			}
		}
	}
}