#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <openFile.h>
#include <stdio.h>

void edit(char c, int y, int x)
{
	//getyx(stdscr, y, x);
	move(y, x);
	insch(c);
	
}

void backspace(int y, int x)
{
	//getyx(stdscr, y, x);
	move(y, x-1);
	delch();
}

//alternative method used for testing

/*
void editor(char text[rows][columns], int xyArray[2], char ky)
{
	char input = ky;
	int count, j =0;
	int tempY = xyArray[0];
	int tempX = xyArray[1];
	

	//get count to init tempArray
	while(text[tempY][tempX] != '\n'){
            //tempLine[j] = text[tempY][tempX];
            tempX++;
            count++;
    }

    char tempLine[count+1]; 

    tempX = xyArray[1];

    //fill temp array
    while(text[tempY][tempX] != '\n'){
            tempLine[j] = text[tempY][tempX];
            tempX++;
    }

    int k = 0;
    tempX = xyArray[1];
    while(k <= count){
            text[tempY][tempX+1] = tempLine[k];
            tempX++;
            k++;
    }

	text[tempY][xyArray[1]] = ky;
	for(int k = 0; k < xyArray[0]; k++)
	{
		for(int g = 0; g < xyArray[1]; g++) {
			printw("%c", text[k][g]);
			refresh();
		}	
		
	}

	xyArray[1] = xyArray[1]+1;
}
*/