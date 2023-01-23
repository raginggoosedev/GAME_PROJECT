#include <iostream>
#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include <GLES2/gl2.h>
//#include <EGL/egl.h>
#include <GLFW/glfw3.h>
#include "GameWindow.cpp"

int main() 
{
	GameWindow* window = new GameWindow(800, 800, "Test 3.0");
	//MAIN LOOP
	while (window->isRunning())
	{
		window->run();
		//window->drawLine();
	}

	window->close();
	return 0;
}