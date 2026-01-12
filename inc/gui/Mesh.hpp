#pragma once

//Qt
#include "QtWidgets/QDialog"

namespace fea
{
	class Mesh;
}
namespace gui
{
	class Canvas;
}
namespace Ui
{
	class Mesh;
}

namespace gui
{
	class Mesh : public QDialog
	{
	public:
		//constructor
		Mesh(QWidget*, fea::Mesh*, Canvas*);

		//destructor
		~Mesh(void);

	private:
		//slot
		void slot(void);

		//data
		Ui::Mesh* m_ui;
		Canvas* m_canvas;
		fea::Mesh* m_mesh;
	};
}