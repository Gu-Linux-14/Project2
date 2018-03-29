#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "openFile.h"
//ncurses should already be open with a new window.
//int columns = 80;
//int rows = 25;

int openFile(char fileName[], char text[rows][columns]) {
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
		if(i == columns - 1){
			text[j][i] = '\n';
			j++;
			i = 0;
		}
		if(j == rows - 1){
			printw("File too large, cannot open to edit");
			refresh();
			return -1;
		}
		text[j][i] =  temp;
		text[j][i+1] = '\0';
		i++;
	}

	bool bre = false;	
	for(int k = 0; k < rows; k++)
	{
		for(int g = 0; g < columns; g++) {
			printw("%c", text[k][g]);
			refresh();

			if (text[k][g] == '\0') {
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

