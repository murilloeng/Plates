#pragma once

//Qt
#include "QtWidgets/QDialog"

namespace Ui { class Load; }
namespace fea { class Load; }
namespace gui { class Canvas; }

namespace gui
{
	class Load : public QDialog
	{
	public:
		//constructor
		Load(QWidget*, fea::Load*, Canvas*);

		//destructor
		~Load(void);

	private:
		//slot
		void slot(void);

		//data
		Ui::Load* m_ui;
		Canvas* m_canvas;
		fea::Load* m_load;
	};
}