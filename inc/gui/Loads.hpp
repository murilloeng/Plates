#pragma once

//Qt
#include "QtWidgets/QDialog"

namespace Ui { class Loads; }
namespace fea { class Plate; }
namespace gui { class Canvas; }

namespace gui
{
	class Loads : public QDialog
	{
	public:
		//constructor
		Loads(QWidget*, fea::Plate*, Canvas*);

		//destructor
		~Loads(void);

	private:
		//slot
		void slot(void);

		//data
		Ui::Loads* m_ui;
		Canvas* m_canvas;
		fea::Plate* m_plate;
	};
}