#include <iostream>
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include <GLES2/gl2.h>
//#include <EGL/egl.h>
#include <GLFW/glfw3.h>

int main() 
{
	bool initialized = glfwInit();

	if (!initialized)
	{
		//initialization didnt work
	}

	//TODO: event error callback

	//initialize window, create context
	GLFWwindow* window = glfwCreateWindow(800, 600, "Game window", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL(); //needed for glad avoid segmentation fault blah blah blah

	//TODO: gladLoadGL(glfwGetProcAddress);

	//TODO: constrain max and min opengl versions
	if (!window)
	{
		//window context creation failed
	}

	

	//MAIN LOOP
	while (!glfwWindowShouldClose(window))
	{
		glad_glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window); //swap front and back buffers	
		glfwPollEvents(); //this gets the window to be closeable
	}

	//TODO: input events

	//destroy window context
	glfwDestroyWindow(window);

	//end application
	glfwTerminate();
	return 0;
}