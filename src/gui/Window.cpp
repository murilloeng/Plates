//Qt
#include "QtGui/QKeyEvent"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QHBoxLayout"
#include "QtWidgets/QVBoxLayout"

//Plates
#include "Plates/inc/gui/Mesh.hpp"
#include "Plates/inc/gui/Load.hpp"
#include "Plates/inc/gui/Window.hpp"
#include "Plates/inc/gui/Drawing.hpp"
#include "Plates/inc/gui/Material.hpp"
#include "Plates/inc/gui/Geometry.hpp"
#include "Plates/build/uic/Window.hpp"

namespace gui
{
	//constructor
	Window::Window(void) : m_ui{new Ui::Window}
	{
		//data
		m_ui->setupUi(this);
		//setup
		setup_canvas();
		setWindowTitle("Plates");
		//connect
		QObject::connect(m_ui->tool_mesh, &QToolButton::clicked, this, &Window::slot_mesh);
		QObject::connect(m_ui->tool_load, &QToolButton::clicked, this, &Window::slot_load);
		QObject::connect(m_ui->tool_drawing, &QToolButton::clicked, this, &Window::slot_drawing);
		QObject::connect(m_ui->tool_geometry, &QToolButton::clicked, this, &Window::slot_geometry);
		QObject::connect(m_ui->tool_material, &QToolButton::clicked, this, &Window::slot_material);
	}

	//destructor
	Window::~Window(void)
	{
		delete m_ui;
	}

	//slots
	void Window::slot_load(void)
	{
		Load(this, &m_plate.load(), m_ui->canvas).exec();
	}
	void Window::slot_mesh(void)
	{
		Mesh(this, &m_plate.mesh(), m_ui->canvas).exec();
	}
	void Window::slot_drawing(void)
	{
		Drawing(this, &m_plate.drawing(), m_ui->canvas).exec();
	}
	void Window::slot_geometry(void)
	{
		Geometry(this, &m_plate.geometry(), m_ui->canvas).exec();
	}
	void Window::slot_material(void)
	{
		Material(this, &m_plate.material(), m_ui->canvas).exec();
	}

	//setup
	void Window::setup_canvas(void)
	{
		m_ui->canvas->plate(&m_plate);
	}

	//callbacks
	void Window::keyPressEvent(QKeyEvent* event)
	{
		//close
		if(event->key() == Qt::Key::Key_Escape) close();
	}
}