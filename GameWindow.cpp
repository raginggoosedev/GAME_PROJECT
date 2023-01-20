//#include <glad/glad.h>
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
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
		glfwSetWindowSize(window, width, height);
		
	}

	void setWidth(int width)
	{
		this->width = width;
		glfwSetWindowSize(window, width, height);
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

	void setBackground(int red, int green, int blue)
	{
		float r = red/255;
		float g = green/255;
		float b = blue/255;
		glClearColor(r,g,b,1.0f);
	}

	void drawLine()
	{
		//glPointSize(10);
		//glLineWidth(2.5); 
		// glColor3f(1.0, 0.0, 0.0);
		// glBegin(GL_LINES);
		// glVertex3f(10.0,10.0,0.0);
		// glVertex3f(200.0,200.0,0.0);
		// glEnd();

	}
};