//
//  fndRplc.c
//  prjt2-14
//
//  Created by grp-14 on 3/28/18.
//  Copyright (c) 2018 grp-14. All rights reserved.
//

int fndRplc(char text[ROWS][COLUMNS]){
    saveFile("tempFR.txt", text);
    FILE *temp;//temp variables for switching values
    char ndl[25];//string to be found
    char hay[25];//what is being used to replace ndl
    //char *fnd;//pointer to
    int frstNm;//
    char tempText[ROWS][COLUMNS];
    char tempLn [COLUMNS];
    int x=0, y=0;
    WINDOW *my_win;
    int startx, starty, width, height;
    height = 6;
    width = 10;
    starty = (LINES - height) / 2;	/* Calculating for a center placement */
    startx = (COLS - width) / 2;	/* of the window		*/
    if(!(temp = fopen ("tempFR.txt", "w+"))) {
        return -1;
    }
    //ncurses asking for user input
    my_win = create_newwin(height, width, starty,--startx);
    destroy_win(my_win);
    mvwprintw(my_win, 1, 1, "Find: ");
    wscanw(my_win, ndl);//uses window to get users find option
    mvwprintw(my_win, 1, 2, "Replace: ");
    wscanw(my_win, hay);//uses window to get users find option
    
    char buff[COLUMNS];
    int j=0;
    int i=0;
    bool flag=false;
    ////
    while((temp = fgetc(temp)) != EOF)
    {
        if(i == columns - 1){
            //            	text[j][i] = '\n';
            buff[i]='\n';
            j++;
            i = 0;
            flag=true;
        }
        if(j == rows - 1){
            printw("File too large, cannot open to edit");
            refresh();
            return -1;
        }
        if(flag){
            char *fnd=strstr(buff, ndl);
            frstNm=strlen(buff)-strlen(fnd);
            strncpy(tempLn, buff, buff + (frstNm - 1));//need to make sure this is right
            strcat(tempLn, hay);
            strcat(tempLn, fnd+strlen(ndl));
            for (int i=0; i<strlen(tempLn); i++) {
                tempText[j][i]=tempLn[i];
            }
            j++;
        }
        buff[i]=temp;
        buff[i+1];
        //text[j][i] =  temp;
        //text[j][i+1] = '\0';
        i++;
    }
    /*
     while((buff=fgetc(temp))){//fgets(buff, COLUMNS, temp)){
     char *fnd=strstr(buff, ndl);
     frstNm=strlen(buff)-strlen(fnd);
     strncpy(tempLn, buff, buff + (frstNm - 1));//need to make sure this is right
     strcat(tempLn, hay);
     strcat(tempLn, fnd+strlen(ndl));
     for (int i=0; i<strlen(tempLn); i++) {
     tempText[j][i]=tempLn[i];
     }
     j++;
     }
     */
    saveFile("tempFR.txt",tempText);//overwrites this temp file with changes
    fclose(temp);
    openFile("tempFR.txt", text);//opens temp file in ncurses
    return 0;
}
WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;
    
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);		/* 0, 0 gives default characters
                                 * for the vertical and horizontal
                                 * lines			*/
    wrefresh(local_win);		/* Show that box 		*/
    
    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
     * result of erasing the window. It will leave it's four corners
     * and so an ugly remnant of window.
     */
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    /* The parameters taken are
     * 1. win: the window on which to operate
     * 2. ls: character to be used for the left side of the window
     * 3. rs: character to be used for the right side of the window
     * 4. ts: character to be used for the top side of the window
     * 5. bs: character to be used for the bottom side of the window
     * 6. tl: character to be used for the top left corner of the window
     * 7. tr: character to be used for the top right corner of the window
     * 8. bl: character to be used for the bottom left corner of the window
     * 9. br: character to be used for the bottom right corner of the window
     */
    wrefresh(local_win);
    delwin(local_win);
}
