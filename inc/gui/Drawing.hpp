#pragma once

//Qt
#include "QtWidgets/Qdialog"

namespace gui { class Canvas; }
namespace Ui { class Drawing; }
namespace fea { class Drawing; }

namespace gui
{
	class Drawing : public QDialog
	{
	public:
		//constructor
		Drawing(QWidget*, fea::Drawing*, Canvas*);

		//destructor
		~Drawing(void);

	private:
		//slot
		void slot_combo(void);

		//data
		Canvas* m_canvas;
		Ui::Drawing* m_ui;
		fea::Drawing* m_drawing;
	};
}