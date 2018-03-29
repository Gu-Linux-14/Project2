//
//  fndRplc.h
//  prjt2-14
//
//  Created by grp-14 on 3/28/18.
//  Copyright (c) 2018 grp-14. All rights reserved.
//

#ifndef __prjt2_14__fndRplc__
#define __prjt2_14__fndRplc__

#include <stdio.h>
#include <ncurses.h>
const int COLUMNS=80;
const int ROWS=25;
int fndRplc(char text[ROWS][COLUMNS]);
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

#endif /* defined(__prjt2_14__fndRplc__) */
