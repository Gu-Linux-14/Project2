#include <ncurses.h>
#include <stdlib.h>

int columns = 80;
int rows = 25;

int saveFile (char fileName[], char text[columns][rows]) {
	FILE *ofp;
	if(!(ofp = fopen (fileName, "w"))) {
		return -1;
	}
	
	bool bre = false; //whether or not the file is done
	for(int k = 0; k < rows; k++) {
		for(int g = 0; g < columns; g++){
			if(text[g][k] == '\0') {
				bre = true;
				break;
			}
			fputc(text[g][k], ofp);
			if(text[g][k] == '\n')
				break;
		}
		if (bre)
			break;
	}
	fclose(ofp);
	return 0;
}

int main(int argc, char*argv[]) {
	char text[columns][rows];
	initscr();
/*	text[0][0] = 'a';
	text[1][0] = '\n';
	text[0][1] = 'b';
	text[1][1] = 'c';
	text[2][1] = '\0';
*/	saveFile(argv[1], text);
	getch();
	endwin();
}
