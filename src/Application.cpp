//std
#include <stdexcept>

//canvas
#include "Canvas/Canvas/inc/API/Loader.hpp"

//plate
#include "Plate/inc/Application.hpp"

//callbacks
static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

//constructor
Application::Application(void)
{
	//setup
	if(!glfwInit())
	{
		throw std::runtime_error("GLFW initialization error!");
	}
	//window
	m_window = glfwCreateWindow(800, 800, "Plate", nullptr, nullptr);
	if(!m_window)
	{
		throw std::runtime_error("GLFW window initialization error!");
	}
	//context
	glfwMakeContextCurrent(m_window);
	//callbacks
	glfwSetKeyCallback(m_window, callback_key);
	//scene
	canvas::load_functions();
	m_scene = new canvas::Scene("../Canvas/Canvas/shd/");
	//main loop
	while(!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
}

//destructor
Application::~Application(void)
{
	//scene
	delete m_scene;
	//window
	glfwDestroyWindow(m_window);
	//glfw
	glfwTerminate();
}