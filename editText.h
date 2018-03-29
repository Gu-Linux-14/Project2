//
//  editText.h
//  prjt2-14
//
//  Created by grp-14 on 3/28/18.
//  Copyright (c) 2018 grp-14. All rights reserved.
//

#ifndef __prjt2_14__editText__
#define __prjt2_14__editText__

#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openFile.h>

//insert a character where cursor is 
void edit(char c, int y, int x);

// delete character at location preceding cursor
void backspace(int y, int x);


#endif /* defined(__prjt2_14__editText__) */