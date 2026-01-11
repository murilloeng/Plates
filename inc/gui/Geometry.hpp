#pragma once

//Qt
#include "QtWidgets/Qdialog"

namespace fea { class Plate; }
namespace gui { class Canvas; }
namespace Ui { class Geometry; }

namespace gui
{
	class Geometry : public QDialog
	{
	public:
		//constructor
		Geometry(QWidget*, fea::Plate*, Canvas*);

		//destructor
		~Geometry(void);

	private:
		//slot
		void slot(void);

		//data
		Canvas* m_canvas;
		Ui::Geometry* m_ui;
		fea::Plate* m_plate;
	};
}