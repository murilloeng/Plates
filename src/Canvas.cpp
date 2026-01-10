//std
#include <cstdint>

//Qt
#include "QtGui/QPainterPath"

//Plates
#include "Plates/inc/Canvas.hpp"

//constructor
Canvas::Canvas(QWidget* parent) : QOpenGLWidget(parent), m_scene{nullptr}
{
	return;
}

//destructor
Canvas::~Canvas(void)
{
	//objects
	m_scene->clear_objects(false);
	//scene
	delete m_scene;
}

//data
void Canvas::plate(Plate* plate)
{
	m_plate = plate;
}
canvas::Scene* Canvas::scene(void)
{
	return m_scene;
}

//OpenGL
void Canvas::paintGL(void)
{
	m_scene->draw();
}
void Canvas::resizeGL(int width, int height)
{
	m_scene->camera().callback_reshape(width, height);
	m_scene->update(false);
}
void Canvas::initializeGL(void)
{
	//scene
	canvas::load_functions();
	m_scene = new canvas::Scene("../Canvas/Canvas/shd/");
	//objects
	m_scene->add_object(m_plate);
	//update
	m_scene->update(true);
}

//events
void Canvas::resizeEvent(QResizeEvent* event)
{
	QPainterPath path;
	const uint32_t radius = 16;
	QOpenGLWidget::resizeEvent(event);
	path.addRoundedRect(rect(), radius, radius);
	setMask(QRegion(path.toFillPolygon().toPolygon()));
}