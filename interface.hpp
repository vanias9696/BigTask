#ifndef INTERFACE_HPP
# define INTERFACE_HPP

#include <ncurses.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct players
{
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
		int	save_ship1(int x, int y, char vh, int num);
		int	save_ship2(int x, int y, char vh, int num);
		void	kill2(int x, int y);
		void	kill1(int x, int y);
		int		shoot2(int x, int y);
		int		shoot1(int x, int y);
		int		if_killed(int x, int y, int map[10][10]);
		void	rulesG(int i);
		void	win12(int i);


	private:
		int const	_height = 30;
		int const	_width = 100;
		players	p1;
		players p2;
		int	map1[10][10] = {};
		int	map2[10][10] = {};
		char pmap1[10][24];
		char pmap2[10][24];
		int	num1 = 10;			//how many lives ships exist in player 1
		int num2 = 10;			//how many lives ships exist in player 2


};

class Player
{
	public:
		Player();
		~Player();
	private:

};

#endif