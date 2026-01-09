#pragma once

//glfw
#include "external/cpp/inc/GLFW/glfw3.h"

//canvas
#include "Canvas/Canvas/inc/Scene/Scene.hpp"

class Application
{
public:
	//constructor
	Application(void);

	//destructor
	~Application(void);

	//data
	GLFWwindow* m_window;
	canvas::Scene* m_scene;
};