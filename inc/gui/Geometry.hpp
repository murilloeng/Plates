#pragma once

//Qt
#include "QtWidgets/QDialog"

namespace fea
{
	class Geometry;
}
namespace gui
{
	class Canvas;
}
namespace Ui
{
	class Geometry;
}

namespace gui
{
	class Geometry : public QDialog
	{
	public:
		//constructor
		Geometry(QWidget*, fea::Geometry*, Canvas*);

		//destructor
		~Geometry(void);

	private:
		//slot
		void slot_edit(void);
		void slot_combo(void);

		//data
		Canvas* m_canvas;
		Ui::Geometry* m_ui;
		fea::Geometry* m_geometry;
	};
}