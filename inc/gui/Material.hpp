#pragma once

//Qt
#include "QtWidgets/Qdialog"

namespace fea { class Plate; }
namespace gui { class Canvas; }
namespace Ui { class Material; }

namespace gui
{
	class Material : public QDialog
	{
	public:
		//constructor
		Material(QWidget*, fea::Plate*, Canvas*);

		//destructor
		~Material(void);

	private:
		//slot
		void slot(void);

		//data
		Canvas* m_canvas;
		Ui::Material* m_ui;
		fea::Plate* m_plate;
	};
}