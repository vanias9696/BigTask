#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.hpp"

class game
{
	public:
		game();
		~game();
		int		setting_values(char ch);
		void	start();
		int		placeShips();
		interface	inf;

	private:
		players		p1;
		players		p2;
		int			x_;
		int			y_;

};

#endif