#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define GLFW_INCLUDE_NONE

class ShaderVariables
{
public:
	static const char* vertex_shader_text;
	static const char* fragment_shader_text;
};