#pragma once

//Qt
#include "QtWidgets/QDialog"

namespace Ui
{
	class Material;
}
namespace gui
{
	class Canvas;
}
namespace fea
{
	class Material;
}

namespace gui
{
	class Material : public QDialog
	{
	public:
		//constructor
		Material(QWidget*, fea::Material*, Canvas*);

		//destructor
		~Material(void);

	private:
		//slot
		void slot(void);

		//data
		Canvas* m_canvas;
		Ui::Material* m_ui;
		fea::Material* m_material;
	};
}