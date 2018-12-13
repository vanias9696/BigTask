#include "interface.hpp"

interface::interface()
{
	initscr();					//start
	clear();
	noecho();					// without display
	cbreak();
	keypad(stdscr, TRUE);		// special keys
	curs_set(FALSE);			// invisible cursor
	start_color();

	welcome_window();
	win = newwin(_height, _width, 1, 2);	// new window
	refresh();
	keypad(win, true);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);

}

interface::~interface()
{
	delwin(win);
    endwin();
}

void	interface::welcome_window(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvaddstr(5, 20,"$$___$_$$$$$__$$______$$$$___$$$$__$$___$_$$$$$_____$$$$$$__$$$$");
	mvaddstr(6, 20,"$$___$_$$_____$$_____$$__$$_$$__$$_$$$_$$_$$__________$$___$$__$$");
	mvaddstr(7, 20,"$$_$_$_$$$$___$$_____$$_____$$__$$_$$_$_$_$$$$________$$___$$__$$");
	mvaddstr(8, 20,"$$$$$$_$$_____$$_____$$__$$_$$__$$_$$___$_$$__________$$___$$__$$");
	mvaddstr(9, 20,"_$$_$$_$$$$$__$$$$$$__$$$$___$$$$__$$___$_$$$$$_______$$____$$$$");
	mvaddstr(10, 20,"");
	mvaddstr(11, 20,"$$$$$$_$$__$$_$$$$$_____$$$$$___$$$$__$$$$$$_$$$$$$_$$_____$$$$$");
	mvaddstr(12, 20,"__$$___$$__$$_$$________$$__$$_$$__$$___$$_____$$___$$_____$$");
	mvaddstr(13, 20,"__$$___$$$$$$_$$$$______$$$$$__$$$$$$___$$_____$$___$$_____$$$$");
	mvaddstr(14, 20,"__$$___$$__$$_$$________$$__$$_$$__$$___$$_____$$___$$_____$$");
	mvaddstr(15, 20,"__$$___$$__$$_$$$$$_____$$$$$__$$__$$___$$_____$$___$$$$$$_$$$$$");
	mvaddstr(22, 20,"");
	mvaddstr(17, 20 + 4,"_$$$$__$$__$$_$$$$$$_$$$$$______$$$$___$$$$__$$___$_$$$$$");
	mvaddstr(18, 20 + 4,"$$_____$$__$$___$$___$$__$$____$$_____$$__$$_$$$_$$_$$");
	mvaddstr(19, 20 + 4,"_$$$$__$$$$$$___$$___$$$$$_____$$_$$$_$$$$$$_$$_$_$_$$$$");
	mvaddstr(20, 20 + 4,"____$$_$$__$$___$$___$$________$$__$$_$$__$$_$$___$_$$");
	mvaddstr(21, 20 + 4,"_$$$$__$$__$$_$$$$$$_$$_________$$$$__$$__$$_$$___$_$$$$$");
	mvaddstr(23, 35,"press a button to begin the game");
	attroff(COLOR_PAIR(1));
	getch();
	clear();

}

void interface::print_ships(players p, int R)
{
	if (p.four[0])
	{
		for (int i = 1; i < 8; i = i + 2)
			mvwprintw(win, p.four[i + 1] + 8, p.four[i] * 2 + 5 + R, "#");
	}
	if (p.three1[0])
	{
		for (int i = 1; i < 6; i = i + 2)
			mvwprintw(win, p.three1[i + 1] + 8, p.three1[i] * 2 + 5 + R, "#");
	}
	if (p.three2[0])
	{
		for (int i = 1; i < 6; i = i + 2)
			mvwprintw(win, p.three2[i + 1] + 8, p.three2[i] * 2 + 5 + R, "#");
	}
	if (p.two1[0])
	{
		for (int i = 1; i < 4; i = i + 2)
			mvwprintw(win, p.two1[i + 1] + 8, p.two1[i] * 2 + 5 + R, "#");
	}
	if (p.two2[0])
	{
		for (int i = 1; i < 4; i = i + 2)
			mvwprintw(win, p.two2[i + 1] + 8, p.two2[i] * 2 + 5 + R, "#");
	}
	if (p.two3[0])
	{
		for (int i = 1; i < 4; i = i + 2)
			mvwprintw(win, p.two3[i + 1] + 8, p.two3[i] * 2 + 5 + R, "#");
	}
	if (p.one1[0])
		mvwprintw(win, p.one1[2] + 8, p.one1[1] * 2 + 5 + R, "#");
	if (p.one2[0])
		mvwprintw(win, p.one2[2] + 8, p.one2[1] * 2 + 5 + R, "#");
	if (p.one3[0])
		mvwprintw(win, p.one3[2] + 8, p.one3[1] * 2 + 5 + R, "#");
	if (p.one4[0])
		mvwprintw(win, p.one4[2] + 8, p.one4[1] * 2 + 5 + R, "#");
}

