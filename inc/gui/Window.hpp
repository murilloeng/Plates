#pragma once

//Qt
#include "QtWidgets/QMainWindow"

//plates
#include "Plates/inc/fea/Plate.hpp"

namespace Ui
{
	class Window;
}

namespace gui
{
	class Window : public QMainWindow
	{
	public:
		//constructor
		Window(void);

		//destructor
		~Window(void);

	private:
		//slots
		void slot_load(void);
		void slot_mesh(void);
		void slot_drawing(void);
		void slot_geometry(void);
		void slot_material(void);

		//setup
		void setup_canvas(void);

		//callbacks
		void keyPressEvent(QKeyEvent*) override;

		//data
		Ui::Window* m_ui;
		fea::Plate m_plate;
	};
}