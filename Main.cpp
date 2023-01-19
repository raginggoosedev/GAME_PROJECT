#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void) 
{
	//Initilizes
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Programming Project", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window))
	{

		//glClear(GL_COLOR_BUFFER_BIT);

		//glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}