#include <iostream>
#include "GameWindow.cpp"


int main() 
{
	GameWindow* window = new GameWindow(800, 800, "TEST 3.0");
	window->setBackground(255,0,255);

	//MAIN LOOP
	while (window->isRunning())
	{
		window->run();
		//window->drawTriangle(0,0,800,0,400,600);
		//window->drawLine();
		
	}

	window->close();
	return 0;
}