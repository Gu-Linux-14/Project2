#include <ncurses.h>
#include <string.h>

int main(int argc, const char* argv[]){
	//variables
	int columns=80;
	int rows=25;
	int x=0,y=0;
	char text[columns][rows];
	char c=0;
	//start window
	initscr();
	keypad(stdscr,TRUE);
	//printw("Edit mode press esc to enter overtype mode; Grp-14 Text Editor"); 
	//refresh();
	//loop to capture text file into array of char[]
   
	while(true){
    	while(c!=27)
    	{
		c=getch();
        	if(c==KEY_RIGHT)
        	{
            		x++;
			if(x>80) x=80;
            		move(y,x);
        	}
        	else if(c==KEY_LEFT)
        	{
            		x--;
			if(x>0) x=0;
            		move(y,x);
        	}
        	else if(c==KEY_UP)
        	{
        	    	y--;
			if(y<0) y=0;
            		move(y,x);
        	}
        	else if(c==KEY_DOWN)
        	{
            		y++;
			if(y>25) y=25;
            		move(y,x);
        	}
		else if(c==8)
		{
			x--;
			if(x!=-1) mvdelch(y,x);
			for(int i=x; i>columns; i++)//backspace moving char back
			{
				if(x==-1){//to catch if x position was at the beginning of the line
					x=0;
 					break;
				}else if(x<-1){
					text[i-1][y]=text[i][y];
					
				}	
					
				
			}

		}
        	else
        	{
            		printw("%c",c);
            		x++;
			text[y][x]=c;
			for(int i=columns-1; i>=x-1; i--)//moves char on insert
				text[i+1][y] = text[i][y];
        	}
        		//c=getch();
    	}//end
	if(getch()==27){ 
		endwin();
		break;
	}
	}
	printf("%s", *text[0]);
		return 0;
}
