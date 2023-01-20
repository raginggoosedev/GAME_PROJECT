#include <iostream>
#include "GameWindow.cpp"

int main() 
{

	GameWindow window = GameWindow(800, 800, "Test");

	window.setBackground(255,255,255); //make it lime green
	window.setHeight(600);

	//MAIN LOOP
	while (window.isRunning())
	{
		window.run();
		//window->drawLine();
	}

	window.close();
	return 0;
}