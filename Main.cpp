#include <iostream>
#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include <GLES2/gl2.h>
//#include <EGL/egl.h>
#include <GLFW/glfw3.h>

int main() 
{
	//Initilizes
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Programming Project", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "The window failed to be created" << std::endl;
		glfwTerminate();
		return -1;
	}

	

	glfwMakeContextCurrent(window);
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}