int	interface::save_ship1(int x, int y, char vh, int num)
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
				if (x + i > -1 && x + i < 10 && y + j > -1 && y + j < 10 && map1[x + i][y + j] != 0)
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
		map1[x1][y1] = 1;
		if (p1.four[0] == 0)
		{
			p1.four[i*2 + 1] = x1;
			p1.four[i*2 + 2] = y1;
			p1.four[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.three1[0] == 0)
		{
			p1.three1[i*2 + 1] = x1;
			p1.three1[i*2 + 2] = y1;
			p1.three1[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.three2[0] == 0)
		{
			p1.three2[i*2 + 1] = x1;
			p1.three2[i*2 + 2] = y1;
			p1.three2[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.two1[0] == 0)
		{
			p1.two1[i*2 + 1] = x1;
			p1.two1[i*2 + 2] = y1;
			p1.two1[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.two2[0] == 0)
		{
			p1.two2[i*2 + 1] = x1;
			p1.two2[i*2 + 2] = y1;
			p1.two2[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.two3[0] == 0)
		{
			p1.two3[i*2 + 2] = y1;
			p1.two3[i*2 + 1] = x1;
			p1.two3[0] = i + 1 == num ? 1 : 0;
		}
		else if (p1.one1[0] == 0)
		{
			p1.one1[i*2 + 1] = x1;
			p1.one1[i*2 + 2] = y1;
			p1.one1[0] = 1;
		}
		else if (p1.one2[0] == 0)
		{
			p1.one2[i*2 + 1] = x1;
			p1.one2[i*2 + 2] = y1;
			p1.one2[0] = 1;
		}
		else if (p1.one3[0] == 0)
		{
			p1.one3[i*2 + 1] = x1;
			p1.one3[i*2 + 2] = y1;
			p1.one3[0] = 1;
		}
		else
		{
			p1.one4[i*2 + 1] = x1;
			p1.one4[i*2 + 2] = y1;
			p1.one4[0] = 1;
		}
		if (vh == 'y' || vh == 'Y')
			++y1;
		else
			++x1;
	}
	return (1);
}

int	interface::save_ship2(int x, int y, char vh, int num)
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
				if (x + i > -1 && x + i < 10 && y + j > -1 && y + j < 10 && map2[x + i][y + j] != 0)
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
		map2[x1][y1] = 1;
		if (p2.four[0] == 0)
		{
			p2.four[i*2 + 1] = x1;
			p2.four[i*2 + 2] = y1;
			p2.four[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.three1[0] == 0)
		{
			p2.three1[i*2 + 1] = x1;
			p2.three1[i*2 + 2] = y1;
			p2.three1[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.three2[0] == 0)
		{
			p2.three2[i*2 + 1] = x1;
			p2.three2[i*2 + 2] = y1;
			p2.three2[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.two1[0] == 0)
		{
			p2.two1[i*2 + 1] = x1;
			p2.two1[i*2 + 2] = y1;
			p2.two1[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.two2[0] == 0)
		{
			p2.two2[i*2 + 1] = x1;
			p2.two2[i*2 + 2] = y1;
			p2.two2[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.two3[0] == 0)
		{
			p2.two3[i*2 + 1] = x1;
			p2.two3[i*2 + 2] = y1;
			p2.two3[0] = i + 1 == num ? 1 : 0;
		}
		else if (p2.one1[0] == 0)
		{
			p2.one1[i*2 + 1] = x1;
			p2.one1[i*2 + 2] = y1;
			p2.one1[0] = 1;
		}
		else if (p2.one2[0] == 0)
		{
			p2.one2[i*2 + 1] = x1;
			p2.one2[i*2 + 2] = y1;
			p2.one2[0] = 1;
		}
		else if (p2.one3[0] == 0)
		{
			p2.one3[i*2 + 1] = x1;
			p2.one3[i*2 + 2] = y1;
			p2.one3[0] = 1;
		}
		else
		{
			p2.one4[i*2 + 1] = x1;
			p2.one4[i*2 + 2] = y1;
			p2.one4[0] = 1;
		}
		if (vh == 'y' || vh == 'Y')
			++y1;
		else
			++x1;
	}
	return 1;
}

void interface::print_field(void)
{
	box(win, 0, 0);
	wattron(win, COLOR_PAIR(6));
	mvwprintw(win, 7, 3, "  A B C D E F G H I J");
	mvwprintw(win, 8, 3, "0 . . . . . . . . . . 0\0");
	mvwprintw(win, 9, 3, "1 . . . . . . . . . . 1\0");
	mvwprintw(win, 10, 3, "2 . . . . . . . . . . 2\0");
	mvwprintw(win, 11, 3, "3 . . . . . . . . . . 3\0");
	mvwprintw(win, 12, 3, "4 . . . . . . . . . . 4\0");
	mvwprintw(win, 13, 3, "5 . . . . . . . . . . 5\0");
	mvwprintw(win, 14, 3, "6 . . . . . . . . . . 6\0");
	mvwprintw(win, 15, 3, "7 . . . . . . . . . . 7\0");
	mvwprintw(win, 16, 3, "8 . . . . . . . . . . 8\0");
	mvwprintw(win, 17, 3, "9 . . . . . . . . . . 9\0");
	mvwprintw(win, 18, 3, "  A B C D E F G H I J");
	mvwprintw(win, 7, 50, "  A B C D E F G H I J");
	mvwprintw(win, 8, 50, "0 . . . . . . . . . . 0\0");
	mvwprintw(win, 9, 50, "1 . . . . . . . . . . 1\0");
	mvwprintw(win, 10, 50, "2 . . . . . . . . . . 2\0");
	mvwprintw(win, 11, 50, "3 . . . . . . . . . . 3\0");
	mvwprintw(win, 12, 50, "4 . . . . . . . . . . 4\0");
	mvwprintw(win, 13, 50, "5 . . . . . . . . . . 5\0");
	mvwprintw(win, 14, 50, "6 . . . . . . . . . . 6\0");
	mvwprintw(win, 15, 50, "7 . . . . . . . . . . 7\0");
	mvwprintw(win, 16, 50, "8 . . . . . . . . . . 8\0");
	mvwprintw(win, 17, 50, "9 . . . . . . . . . . 9\0");
	mvwprintw(win, 18, 50, "  A B C D E F G H I J");
	wattroff(win, COLOR_PAIR(6));
	wattron(win, COLOR_PAIR(5));
	mvwprintw(win, 5, 8, "<<PLAYER 1>>");
	mvwprintw(win, 5, 56, "<<PLAYER 2>>");
	wattroff(win, COLOR_PAIR(5));
}

void interface::rules(int i, int num)
{
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 1, 2, "To set the ship enter the first x and y coordinate and press Y[vertically] or X[horizontally]");
	mvwprintw(win, 2, 2, "As soon as you choose X or Y ship will be installed on the field.");
	mvwprintw(win, 3, 2, "To select the coordinate for X, enter the value from A to J");
	mvwprintw(win, 3, 2, "To select the coordinate for Y, enter the value from 0 to 9");
	mvwprintw(win, 24, 2, "If you want to exit press Q");
	mvwprintw(win, 22, 2, "Ships cannot touch the sides and corners of each other.");
	wattroff(win, COLOR_PAIR(1));
	print_field();
	wattron(win, COLOR_PAIR(5));
	mvwprintw(win, 6, 27, "PLAYER   sets the ships");
	mvwprintw(win, 6, 34, i == 0 ? "1" : "2");
	print_ships(i == 0 ? p1 : p2, i == 0 ? 0 : 47);
	wattroff(win, COLOR_PAIR(5));
	wattron(win, COLOR_PAIR(3));
	if (num == 0)
		mvwprintw(win, 9, 31, "Set ship: ####");
	else if (num < 3)
		mvwprintw(win, 9, 31, "Set ship: ###");
	else if (num < 6)
		mvwprintw(win, 9, 31, "Set ship: ##");
	else
		mvwprintw(win, 9, 31, "Set ship: #");
	mvwprintw(win, 11, 35, "X: ");
	mvwprintw(win, 13, 35, "Y: ");
}

int	interface::placeShips()
{
    int ch;
    int i = 0;
    int x = -1;
    int y = -1;
    int num = 0;
    char tmp[2] = "\0";

	while (1)
    {
    	if (i == 1 && p2.one4[0] == 1)
    		return (1);
		if (i == 0 && p1.one4[0] == 1)
		{
			num = 0;
			++i;
		}
		rules(i, num);
		wattron(win, COLOR_PAIR(3));
		if (x > -1 && (tmp[0] = x + 'A'))
			mvwprintw(win, 11, 38, reinterpret_cast<const char *>(tmp));
		if (y > -1 && (tmp[0] = y + '0'))
			mvwprintw(win, 13, 38, reinterpret_cast<const char *>(tmp));
		wattroff(win, COLOR_PAIR(3));
    	ch = wgetch(win);
    	wclear(win);
    	wrefresh(win);
    	if (ch == 'q' || ch == 'Q')
    		return 0;
    	else if (ch >= '0' && ch <= '9')
    		y = ch - '0';
    	else if (ch >= 'A' && ch <= 'J')
    		x = ch - 'A';
    	else if (ch >= 'a' && ch <= 'j')
    		x = ch - 'a';
    	else if (ch == 'x' || ch == 'X' || ch == 'y' || ch == 'Y')
    	{
    		if (x == -1 || y == -1)
    		{
    			wattron(win, COLOR_PAIR(2));
    			mvwprintw(win, 20, 23, "You didn`t choose a coordinate!");
    			wattroff(win, COLOR_PAIR(2));
    		}
    		else if (i == 0 && (save_ship1(x, y, (char)ch, num)) == 1)
    		{
				x = -1;
    			y = -1;
    			++num;
    		}
    		else if (i == 1 && (save_ship2(x, y, (char)ch, num)) == 1)
    		{
    			x = -1;
    			y = -1;
    			++num;
    		}
    	}
    	else
    	{
			wattron(win, COLOR_PAIR(2));
    		mvwprintw(win, 20, 18, "Please enter [0 - 9] or [A - J] or X or Y");
    		wattroff(win, COLOR_PAIR(2));
    	}
    }
    return 1;
}

int		interface::if_killed(int x, int y, int map[10][10])
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

void	interface::kill1(int x, int y)
{
	if (x > -1 && x < 10 && y > -1 && y < 10 && map2[x][y] == 2)
	{
		map2[x][y] = 3;
		if (x - 1 > -1)
		{
			if (y - 1 > -1)
				map2[x - 1][y - 1] = 4;
			if (y + 1 < 10)
				map2[x - 1][y + 1] = 4;
		}
		if (x + 1 > -1)
		{
			if (y - 1 > -1)
				map2[x + 1][y - 1] = 4;
			if (y + 1 < 10)
				map2[x + 1][y + 1] = 4;
		}
		kill1(x - 1, y);
		kill1(x + 1, y);
		kill1(x, y - 1);
		kill1(x, y + 1);
	}
	else if (x > -1 && x < 10 && y > -1 && y < 10 && map2[x][y] == 0)
	{
		map2[x][y] = 4;
	}
}

int		interface::shoot1(int x, int y)
{
	if (map2[x][y] == 0)
	{
		map2[x][y] = 4;
		return (1);
	}
	else if (map2[x][y] == 1)
	{
		map2[x][y] = 2;
		if (if_killed(x, y, map2) == 1 && (--num2))
			kill1(x, y);
		return (2);
	}
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 20, 27, "You alredy shoot here!");
	wattroff(win, COLOR_PAIR(2));
	return 0;
}

void	interface::kill2(int x, int y)
{
	if (x > -1 && x < 10 && y > -1 && y < 10 && map1[x][y] == 2)
	{
		map1[x][y] = 3;
		if (x - 1 > -1)
		{
			if (y - 1 > -1)
				map1[x - 1][y - 1] = 4;
			if (y + 1 < 10)
				map1[x - 1][y + 1] = 4;
		}
		if (x + 1 > -1)
		{
			if (y - 1 > -1)
				map1[x + 1][y - 1] = 4;
			if (y + 1 < 10)
				map1[x + 1][y + 1] = 4;
		}
		kill2(x - 1, y);
		kill2(x + 1, y);
		kill2(x, y - 1);
		kill2(x, y + 1);
	}
	else if (x > -1 && x < 10 && y > -1 && y < 10 && map1[x][y] == 0)
		map1[x][y] = 4;
}

int		interface::shoot2(int x, int y)
{
	if (map1[x][y] == 0)
	{
		map1[x][y] = 4;
		return (1);
	}
	else if (map1[x][y] == 1)
	{
		map1[x][y] = 2;
		if (if_killed(x, y, map1) == 1 && (--num1))
			kill2(x, y);
		return (2);
	}
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 20, 27, "You alredy shoot here!");
	wattroff(win, COLOR_PAIR(2));
	return 0;
}

void	interface::print_ships(void)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (map1[i][j] == 2)
			{
				wattron(win, COLOR_PAIR(5));
				mvwprintw(win, 8 + j, 5 + 2*i , "X");
				wattroff(win, COLOR_PAIR(5));
			}
			else if (map1[i][j] == 3)
			{
				wattron(win, COLOR_PAIR(5));
				mvwprintw(win, 8 + j, 5 + 2*i , "#");
				wattroff(win, COLOR_PAIR(5));
			}
			else if (map1[i][j] == 4)
			{
				wattron(win, COLOR_PAIR(6));
				mvwprintw(win, 8 + j, 5 + 2*i, "O");
				wattroff(win, COLOR_PAIR(5));
			}
			if (map2[i][j] == 2)
			{
				wattron(win, COLOR_PAIR(5));
				mvwprintw(win, 8 + j, 52 + 2*i , "X");
				wattroff(win, COLOR_PAIR(5));
			}
			else if (map2[i][j] == 3)
			{
				wattron(win, COLOR_PAIR(5));
				mvwprintw(win, 8 + j, 52 + 2*i , "#");
				wattroff(win, COLOR_PAIR(5));
			}
			else if (map2[i][j] == 4)
			{
				wattron(win, COLOR_PAIR(6));
				mvwprintw(win, 8 + j, 52 + 2*i, "O");
				wattroff(win, COLOR_PAIR(5));
			}
		}
	}
}

