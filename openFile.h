//
//  openFile.h
//  prjt2-14
//
//  Created by grp-14 on 3/28/18.
//  Copyright (c) 2018 grp-14. All rights reserved.
//

#ifndef __prjt2_14__openFile__
#define __prjt2_14__openFile__

#include <ncurses.h>

#include <stdio.h>
int columns = 80;
int rows = 25;

int openFile(char fileName[], char text[rows][columns]);

#endif /* defined(__prjt2_14__openFile__) */
