// Usually in aheader file, following inforamtion are included
//  1. function declarations
// 2. constant definitons
// 3. conditional complination (will be dicussed later)

//constant definitions
#define  ESC 0x1B
//#define BLACK 
enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGNETA,CYAN,WHITE};
#define bg(c) (c+10)	//marco definition

#define UNICODE		//for conditional complination
#define BAR "\u2590"

#define DEBUG

typedef struct{
	int row	;
	int col;
}Position;
// function declarations
void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void gotoXY(int, int);
void drawbar(int,int);
void drawrect(int, int, int, int);
Position getscreensize(void);