void	interface::rulesG(int i)
{
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 1, 2, "To select the coordinates of the target enter x coordinate, y coordinate and press ENTER");
	mvwprintw(win, 2, 2, "To select the coordinate for X, enter the value from A to J");
	mvwprintw(win, 3, 2, "To select the coordinate for Y, enter the value from 0 to 9");
	mvwprintw(win, 27, 2, "If you want to exit press Q");
	mvwprintw(win, 22, 2, "If you miss, the move goes to the enemy. If you hit the ship you make another move.");
	mvwprintw(win, 23, 2, "If you miss, the place will look like             O");
	mvwprintw(win, 24, 2, "If you hurt the ship, the place will look like    X");
	mvwprintw(win, 25, 2, "If you kill the ship, the place will look like    #");
	wattroff(win, COLOR_PAIR(1));
	print_field();
	print_ships();
	wattron(win, COLOR_PAIR(5));
	if (i % 2 != 0)
		mvwprintw(win, 6, 31, "PLAYER 1 move");
	else
		mvwprintw(win, 6, 31, "PLAYER 2 move");
	wattroff(win, COLOR_PAIR(5));
	wattron(win, COLOR_PAIR(3));
	mvwprintw(win, 11, 35, "X: ");
	mvwprintw(win, 13, 35, "Y: ");
	char tmp[2] = "\0";
	tmp[0] = num2 + '0';
	mvwprintw(win, 19, 50, "Player 1 must kill");
	if (num2 == 10)
		mvwprintw(win, 19, 69, "10 sheeps to win.");
	else
	{
		mvwprintw(win, 19, 69, reinterpret_cast<const char *>(tmp));
		mvwprintw(win, 19, 71, "sheeps to win.");
	}
	mvwprintw(win, 19, 2, "Player 2 must kill");
	tmp[0] = num1 + '0';
	if (num1 == 10)
		mvwprintw(win, 19, 21, "10 sheeps to win.");
	else
	{
		mvwprintw(win, 19, 21, reinterpret_cast<const char *>(tmp));
		mvwprintw(win, 19, 23, "sheeps to win.");
	}
	wattroff(win, COLOR_PAIR(3));
}

