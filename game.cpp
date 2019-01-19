#include "game.hpp"

game::game()
{
    x_ = -1;
    y_ = -1;
}

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


int game::placeShips()
{
    char    ch;
    int     i = 0;
    int     num = 0;

    while (1)
    {
        if (i == 1 && p2.one4[0] == 1)
            return (1);
        if (i == 0 && p1.one4[0] == 1 && ++i)
            num = 0;
        inf.rules(i, num, p1, p2);
        ch = inf.printStart(x_, y_);
        if (ch == 'q' || ch == 'Q')
            return 0;
        else if (setting_values(ch) == 0)
            ch += 0;
        else if (ch == 'x' || ch == 'X' || ch == 'y' || ch == 'Y')
        {
            if (x_ == -1 || y_ == -1)
                inf.error(2, 20, 23, "You didn`t choose a coordinate!");
            else if (i == 0)
            {
                try
                {
                    p1.save_ship(x_, y_, ch, num);
                    x_ = -1;
                    y_ = -1;
                    ++num;
                }
                catch (const char *a)
                {
                    inf.error(2, 20, 25, "Not enough space for ship!");
                    inf.error(2, 21, 24, a);
                }
            }
            else if (i == 1)
            {
                try
                {
                    p2.save_ship(x_, y_, ch, num);
                    x_ = -1;
                    y_ = -1;
                    ++num;
                }
                catch (const char *a)
                {
                    inf.error(2, 20, 25, "Not enough space for ship!");
                    inf.error(2, 21, 24, a);
                }
            }
        }
        else
            inf.error(2, 20, 18, "Please enter [0 - 9] or [A - J] or X or Y");
    }
    return 1;
}

void	game::start()
{
	if (placeShips() == 0)
		return ;
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
		inf.rulesG(i, p1, p2);
        ch = inf.printStart(x_, y_);
    	if (ch == 'q' || ch == 'Q')
    		return ;
        if (setting_values(ch) == 0)
            ;
    	else if (ch == 10)
    	{
    		if (x_ == -1 || y_ == -1)
                inf.error(2, 20, 23, "You didn`t choose a coordinate!");
            else if (i % 2 != 0)
            {
                try
                {
                    if (p2.shoot(x_, y_) == 1)
                        ++i;
                }
                catch (...)
                {
                    inf.error(2, 20, 27, "You alredy shoot here!");
                }
                x_ = -1;
                y_ = -1;
            }
            else if (i % 2 == 0)
            {
                try
                {
                    if (p1.shoot(x_, y_) == 1)
                        ++i;
                }
                catch (...)
                {
                    inf.error(2, 20, 27, "You alredy shoot here!");
                }
                x_ = -1;
                y_ = -1;
            }
    	}
    	else
            inf.error(2, 20, 18, "Please enter [0 - 9] or [A - J] or ENTER!");
	}
}