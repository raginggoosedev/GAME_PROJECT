#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow
{
private:
	GLFWwindow* window;
	int height;
	int width;
	const char* title;

public:
	GameWindow(int height, int width, const char* title)
	{
		this->height = height;
		this->width = width;
		this->title = title;
		
		glfwInit();
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGL(); 
	}

	void setHeight(int height)
	{
		this->height = height;
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	void setTitle(const char* title)
	{
		this->title = title;
	}

	int getHeight()
	{
		return height;
	}

	int getWidth()
	{
		return width;
	}

	const char* getTitle()
	{
		return title;
	}

	void run()
	{
		glad_glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window); //swap front and back buffers	
		glfwPollEvents(); //this gets the window to be closeable
	}

	bool isRunning()
	{
		return !glfwWindowShouldClose(window);
	}

	void close()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};