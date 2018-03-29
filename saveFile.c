#include <ncurses.h>
#include <stdlib.h>
#include "saveFile.h"
//int columns = 80;
//int rows = 25;

int saveFile (char fileName[], char text[rows][columns]) {
	FILE *ofp;
	if(!(ofp = fopen (fileName, "w"))) {
		return -1;
	}
	
	bool bre = false; //whether or not the file is done
	for(int k = 0; k < rows; k++) {
		for(int g = 0; g < columns; g++){
			if(text[k][g] == '\0') {
				bre = true;
				break;
			}
			fputc(text[k][g], ofp);
			if(text[k][g] == '\n')
				break;
		}
		if (bre)
			break;
	}
	fclose(ofp);
	return 0;
}
