#ifndef INTERFACE_HPP
# define INTERFACE_HPP

#include <ncurses.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.hpp"

class interface
{
	public:
		interface();
		~interface();
		WINDOW		*win;
		void		printStart();
		void		error(int color, int first, int second, const char * str);
		void		welcome_window();
		void		draw_borders(WINDOW *screen);
		void		rules(int i, int num, players p1, players p2);
		void		print_field();
		void		print_ships(players p, int i);
		void		rulesG(int i, players p1, players p2);
		void		win12(int i);
		void		print_ships2(players p1, players p2);
		void		goodbye();
		char		printStart(int x, int y);
		interface	operator=(interface tmp);

	private:
		int const	_height = 30;
		int const	_width = 100;

};

#endif