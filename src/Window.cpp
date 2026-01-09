//Qt
#include "QtGui/QKeyEvent"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QHBoxLayout"
#include "QtWidgets/QVBoxLayout"

//Plates
#include "Plates/inc/Window.hpp"
#include "Plates/build/uic/Window.hpp"

static double(Plate::*fun_geometry_set[])(double) = {
	&Plate::width,
	&Plate::height,
	&Plate::radius
};
static double(Plate::*fun_geometry_get[])(void) const = {
	&Plate::width,
	&Plate::height,
	&Plate::radius
};

static uint32_t(Plate::*fun_mesh_set[])(uint32_t) = {
	&Plate::mesh_angle,
	&Plate::mesh_width,
	&Plate::mesh_height,
	&Plate::mesh_radius
};
static uint32_t(Plate::*fun_mesh_get[])(void) const = {
	&Plate::mesh_angle,
	&Plate::mesh_width,
	&Plate::mesh_height,
	&Plate::mesh_radius
};

//constructor
Window::Window(void) : m_ui{new Ui::Window}
{
	//data
	m_ui->setupUi(this);
	//setup
	setup_mesh();
	setup_canvas();
	setup_geometry();
	setWindowTitle("Plates");
	//connect
	connect_mesh();
	connect_geometry();
}

//destructor
Window::~Window(void)
{
	delete m_ui;
}

//slots
void Window::slot_mesh(void)
{
	bool test;
	QLineEdit* edits[] = {
		m_ui->edit_mesh_angle,
		m_ui->edit_mesh_width,
		m_ui->edit_mesh_height,
		m_ui->edit_mesh_radius
	};
	const QObject* sender = QObject::sender();
	for(uint32_t i = 0; i < sizeof(edits) / sizeof(edits[0]); i++)
	{
		if(sender == edits[i])
		{
			uint32_t value_old = (m_plate.*fun_mesh_get[i])();
			const uint32_t value_new = edits[i]->text().toUInt(&test);
			if(test && value_new != value_old)
			{
				value_old = value_new;
				(m_plate.*fun_mesh_set[i])(value_new);
			}
			edits[i]->setText(QString::asprintf("%d", value_old));
		}
	}
}
void Window::slot_geometry(void)
{
	bool test;
	QLineEdit* edits[] = {
		m_ui->edit_geometry_width,
		m_ui->edit_geometry_height,
		m_ui->edit_geometry_radius
	};
	const QObject* sender = QObject::sender();
	for(uint32_t i = 0; i < sizeof(edits) / sizeof(edits[0]); i++)
	{
		if(sender == edits[i])
		{
			double value_old = (m_plate.*fun_geometry_get[i])();
			const double value_new = edits[i]->text().toDouble(&test);
			if(test && value_new != value_old)
			{
				value_old = value_new;
				(m_plate.*fun_geometry_set[i])(value_new);
			}
			edits[i]->setText(QString::asprintf("%+.6e", value_old));
		}
	}
}

//setup
void Window::setup_mesh(void)
{
	m_ui->edit_mesh_angle->setText(QString::asprintf("%d", m_plate.mesh_angle()));
	m_ui->edit_mesh_width->setText(QString::asprintf("%d", m_plate.mesh_width()));
	m_ui->edit_mesh_height->setText(QString::asprintf("%d", m_plate.mesh_height()));
	m_ui->edit_mesh_radius->setText(QString::asprintf("%d", m_plate.mesh_radius()));
	m_ui->edit_mesh_angle->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->edit_mesh_radius->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->label_mesh_angle->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->label_mesh_radius->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->edit_mesh_width->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->edit_mesh_height->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->label_mesh_width->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->label_mesh_height->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
}
void Window::setup_canvas(void)
{
	m_ui->canvas->plate(&m_plate);
}
void Window::setup_geometry(void)
{
	m_ui->combo_geometry_type->setCurrentIndex(uint32_t(m_plate.geometry()));
	m_ui->edit_geometry_width->setText(QString::asprintf("%+.6e", m_plate.width()));
	m_ui->edit_geometry_height->setText(QString::asprintf("%+.6e", m_plate.height()));
	m_ui->edit_geometry_radius->setText(QString::asprintf("%+.6e", m_plate.radius()));
	m_ui->edit_geometry_radius->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->label_geometry_radius->setVisible(m_plate.geometry() == Plate::Geometry::circle);
	m_ui->edit_geometry_width->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->label_geometry_width->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->edit_geometry_height->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
	m_ui->label_geometry_height->setVisible(m_plate.geometry() == Plate::Geometry::rectangle);
}

//connect
void Window::connect_mesh(void)
{
	QObject::connect(m_ui->edit_mesh_angle, &QLineEdit::editingFinished, this, &Window::slot_mesh);
	QObject::connect(m_ui->edit_mesh_width, &QLineEdit::editingFinished, this, &Window::slot_mesh);
	QObject::connect(m_ui->edit_mesh_height, &QLineEdit::editingFinished, this, &Window::slot_mesh);
	QObject::connect(m_ui->edit_mesh_radius, &QLineEdit::editingFinished, this, &Window::slot_mesh);
}
void Window::connect_geometry(void)
{
	QObject::connect(m_ui->edit_geometry_width, &QLineEdit::editingFinished, this, &Window::slot_geometry);
	QObject::connect(m_ui->edit_geometry_height, &QLineEdit::editingFinished, this, &Window::slot_geometry);
	QObject::connect(m_ui->edit_geometry_radius, &QLineEdit::editingFinished, this, &Window::slot_geometry);
}

//callbacks
void Window::keyPressEvent(QKeyEvent* event)
{
	//close
	if(event->key() == Qt::Key::Key_Escape) close();
}