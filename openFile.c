#include <ncurses.h>

//ncurses should already be open with a new window.

int openFile(char fileName[]) {
	FILE *fp;
	if(!(fp = fopen (fileName, "r"))){
		printw("File not found");
		refresh();
		return -1;
	}
	char buff[255];
	char temp;
	while(fscanf(fp, "%s", buff) != EOF){
		temp = fgetc(fp);
		printw("%s%c", buff, temp);		
		refresh();
	}

	return 0;
	
} 

int main(int argc, char*argv[])
{
	initscr();
	openFile(argv[1]);
	getch();
	endwin();

	return 0;

}
