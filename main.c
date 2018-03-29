#include <ncurses.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	int rows = 25;
	int columns = 80;
	char text[rows][columns];
	char key;
	string fName = argv[1];
	openFile(fName, text);
	bool insMode = false;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	move(2,0);
	hline(ACS_CKBOARD,80); // placing a horizontal line to separate menu from text area here
	mvaddstr(0,0, "Group 14 - dataFile.txt");
	textEditor(text, insMode, fName);

	clear();
	endwin();



	return 0;
}

int textEditor(char text[25][80], bool insMode, string fName){
	int inKey, cursorPosition, x = 0;
	int y = 2;	//since top 2 lines are uneditable

	while(!exitFlag){
		inKey = getch();

		switch(inKey){
			case 27:	//esc
				exitFlag = true;
				break;
			case KEY_LEFT:	//move cursor left
				if(cursorPosition>0 && insMode==true){	//if cursor isn't all the way left
					cursorPosition--;
					x--;
					move(y,x);
				}	
				break;
			case KEY_RIGHT:	//move cursor right
				//if cursor is not all the way right
				if(cursorPosition < strlen(text[y]) && insMode==true)
					cursorPosition++;
					x++;
					move(y,x);
				break;
			case KEY_UP:	//move cursor up
				if(y > 1 && insMode==true){	//if not on top line
					if(x > strlen(text[y-1])){
						y--;
						x = strlen(text[y]);
						cursorPosition = x;
					}
					else{
						y--;
					}
					move(y,x);
				}
				break;
			case KEY_DOWN:	//move cursor down
				if(y < 24 && insMode==true){
					if(x > strlen(text[y+1])){
						y++;
						x = strlen(text[y]);
						cursorPosition = x;
					}
					else{
						y++;
					}
					move(y,x);
				}
				break;
			case KEY_F(1):	//change insert or command mode
				insMode = !insMode;
				if(insMode == true)	//if insert mode
					curs_set(1);	//cursor visible
				if (insMode == false)//if command mode
					curs_set(0);	//cursor invisible
				break;
			case KEY_F(2):	//save
				if(insMode == false)	//only if in command mode
					saveFile(fileName, text);
				break;
			case 6:	//ctrl+f find+replace
				find(text);
				break;
			case KEY_DL:	//delete line
				if(insMode)	//if insert mode
					deleteLine(text);
				break;
			case KEY_ENTER:	//enter or insert new line
				if(insMode){	//if insert mode
					insert(text, y, cursorPosition);
					x = cursorPosition;
					move(y,x);
				}
				break;
			case KEY_BACKSPACE: //backspace
				if(insMode){ //if insert mode
					char ky = inKey;
					edit(text, y, x, ky);
					move(y,x);
				}
				break;
			default:
				if(insMode && (inKey > 31 && inKey < 127)){	//if insert mode and printing character
					char ky = inKey;
					edit(text, y, x, ky);
					move(y,x);
				}
			break;
		
		}
		refresh();
	}

	return 0;
}
