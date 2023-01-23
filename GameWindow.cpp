
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//TODO: Put all buffer/shader code into seperate class
//TEST
//CREATES THE SHADERS SOURCE CODE
//TODO: Move source code into potentially a .h class 
static const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

static const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

class GameWindow
{
private:

	//Variables
	GLFWwindow* window;

	int height;
	int width;
	const char* title;

	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint VAO, VBO;
	GLfloat vertices[9] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};
	

public:
	GameWindow(int height, int width, const char* title)
	{
		//Assigns Variables
		this->height = height;
		this->width = width;
		this->title = title;
		//Intialize GLFW
		glfwInit();
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		glfwMakeContextCurrent(window);

		gladLoadGL();

		//TODO: Create custom variables for viewport dimensions
		glViewport(0, 0, width, height);
		setShaders();
		setBuffers();
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		

		
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
		
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
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

	void setShaders()
	{
	//TODO: Move to a different class
	//vertex shader
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		//fragment shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		//CREATE THE SHADER PROGRAM
		shaderProgram = glCreateProgram();

		//ATTACH THE SHADERS TO THE PROGRAM
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		//FINISH WITH THE SHADER PROGRAM
		glLinkProgram(shaderProgram);

		//DELETE SHADERS TO BE NEAT
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void setBuffers()
	{
		//SET UP BUFFERS
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
  }
	void setBackground(int red, int green, int blue)
	{
		float r = red/255;
		float g = green/255;
		float b = blue/255;
		glClearColor(r,g,b,1.0f);
	}
};