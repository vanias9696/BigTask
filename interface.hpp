#ifndef INTERFACE_HPP
# define INTERFACE_HPP
#include <ncurses.h>
#include "players.hpp"

class interface
{
	public:
		interface();
		~interface();
		WINDOW		*win;
		void		error(int color, int first, int second, const char * str);
		void		welcome_window();
		void		rules_set(int i, int num, players p1, players p2);
		void		print_field();
		void		print_ships_set(players p, int i);
		void		rules_game(int i, players p1, players p2);
		void		win12(int i);
		void		print_ships_game(players p1, players p2);
		void		goodbye();
		char		print_start(int x, int y);
		interface	operator=(interface tmp);

	private:
		int const	_height = 30;
		int const	_width = 100;

};

#endif