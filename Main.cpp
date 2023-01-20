#include <iostream>
//#include </home/apeman/Code/Test/GAME_PROJECT/Libraries/include/glad/glad.h>
//#include </home/apeman/code/VSCode/GAME_PROJECT/Libraries/include/glad/glad.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameWindow.cpp"
#include "Player.cpp"

int main() 
{

	GameWindow* window = new GameWindow(800, 800, "Test");
	Player* player = new Player();
	
	
	//Create triangle
	

	//MAIN LOOP
	while (window->isRunning())
	{
		window->run();
		glUseProgram(player->program);
	}

	window->close();
	return 0;
}