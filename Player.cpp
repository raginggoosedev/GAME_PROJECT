#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderVariables.cpp"
#define GLFW_INCLUDE_NONE



class Player
{

private:
	GLuint vertexBuffer, vertexShader, fragmentShader;
	GLint mvpLocation, vposLocation, vcolLocation;
	ShaderVariables* variables;

public:
	GLuint program;

	Player()
	{
		variables = new ShaderVariables();

		//Initilize Variable
		variables->vertex_shader_text = 
		"#version 110\n"
		"uniform mat4 MVP;\n"
		"attribute vec3 vCol;\n"
		"attribute vec2 vPos;\n"
		"varying vec3 color;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
		"    color = vCol;\n"
			"}\n";

		variables->vertex_shader_text =
			"#version 110\n"
			"varying vec3 color;\n"
			"void main()\n"
			"{\n"
			"    gl_FragColor = vec4(color, 1.0);\n"
			"}\n";

		variables->vertices =
		{
			{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
			{  0.6f, -0.4f, 0.f, 1.f, 0.f },
			{   0.0f,  0.6f, 0.f, 0.f, 1.f }
		};

		//Setting up the shaders
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBuffer), variables->vertices, GL_STATIC_DRAW);

		//VERTEX SHADERS
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &variables->vertex_shader_text, NULL);
		glCompileShader(vertexShader);

		//FRAGMENT SHADERS
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &variables->fragment_shader_text, NULL);
		glCompileShader(fragmentShader);

		//PROGRAM
		program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		mvpLocation = glGetUniformLocation(program, "MVP");
		vposLocation = glGetAttribLocation(program, "vPos");
		vcolLocation = glGetAttribLocation(program, "vCol");

		//Enable the buffers
		glEnableVertexAttribArray(vposLocation);
		glVertexAttribPointer(vposLocation, 2, GL_FLOAT, GL_FALSE, sizeof(variables->vertices[0]), (void*)0);

		glEnableVertexAttribArray(vcolLocation);
		glVertexAttribPointer(vcolLocation, 3, GL_FLOAT, GL_FALSE, sizeof(variables->vertices[0]), (void*)(sizeof(float) * 2));

		//Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
	}

};