#include<unistd.h>
#include<stdlib.h>
#include<curses.h>

#define LOCAL_ESCAPE_KEY 27

int main()
{
	int key;

	initscr();
	crmode();
	keypad(stdscr,TRUE);

	noecho();
	clear();
	mvprintw(5,5,"Key pad demonstration.Press 'q' to quit");
	move(7,5);
	refresh();
	key = getch();

	while(key !=ERR && key !='q')
	{
		move(7,5);
		clrtoeol();

		if((key>='A'&&key<='Z')||(key>='a'&&key<='z'))
		{
			printw("Key was %c",(char)key);
		}//if
		else
		{
		switch(key){
			case LOCAL_ESCAPE_KEY:
				printw("%s","Escape ley");
				break;
			case KEY_END:
				printw("%s","END key");
				break;
			case KEY_BEG:
				printw("%s","BEGINNING key");
				break;
		dafault: printw("Unmatched - %d",key); break;
		}//switch
		}//else

		refresh();
		key = getch();
	}//while
	
	endwin();
	exit(EXIT_SUCCESS);
}
