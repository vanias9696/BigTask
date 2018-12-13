#include "interface.hpp"


int	players::save_ship(int x, int y, char vh, int num, WINDOW *win)
{
	int x1 = x;
	int y1 = y;

	if (num == 0)
		num = 4;
	else if (num < 3)
		num = 3;
	else if (num < 6)
		num = 2;
	else
		num = 1;

	for (int n = 0; n < num; ++n)
	{
		if (y > 9)
		{
			wattron(win, COLOR_PAIR(2));
    		mvwprintw(win, 20, 22, "Not enough vertical space for ship!");
    		mvwprintw(win, 21, 25, "Please move the ship higher!");
    		wattroff(win, COLOR_PAIR(2));
    		return 0;
    	}
    	if (x > 9)
    	{
			wattron(win, COLOR_PAIR(2));
    		mvwprintw(win, 20, 22, "Not enough horizontal space for ship!");
    		mvwprintw(win, 21, 24, "Please move the ship to the left!");
    		wattroff(win, COLOR_PAIR(2));
    		return 0;
    	}
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				if (x + i > -1 && x + i < 10 && y + j > -1 && y + j < 10 && map[x + i][y + j] != 0)
				{
					wattron(win, COLOR_PAIR(2));
    				mvwprintw(win, 20, 25, "Not enough space for ship!");
    				mvwprintw(win, 21, 24, "Coordinate");
    				char tmp[2] = "\0";
    				tmp[0] = x + i + 'A';
    				mvwprintw(win, 21, 35, reinterpret_cast<const char *>(tmp));
    				tmp[0] = y + j + '0';
    				mvwprintw(win, 21, 37, reinterpret_cast<const char *>(tmp));
    				mvwprintw(win, 21, 39, "already taken!");
    				wattroff(win, COLOR_PAIR(2));
    				return 0;

				}
			}
		}
		if (vh == 'y' || vh == 'Y')
			++y;
		else
			++x;
	}
	for (int i = 0; i < num; ++i)
	{
		map[x1][y1] = 1;
		if (four[0] == 0)
		{
			four[i*2 + 1] = x1;
			four[i*2 + 2] = y1;
			four[0] = i + 1 == num ? 1 : 0;
		}
		else if (three1[0] == 0)
		{
			three1[i*2 + 1] = x1;
			three1[i*2 + 2] = y1;
			three1[0] = i + 1 == num ? 1 : 0;
		}
		else if (three2[0] == 0)
		{
			three2[i*2 + 1] = x1;
			three2[i*2 + 2] = y1;
			three2[0] = i + 1 == num ? 1 : 0;
		}
		else if (two1[0] == 0)
		{
			two1[i*2 + 1] = x1;
			two1[i*2 + 2] = y1;
			two1[0] = i + 1 == num ? 1 : 0;
		}
		else if (two2[0] == 0)
		{
			two2[i*2 + 1] = x1;
			two2[i*2 + 2] = y1;
			two2[0] = i + 1 == num ? 1 : 0;
		}
		else if (two3[0] == 0)
		{
			two3[i*2 + 2] = y1;
			two3[i*2 + 1] = x1;
			two3[0] = i + 1 == num ? 1 : 0;
		}
		else if (one1[0] == 0)
		{
			one1[i*2 + 1] = x1;
			one1[i*2 + 2] = y1;
			one1[0] = 1;
		}
		else if (one2[0] == 0)
		{
			one2[i*2 + 1] = x1;
			one2[i*2 + 2] = y1;
			one2[0] = 1;
		}
		else if (one3[0] == 0)
		{
			one3[i*2 + 1] = x1;
			one3[i*2 + 2] = y1;
			one3[0] = 1;
		}
		else
		{
			one4[i*2 + 1] = x1;
			one4[i*2 + 2] = y1;
			one4[0] = 1;
		}
		if (vh == 'y' || vh == 'Y')
			++y1;
		else
			++x1;
	}
	return (1);
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

int		players::shoot(int x, int y, WINDOW *win)
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
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 20, 27, "You alredy shoot here!");
	wattroff(win, COLOR_PAIR(2));
	return 0;
}
