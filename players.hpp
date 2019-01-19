#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <iostream>

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
	void	ship_setting(int num, int x, int y, int vh);
	void	save_ship(int x, int y, char vh, int num);
	int		shoot(int x, int y);
	void	kill(int x, int y);
	int		if_killed(int x, int y);
};

#endif
