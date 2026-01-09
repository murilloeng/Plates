#pragma once

//Qt
#include "QtOpenGLWidgets/QOpenGLWidget"

//Canvas
#include "Canvas/Canvas/inc/API/Loader.hpp"
#include "Canvas/Canvas/inc/Scene/Scene.hpp"

//Plates
#include "Plates/inc/Plate.hpp"

class Canvas : public QOpenGLWidget
{
public:
	//constructor
	Canvas(QWidget*);

	//destructor
	~Canvas(void);

	//data
	void plate(Plate*);
	canvas::Scene* scene(void);

private:
	//OpenGL
	void paintGL(void) override;
	void resizeGL(int, int) override;
	void initializeGL(void) override;

	//data
	Plate* m_plate;
	canvas::Scene* m_scene;
};