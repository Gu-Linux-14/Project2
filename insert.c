#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int insert(char text[rows][columns], int *rows, int *cursorPosition){
    //check if trying to insert new line after max row
    if(rows = 24){
        printw("No more room to insert new line");
        refresh();
        return -1;
    }

    int i, j, count, cursorTemp = 0;
    
    //move whole document after row down one line
    for(int k = 23; k > rows; k--){
        //if last row isn't empty, no more room to insert new line
        //return -1 to indicate error
        if(text[24][0] != '\n'){
            printw("No more room to insert new line");
            refresh();
            return -1;
            break;
        }

        count = 0;
        i = cursorTemp;

        //get the count to initialize tempLine
        while(text[k][i] != '\0'){
            count++;
            i++;
        }

        char tempLine[count+1];
        i = cursorTemp;
        j = 0;

        //fill tempLine with chars after cursorPosition
        if(count == 1){        //only if blank line
            tempLine[0] = '\n';
            tempLine[1] = '\0';        //add null terminator
        }
        else{
            while(text[k][i] != '\0'){
            tempLine[j] = text[k][i];
            i++;
            j++;
            }
        }

        tempLine[j] = '\0';        //add null terminator

        //fill row after cursorPosition with tempLine
        text[k+1] = tempLine;
    }

    //return rest of line after cursorPosition down
    i = cursorPosition;
    count = 0;
    //get the count to initialize tempLine
        while(text[rows][i] != '\0'){
            count++;
            i++;
        }

    char tempLine[count+1];
    i = cursorTemp;
    j = 0;

    //fill tempLine with chars after cursorPosition
    if(count == 1){        //only if blank line
        tempLine[0] = '\n';
        tempLine[1] = '\0';        //add null terminator
    }
    else{
        while(text[rows][i] != '\0'){
        tempLine[j] = text[rows][i];
        i++;
        j++;
        }
    }

    tempLine[j] = '\0';        //add null terminator

    //fill row after cursorPosition with tempLine
    text[rows+1] = tempLine;

    text[rows][cursorPosition] = '\n';
    text[rows][cursorPosition+1] = '\0';    //add null terminator
    cursorPosition = 0;    //reset cursorPosition to beginning of row
    rows++;

    return 0;
}