void	interface::win12(int i)
{
	box(win, 0, 0);
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 6, 23, "$$$$$__$$______$$$$__$$__$$_$$$$$__$$$$$_____");
	mvwprintw(win, 7, 23, "$$__$$_$$_____$$__$$__$$$$__$$_____$$__$$____");
	mvwprintw(win, 8, 23, "$$$$$__$$_____$$$$$$___$$___$$$$___$$$$$_____");
	mvwprintw(win, 9, 23, "$$_____$$_____$$__$$___$$___$$_____$$__$$____");
	mvwprintw(win, 10, 23, "$$_____$$$$$$_$$__$$___$$___$$$$$__$$__$$____");
	mvwprintw(win, 13, 38, "$$___$_$$$$$$_$$__$$");
	mvwprintw(win, 14, 38, "$$___$___$$___$$$_$$");
	mvwprintw(win, 15, 38, "$$_$_$___$$___$$_$$$");
	mvwprintw(win, 16, 38, "$$$$$$___$$___$$__$$");
	mvwprintw(win, 17, 38, "_$$_$$_$$$$$$_$$__$$");
	if (i == 1)
	{
		mvwprintw(win, 6, 67, "___$$");
		mvwprintw(win, 7, 67, "_$$$$");
		mvwprintw(win, 8, 67, "___$$");
		mvwprintw(win, 9, 67, "___$$");
		mvwprintw(win, 10, 67, "___$$");
	}
	else
	{
		mvwprintw(win, 6, 67, "_$$$$_");
		mvwprintw(win, 7, 67, "$$__$$");
		mvwprintw(win, 8, 67, "___$$_");
		mvwprintw(win, 9, 67, "_$$___");
		mvwprintw(win, 10, 67, "$$$$$$");
	}
	mvwprintw(win, 21, 36,"press any button to exit");
	wattroff(win, COLOR_PAIR(1));
	wgetch(win);

}

