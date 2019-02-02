#include "players.hpp"
#include <iostream>

void	players::ship_setting(int num, int x, int y, int vh)
{
	for (int n = 0; n < num; ++n)
	{
		if (y > 9)
		  throw (static_cast<const char *>("Please move the ship higher!"));
		if (x > 9)
		  throw (static_cast<const char *>("Please move the ship to the left!"));
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				if (x + i > -1 && x + i < 10 && y + j > -1 && y + j < 10 && map[x + i][y + j] != 0)
				{
					std::string tmp;
					tmp += "Coordinate ";
					tmp += (x + i + 'A');
					tmp += " ";
					tmp += (y + j + '0');
					tmp += " already taken!";
					throw tmp.c_str();
				}
			}
		}
		if (vh == 'y' || vh == 'Y')
			++y;
		else
			++x;
	}
}

void	players::save_ship(int x, int y, char vh, int num)
{
	if (num == 0)
		num = 4;
	else if (num < 3)
		num = 3;
	else if (num < 6)
		num = 2;
	else
		num = 1;
	ship_setting(num, x, y, vh);
	for (int i = 0; i < num; ++i)
	{
		map[x][y] = 1;
		if (vh == 'y' || vh == 'Y')
			++y;
		else
			++x;
	}
}


int		players::if_killed(int x, int y)
{
	int t = x;
	while(x > -1 && map[x][y] == 2)
		--x;
	if (x > -1 && map[x][y] == 1)
		return 0;
	x = t;
	while(x < 10 && map[x][y] == 2)
		++x;
	if (x < 10 && map[x][y] == 1)
		return 0;
	x = t;
	t = y;
	while(y > -1 && map[x][y] == 2)
		--y;
	if (y > -1 && map[x][y] == 1)
		return 0;
	y = t;
	while(y < 10 && map[x][y] == 2)
		++y;
	if (y < 10 && map[x][y] == 1)
		return 0;
	return 1;
}

void	players::kill(int x, int y)
{
	if (x > -1 && x < 10 && y > -1 && y < 10 && map[x][y] == 2)
	{
		map[x][y] = 3;
		if (x - 1 > -1)
		{
			if (y - 1 > -1)
				map[x - 1][y - 1] = 4;
			if (y + 1 < 10)
				map[x - 1][y + 1] = 4;
		}
		if (x + 1 > -1)
		{
			if (y - 1 > -1)
				map[x + 1][y - 1] = 4;
			if (y + 1 < 10)
				map[x + 1][y + 1] = 4;
		}
		kill(x - 1, y);
		kill(x + 1, y);
		kill(x, y - 1);
		kill(x, y + 1);
	}
	else if (x > -1 && x < 10 && y > -1 && y < 10 && map[x][y] == 0)
	{
		map[x][y] = 4;
	}
}

int		players::shoot(int x, int y)
{
	if (map[x][y] == 0)
	{
		map[x][y] = 4;
		return (1);
	}
	else if (map[x][y] == 1)
	{
		map[x][y] = 2;
		if (if_killed(x, y) == 1 && (--number))
			kill(x, y);
		return (2);
	}
	throw 1;
}
