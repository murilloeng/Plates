//std
#include <stdexcept>

//canvas
#include "Canvas/Canvas/inc/API/Loader.hpp"

//plate
#include "Plates/inc/Application.hpp"

//constructor
Application::Application(void)
{
	setup_glfw();
	setup_scene();
	setup_callbacks();
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

//start
void Application::start(void)
{
	glfwMaximizeWindow(m_window);
	while(!glfwWindowShouldClose(m_window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
}

//setup
void Application::setup_glfw(void)
{
	//setup
	if(!glfwInit())
	{
		throw std::runtime_error("GLFW initialization error!");
	}
	//window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(800, 800, "Plate", nullptr, nullptr);
	if(!m_window)
	{
		glfwTerminate();
		throw std::runtime_error("GLFW window initialization error!");
	}
	//context
	glfwMakeContextCurrent(m_window);
	//functions
	canvas::load_functions();
}
void Application::setup_scene(void)
{
	m_scene = new canvas::Scene("../Canvas/Canvas/shd/");
}
void Application::setup_callbacks(void)
{
	glfwSetErrorCallback(callback_error);
	glfwSetKeyCallback(m_window, callback_key);
	glfwSetWindowSizeCallback(m_window, callback_size);
}

//callbacks
void Application::callback_error(int error, const char* description)
{
	//message
	char buffer[1024];
	sprintf(buffer, "GLFW error: %s", description);
	//throw
	throw std::runtime_error(buffer);
}
void Application::callback_size(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void Application::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}