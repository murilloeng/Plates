//std
#include <cstdio>
#include <stdexcept>

//Qt
#include "QtWidgets/QApplication"

//plates
#include "Plates/inc/gui/Window.hpp"

int main(int argc, char* argv[])
{
	try
	{
		//application
		QApplication application(argc, argv);
		//window
		gui::Window window;
		window.showMaximized();
		//return
		return application.exec();
	}
	catch(const std::exception& e)
	{
		printf("%s\n", e.what());
	}
	return 0;
}