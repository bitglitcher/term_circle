#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

//Scale factor
#define SCALE 10

void draw_circle(WINDOW* win)
{
    for(int i = 0;i <= 360;i++)
    {
        mvprintw((sin(i*PI/180) * SCALE) + (getmaxy(win)/2), (cos(i*PI/180) * SCALE) + (getmaxx(win)/2), "#");
    }
}

void win_clear(WINDOW* win)
{
    for(int x = 0;x <= getmaxx(win);++x)
    {
        for(int y = 0;y <= getmaxy(win);++y)
        {
            mvprintw(y, x, " ");
        }
    }
}



int main()
{
    //Ncurses initalize
    WINDOW* win = initscr();
    curs_set(FALSE); // Don't display a cursor
    noecho();
    timeout(0);

    while(getch() != 'q' || getch() != 'Q')
    {
        draw_circle(win);
        refresh(); //Refresh window
        usleep(10000000);
        win_clear(win);
    }

    endwin();
    return 0;
}
