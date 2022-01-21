#include "iostream"
#include "Game.h"

using std::cout;

int main()
{
	
	//Init Game engine
	Game game;
	// game loop
	
	while (game.running())
	{
		//Update
		game.update();
		//Render
		game.render();
		//Draw game
	}
	
	return 0;
}