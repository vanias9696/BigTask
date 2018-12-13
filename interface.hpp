#ifndef INTERFACE_HPP
# define INTERFACE_HPP

#include <ncurses.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class players
{
public:
	int four[9] = {};		//if exist 1 else 0, other is coordinat x y
	int three1[7] = {};
	int three2[7] = {};
	int two1[5] = {};
	int two2[5] = {};
	int two3[5] = {};
	int one1[3] = {};
	int one2[3] = {};
	int one3[3] = {};
	int one4[3] = {};
	int	map[10][10] = {};
	int number = 10;
	int		save_ship(int x, int y, char vh, int num, WINDOW *win);
	int		shoot(int x, int y, WINDOW *win);
	void	kill(int x, int y);
	int		if_killed(int x, int y);
};

class interface
{
	public:
		interface();
		~interface();
		WINDOW *win;
		void	welcome_window();
		void	game();
		int		placeShips();
		void draw_borders(WINDOW *screen);
		void	rules(int i, int num);
		void	print_field();
		void print_ships(players p, int i);
		void	rulesG(int i);
		void	win12(int i);
		void	print_ships(void);
		void	goodbye();


	private:
		int const	_height = 30;
		int const	_width = 100;
		players	p1;
		players p2;
//		0 - пусто
//		1 - корабль
//		2 - ранив
//		3 - вбив
//		4 - мімо

};

#endif