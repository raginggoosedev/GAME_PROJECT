#include <iostream>
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