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

	//start
	void start(void);

private:
	//setup
	void setup_glfw(void);
	void setup_scene(void);
	void setup_callbacks(void);

	//callbacks
	static void callback_error(int, const char*);
	static void callback_size(GLFWwindow*, int, int);
	static void callback_key(GLFWwindow*, int, int, int, int);

	//data
	GLFWwindow* m_window;
	canvas::Scene* m_scene;
};