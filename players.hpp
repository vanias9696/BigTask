#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#include <exception>

class players
{
public:
	players() = default;
	~players() = default;
	int	map[10][10] = {};
	int number = 10;
	void	ship_setting(int num, int x, int y, int vh);
	void	save_ship(int x, int y, char vh, int num);
	int		shoot(int x, int y);
	void	kill(int x, int y);
	int		if_killed(int x, int y);
};

#endif
