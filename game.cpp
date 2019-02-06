#include "game.hpp"

game::game() : x_(-1), y_(-1){}

game::~game(){
}

int game::setting_values(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        y_ = ch - '0';
        return 0;
    }
    else if (ch >= 'A' && ch <= 'J')
    {
        x_ = ch - 'A';
        return 0;
    }
    else if (ch >= 'a' && ch <= 'j')
    {
        x_ = ch - 'a';
        return 0;
    }
    return 1;
}

void    game::ship_install(players *pl, char ch, int *num)
{
    if (x_ == -1 || y_ == -1)
        inf.error(2, 20, 23, "You didn`t choose a coordinate!");
    else
    {
        try
        {
            pl->save_ship(x_, y_, ch, *num);
            x_ = -1;
            y_ = -1;
            *num = *num + 1;
        }
        catch (std::exception const &ex)
        {
            inf.error(2, 20, 25, "Not enough space for ship!");
            inf.error(2, 21, 24, ex.what());
        }
    }

}

int game::place_ships()                     //set ships for 1 and 2 players
{
    char    ch;
    int     i = 0;
    int     num = 0;

    while (1)
    {
        if (i == 1 && num == 10)
            return (1);
        if (i == 0 && num == 10 && ++i)
            num = 0;
        inf.rules_set(i, num, p1, p2);
        ch = inf.print_start(x_, y_);
        if (ch == 'q' || ch == 'Q')
            return 0;
        else if (setting_values(ch) == 0)
            ;
        else if (ch == 'x' || ch == 'X' || ch == 'y' || ch == 'Y')
            ship_install(i == 0 ? &p1 : &p2, ch, &num);
        else
            inf.error(2, 20, 18, "Please enter [0 - 9] or [A - J] or X or Y");
    }
    return 1;
}

void    game::shoot_ship(players *pl, int *i)   // check if can shoot
{
    if (x_ == -1 || y_ == -1)
        inf.error(2, 20, 23, "You didn`t choose a coordinate!");
    else
    {
        try
        {
            if (pl->shoot(x_, y_) == 1)
                *i = *i + 1;
        }
        catch (std::exception const &ex)
        {
            inf.error(2, 20, 27, ex.what());
        }
        x_ = -1;
        y_ = -1;
    }
}

void	game::start()      //main method which call methods of displaying information and shooring
{
	int i = 1;
	int ch;
    x_ = -1;
    y_ = -1;

	while (1)
	{
		if (p1.number == 0 || p2.number == 0)
		{
			inf.win12(p1.number == 0 ? 2 : 1);
			return ;}
		inf.rules_game(i, p1, p2);
        ch = inf.print_start(x_, y_);
    	if (ch == 'q' || ch == 'Q')
    		return ;
        if (setting_values(ch) == 0)
            ;
    	else if (ch == 10)
            shoot_ship(i % 2 != 0 ? &p2 : &p1, &i);
    	else
            inf.error(2, 20, 18, "Please enter [0 - 9] or [A - J] or ENTER!");
	}
}