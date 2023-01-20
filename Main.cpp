#include <iostream>
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameWindow.cpp"

int main() 
{

	GameWindow* window = new GameWindow(800, 800, "Test");

	//MAIN LOOP
	while (window->isRunning())
	{
		window->run();
	}

	window->close();
	return 0;
}