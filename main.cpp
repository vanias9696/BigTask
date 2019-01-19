#include "game.hpp"

int main(void)
{
	game on;
	if (on.placeShips() != 0)
		on.start();
    on.inf.goodbye();
	return 0;
}