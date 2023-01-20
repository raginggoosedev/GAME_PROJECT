#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class ShaderVariables
{
public:
	static const char* vertex_shader_text;
	static const char* fragment_shader_text;

	static const struct
	{
		float x, y;
		float r, g, b;
	} vertices[3];
};