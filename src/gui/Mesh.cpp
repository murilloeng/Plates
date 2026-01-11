//Plates
#include "Plates/inc/gui/Mesh.hpp"
#include "Plates/inc/fea/Plate.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/build/uic/Mesh.hpp"

static uint32_t(fea::Plate::* functions_set[])(uint32_t) = {
	&fea::Plate::mesh_angle,
	&fea::Plate::mesh_width,
	&fea::Plate::mesh_height,
	&fea::Plate::mesh_radius
};
static uint32_t(fea::Plate::* functions_get[])(void) const = {
	&fea::Plate::mesh_angle,
	&fea::Plate::mesh_width,
	&fea::Plate::mesh_height,
	&fea::Plate::mesh_radius
};

namespace gui
{
	//constructor
	Mesh::Mesh(QWidget* parent, fea::Plate* plate, Canvas* canvas) :
		QDialog(parent), m_ui{new Ui::Mesh}, m_plate{plate}, m_canvas{canvas}
	{
		//data
		m_ui->setupUi(this);
		m_ui->edit_angle->setText(QString::asprintf("%d", m_plate->mesh_angle()));
		m_ui->edit_width->setText(QString::asprintf("%d", m_plate->mesh_width()));
		m_ui->edit_height->setText(QString::asprintf("%d", m_plate->mesh_height()));
		m_ui->edit_radius->setText(QString::asprintf("%d", m_plate->mesh_radius()));
		//visibility
		m_ui->edit_angle->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->edit_radius->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->label_angle->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->label_radius->setVisible(m_plate->geometry() == fea::Plate::Geometry::circle);
		m_ui->edit_width->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->edit_height->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->label_width->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		m_ui->label_height->setVisible(m_plate->geometry() == fea::Plate::Geometry::rectangle);
		//connect
		QObject::connect(m_ui->edit_angle, &QLineEdit::editingFinished, this, &Mesh::slot);
		QObject::connect(m_ui->edit_width, &QLineEdit::editingFinished, this, &Mesh::slot);
		QObject::connect(m_ui->edit_height, &QLineEdit::editingFinished, this, &Mesh::slot);
		QObject::connect(m_ui->edit_radius, &QLineEdit::editingFinished, this, &Mesh::slot);
	}

	//destructor
	Mesh::~Mesh(void)
	{
		delete m_ui;
	}

	//slot
	void Mesh::slot(void)
	{
		bool test;
		QLineEdit* edits[] = {
			m_ui->edit_angle,
			m_ui->edit_width,
			m_ui->edit_height,
			m_ui->edit_radius
		};
		const QObject* sender = QObject::sender();
		for (uint32_t i = 0; i < sizeof(edits) / sizeof(edits[0]); i++)
		{
			if (sender == edits[i])
			{
				uint32_t value_old = (m_plate->*functions_get[i])();
				const uint32_t value_new = edits[i]->text().toUInt(&test);
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
				edits[i]->setText(QString::asprintf("%d", value_old));
			}
		}
	}
}