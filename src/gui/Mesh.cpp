//Plates
#include "Plates/inc/gui/Mesh.hpp"
#include "Plates/inc/fea/Mesh.hpp"
#include "Plates/inc/gui/Canvas.hpp"
#include "Plates/build/uic/Mesh.hpp"

static uint32_t(fea::Mesh::* functions_set[])(uint32_t) = {
	&fea::Mesh::angle,
	&fea::Mesh::width,
	&fea::Mesh::height,
	&fea::Mesh::radius
};
static uint32_t(fea::Mesh::* functions_get[])(void) const = {
	&fea::Mesh::angle,
	&fea::Mesh::width,
	&fea::Mesh::height,
	&fea::Mesh::radius
};

namespace gui
{
	//constructor
	Mesh::Mesh(QWidget* parent, fea::Mesh* mesh, Canvas* canvas) :
		QDialog(parent), m_ui{new Ui::Mesh}, m_canvas{canvas}, m_mesh{mesh}
	{
		//data
		m_ui->setupUi(this);
		m_ui->edit_angle->setText(QString::asprintf("%d", m_mesh->angle()));
		m_ui->edit_width->setText(QString::asprintf("%d", m_mesh->width()));
		m_ui->edit_height->setText(QString::asprintf("%d", m_mesh->height()));
		m_ui->edit_radius->setText(QString::asprintf("%d", m_mesh->radius()));
		//visibility
		const fea::Geometry::Type type = fea::Geometry::Type::rectangle;
		m_ui->edit_angle->setVisible(type == fea::Geometry::Type::circle);
		m_ui->edit_radius->setVisible(type == fea::Geometry::Type::circle);
		m_ui->label_angle->setVisible(type == fea::Geometry::Type::circle);
		m_ui->label_radius->setVisible(type == fea::Geometry::Type::circle);
		m_ui->edit_width->setVisible(type == fea::Geometry::Type::rectangle);
		m_ui->edit_height->setVisible(type == fea::Geometry::Type::rectangle);
		m_ui->label_width->setVisible(type == fea::Geometry::Type::rectangle);
		m_ui->label_height->setVisible(type == fea::Geometry::Type::rectangle);
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
				uint32_t value_old = (m_mesh->*functions_get[i])();
				const uint32_t value_new = edits[i]->text().toUInt(&test);
				if (test && value_new != value_old)
				{
					//data
					value_old = value_new;
					(m_mesh->*functions_set[i])(value_new);
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