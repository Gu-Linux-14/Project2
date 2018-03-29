#include <ncurses.h> 

int main(void) 
{
	initscr(); 

	FILE *filePointer; 

	filePointer=fopen("file.txt", "r"); 

	char singleLine[150]; 

	int line = 0; 


	while(fgets(singleLine, 150, filePointer)){
		line++; 
		printw("Line%d -> %s", line, singleLine); 
		refresh(); 
	}

	fclose(filePointer); 
	getch();
	endwin(); 

	return 0;

}
