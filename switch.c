#include <ncurses.h>
#include <string.h>
#include <stdlib.h>


int main(argv[]int argc, char*){
    


    initscr();
    noecho();
    cbreak();

    char answer = getch();
    string mode = "";

    switch(answer){
   	 case 'i' :
   		 mode = "Insert Mode";
   		 break;
   	 case 27 :    //27 is ASCII value for esc
   		 mode = "Exiting Now...";
   		 break;
    }
   	 case 'c' :
   		 mode = "Command Mode";
   		 break;

    return 1;
}

int textEditor(){
    int inKey, cursorPosition = 0;
}
