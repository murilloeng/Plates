#pragma once

//Qt
#include "QtOpenGLWidgets/QOpenGLWidget"

//Canvas
#include "Canvas/Canvas/inc/API/Loader.hpp"
#include "Canvas/Canvas/inc/Scene/Scene.hpp"

//Plates
#include "Plates/inc/fea/Plate.hpp"

namespace gui
{
	class Canvas : public QOpenGLWidget
	{
	public:
		//constructor
		Canvas(QWidget*);

		//destructor
		~Canvas(void);

		//data
		void plate(fea::Plate*);
		canvas::Scene* scene(void);

	private:
		//OpenGL
		void paintGL(void) override;
		void resizeGL(int, int) override;
		void initializeGL(void) override;

		//events
		void resizeEvent(QResizeEvent*) override;

		//data
		fea::Plate* m_plate;
		canvas::Scene* m_scene;
	};
}