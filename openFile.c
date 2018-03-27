#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

//ncurses should already be open with a new window.
int columns = 80;
int rows = 25;

int openFile(char fileName[], char text[columns][rows]) {
	FILE *fp;
	if(!(fp = fopen (fileName, "r"))){
		printw("File not found");
		refresh();
		return -1;
	}
	char temp;
	int i = 0; //columns
	int j = 0; //rows
	while((temp = fgetc(fp)) != EOF)
	{
		if(i == columns){
			text[i][j] = '\n';
			j++;
		}
		if(j == rows){
			printw("File too large, cannot open to edit");
			refresh();
			return -1;
		}
		text[i][j] =  temp;
		text[i+1][j] = '\0';
		i++;
	}

	bool bre = false;	
	for(int k = 0; k < rows; k++)
	{
		for(int g = 0; g < columns; g++) {
			printw("%c", text[g][k]);
			refresh();

			if (text[g][k] == '\0') {
				bre = true;
				break;
			}
		}	
		if( bre) 
			break;
	}
	
	fclose(fp);
	return 0;
	
} 

int main(int argc, char*argv[])
{
	char text[columns][rows];
	initscr();
	openFile(argv[1], text);
	getch();
	endwin();

	return 0;

}
