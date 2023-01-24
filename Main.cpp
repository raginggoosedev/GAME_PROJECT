#include <iostream>
#include "GameWindow.cpp"


void processInput(GameWindow* window) {
	if(glfwGetKey(window->getWindow(), GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(window->getWindow(), true);
	}
}

int main() 
{
	GameWindow* window = new GameWindow(800, 800, "Test 3.0");
	//MAIN LOOP
	while (window->isRunning())
	{
		window->run();
		processInput(window);
		//window->drawLine();

		
	}

	window->close();
	return 0;
}

