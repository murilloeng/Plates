#pragma once

//Qt
#include "QtWidgets/QMainWindow"

//plates
#include "Plates/inc/Plate.hpp"

namespace Ui
{
	class Window;
}

class Window : public QMainWindow
{
public:
	//constructor
	Window(void);

	//destructor
	~Window(void);

private:
	//slots
	void slot_mesh(void);
	void slot_geometry(void);

	//setup
	void setup_mesh(void);
	void setup_canvas(void);
	void setup_geometry(void);

	//connect
	void connect_mesh(void);
	void connect_geometry(void);

	//callbacks
	void keyPressEvent(QKeyEvent*) override;

	//data
	Plate m_plate;
	Ui::Window* m_ui;
};