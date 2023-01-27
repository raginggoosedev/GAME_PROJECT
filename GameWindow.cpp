//#include <glad/glad.h>
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <tgmath.h>

//TODO: Put all buffer/shader code into seperate class

//CREATES THE SHADERS SOURCE CODE
//TODO: Move source code into potentially a .h class 
static const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "	gl_Position = vec4(position, 1.0);\n"
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

	//background color
	int bgRed = 0;
	int bgGreen = 0;
	int bgBlue = 0;

	GLchar infoLog[512];
	GLint success;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLuint VAO, VBO, EBO;
	
	float x1 = 0;
	float y1 = 600;
	float x2 = 800;
	float y2 = 600;
	float x3 = 400;
	float y3 = 0;

	float convertX(float x) {
		x = 2.0*x/800.0 - 1.0;
		return x;
	}

	float convertY(float y) {
		y = 1.0 - 2.0*y/600.0;
		return y;
	}

	GLfloat vertices[9] =
	{
		// -1.0, -1.0, 0.0f,
		// 0.0f, 1.0f, 0.0f,
		// 1.0f, -1.0f, 0.0f
		convertX(x1), convertY(y1), 0.0f,
		convertX(x2), convertY(y2), 0.0f,
		convertX(x3), convertY(y3), 0.0f
	};

	GLuint indices[3]
	{
	//	0 ,3, 5, //Lower Left Triangle
	0,1,2
	//	3, 2, 4, //Lower Right Triangle
	//	1, 4, 5 // Upper Triangle
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
		glClearColor(bgRed, bgGreen, bgBlue, 0.0f);
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
		//Change the background colour
		glClearColor(bgRed, bgGreen, bgBlue, 0.0f);

		//Clear the back buffer and assign a new colour to it
		glClear(GL_COLOR_BUFFER_BIT);

		//Specify to openGl which shader program it should utilise
		glUseProgram(shaderProgram);

		//Bind the VAO in order for openGL to know how to use it
		glBindVertexArray(VAO);

		//Draw the triangles using GL_TRIANGLES as a primitive
		//drawTriangle();

		//Swap the back buffer with the front buffer
		//glfwSwapBuffers(window);

		//Run all other events
		glfwPollEvents();
	}

	bool isRunning()
	{
		return !glfwWindowShouldClose(window);
	}

	void close()
	{
		//Delete all the objects
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteProgram(shaderProgram);

		//Terminate the windiow
		glfwDestroyWindow(window);

		//Terminate GLFW before ending the program
		glfwTerminate();
	}

	void setShaders()
	{
	//TODO: Move to a different class
	//vertex shader
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		//CHECK FOR COMPILING ERRORS IN THE VERTEX SHADER
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n";
		}

		//fragment shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		//CHECK FOR COMPILING ERRORS IN THE FRAGMENT SHADER
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		//CREATE THE SHADER PROGRAM
		shaderProgram = glCreateProgram();

		//ATTACH THE SHADERS TO THE PROGRAM
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		//FINISH WITH THE SHADER PROGRAM
		glLinkProgram(shaderProgram);

		//CHECK FOR ANY LINKING ERRORS
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		//DELETE SHADERS TO BE NEAT
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void setBuffers()
	{
		//CREATE THE BUFFERS
		//Generate the VAO, VBO and EBO and assign each with 1 only object
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		//Make the VAO the current vertex array object by binding it
		glBindVertexArray(VAO);

		//Bind the VBO and assign it as a GL_ARRAY_BUFFER
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//Give the vertices to the VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//Configure the vertex attributes in order for openGL to be able to read the VBO
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		//Enable the attributes so openGL can use it
		glEnableVertexAttribArray(0);

		//Bind both the VBO and VAO to 0 in order to prevent accidental modifications
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

	void drawTriangle()
	{
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
	}

	void setBackground(int red, int green, int blue)
	{
		bgRed = red/255.0;
		bgGreen = green/255.0;
		bgBlue = blue/255.0;
	}
};