// The  file contains functions to manipulate screens, such as set foreground
// color, background color, clearscreen, restore default settings, etc.
// To enable screen manipulations, we need to use VT100 escape sequences
// see the link: http://www.termsys.demon.co.uk/vtansi.htm
// use SHIFT_insert key to paste

#include <stdio.h> // for printf() function
#include "screen.h"// contains constants

// function definitions
// a function name is an identifier in c, an identifier should start with letter
// a letter or underscore, and followed by letters, digits, underscores

void clearscreen(void){
        printf("%c[2J", ESC);
}

void setfgcolor(int fg){
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}

void setcolors(int fg, int bg){
	setfgcolor(fg);
	setbgcolor(bg);
}

void resetcolors(void)
{
	printf("%c[0m",ESC);
}

void gotoXY(int row, int col){
	printf("%c[%d;%dH", ESC,row,col);

}

void drawbar(int col, int height){
	int i;
	for(i=1; i<=height;i++)
	{
		gotoXY(i,col);
#ifdef UNICODE
	printf("%s",BAR);
#else
	printf("%c","#");
#endif
	}
}

void drawrect(int row, int col, int height,int width)
{
	int i,j;	//loop control variables
	for(i=row; i<row+height; i++){
		for(j=col; j<col+width;j++){
			gotoXY(i,j);
#ifdef UNICODE
		printf("%s",BAR);
#else
		printf("%c",'#');
#endif// this file will be used to test nfunctions in screen.c
	}
		printf("\n");
	}
}

Position getscreensize(void){
	Position p;
	int r,c;
	char ret[100]="\0";
	gotoXY(999,999);
	printf("%c[6n",ESC);
	scanf("%s",ret);
#ifdef DEBUG
	printf("%s\n",ret);
#endif
	//we will decode the returned string
#include<string.h>
	if(strlen(ret)>0){
		char dum;
		int r,c;
		sscanf(ret,"%c%c%d%c%d%c",&dum,&dum,&r,&dum,&c,&dum);
		p.row=r;
		p.col=c;
}
	else{
		p.row=0;
		p.col=0;
}
	return p;
}
