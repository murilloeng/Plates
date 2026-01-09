//std
#include <cstdio>
#include <stdexcept>

//plate
#include "Plate/inc/Application.hpp"

int main(void)
{
	try
	{
		Application application;
	}
	catch(const std::exception& e)
	{
		printf("%s\n", e.what());
	}
	return 0;
}