#include "game.hpp"

int main(void)
{
	game on;
	if (on.place_ships() != 0)
		on.start();
    on.inf.goodbye();
	return 0;
}