void	interface::game()
{
	if (placeShips() == 0)
		return ;

	int i = 1;
	int ch;
	int x = -1;
	int y = -1;
	char tmp[2] = "\0";
	while (1)
	{
		if (num1 == 0 || num2 == 0)
		{
			win12(num1 == 0 ? 2 : 1);
			return ;
		}
		rulesG(i);
		wattron(win, COLOR_PAIR(3));
		if (x > -1 && (tmp[0] = x + 'A'))
			mvwprintw(win, 11, 38, reinterpret_cast<const char *>(tmp));
		if (y > -1 && (tmp[0] = y + '0'))
			mvwprintw(win, 13, 38, reinterpret_cast<const char *>(tmp));
		wattroff(win, COLOR_PAIR(3));
		ch = wgetch(win);
    	wclear(win);
    	wrefresh(win);
    	if (ch == 'q' || ch == 'Q')
    		return ;
    	else if (ch >= '0' && ch <= '9')
    		y = ch - '0';
    	else if (ch >= 'A' && ch <= 'J')
    		x = ch - 'A';
    	else if (ch >= 'a' && ch <= 'j')
    		x = ch - 'a';
    	else if (ch == 10)
    	{
    		if (x == -1 || y == -1)
    		{
    			wattron(win, COLOR_PAIR(2));
    			mvwprintw(win, 20, 23, "You didn`t choose a coordinate!");
   				wattroff(win, COLOR_PAIR(2));
    		}
    		else if (i % 2 != 0)
    		{
    			if (shoot1(x, y) == 1)
    				++i;
				x = -1;
    			y = -1;
    		}
    		else if (i % 2 == 0)
    		{
    			if (shoot2(x, y) == 1)
    				++i;
    			x = -1;
    			y = -1;
    		}
    	}
    	else
    	{
			wattron(win, COLOR_PAIR(2));
    		mvwprintw(win, 20, 21, "Please enter [0 - 9] or [A - J] or O");
    		wattroff(win, COLOR_PAIR(2));
    	}
	}

}

//написати гудбай!
