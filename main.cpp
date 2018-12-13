#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.hpp"

int main(void)
{
	interface in;

	in.game();

    // int x = 3;
    // int y = 3;
    // int ch;
    
    // while (1)
    // {
    // 	ch = wgetch(in.win);
    // 	if (ch == 'q' || ch == 'Q')
    // 		break;
    // 	if (ch == 'w' || ch == 'W')
    // 		y--;
    //     if (ch == 'S' || ch == 's')
    //     	y++;
    //     if (ch == 'a' || ch == 'A')
    //     	x--;
    //     if (ch == 'd' || ch == 'D')
    //     	x++;
    //     wclear(in.win);
    // 	box(in.win, 0, 0);
    // 	mvwprintw(in.win, y, x, "X");
    // 	wrefresh(in.win);
    // }

	return 0;
}