//std
#include <cstdio>
#include <stdexcept>

//plate
#include "Plates/inc/Application.hpp"

int main(void)
{
	try
	{
		Application().start();
	}
	catch(const std::exception& e)
	{
		printf("%s\n", e.what());
	}
	return 0;
}