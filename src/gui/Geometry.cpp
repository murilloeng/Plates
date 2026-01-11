//Plate
#include "Plates/inc/fea/Plate.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/inc/gui/Geometry.hpp"

#include "Plates/build/uic/Geometry.hpp"

static double(fea::Plate::* functions_set[])(double) = {
	&fea::Plate::width,
	&fea::Plate::height,
	&fea::Plate::radius,
	&fea::Plate::thickness
};
static double(fea::Plate::* functions_get[])(void) const = {
	&fea::Plate::width,
	&fea::Plate::height,
	&fea::Plate::radius,
	&fea::Plate::thickness
};

namespace gui
{
	//constructor
	Geometry::Geometry(QWidget* parent, fea::Plate* plate, Canvas* canvas) :
		QDialog(parent), m_plate{ plate }, m_canvas{ canvas }, m_ui{ new Ui::Geometry }
	{
		//data
		m_ui->setupUi(this);
		m_ui->combo_type->setCurrentIndex(uint32_t(m_plate->geometry()));
		m_ui->edit_width->setText(QString::asprintf("%+.6e", m_plate->width()));
		m_ui->edit_height->setText(QString::asprintf("%+.6e", m_plate->height()));
		m_ui->edit_radius->setText(QString::asprintf("%+.6e", m_plate->radius()));
		m_ui->edit_thickness->setText(QString::asprintf("%+.6e", m_plate->thickness()));
		//visibility
		m_ui->edit_radius->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->label_radius->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->edit_width->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->label_width->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->edit_height->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->label_height->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
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
				double value_old = (m_plate->*functions_get[i])();
				const double value_new = edits[i]->text().toDouble(&test);
				if (test && value_new != value_old)
				{
					//data
					value_old = value_new;
					(m_plate->*functions_set[i])(value_new);
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