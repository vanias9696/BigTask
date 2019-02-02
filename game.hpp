#ifndef GAME_HPP
# define GAME_HPP

#include "interface.hpp"

class game
{
	public:
		game();
		~game();
		int		setting_values(char ch);
		void    ship_install(players *pl, char ch, int *num);
		void    shoot_ship(players *pl, int *i);
		void	start();
		int		place_ships();
		interface	inf;

	private:
		players		p1;
		players		p2;
		int			x_;
		int			y_;

};

#endif