#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	Position p=getscreensize();
if (p.col<BARS){
	printf("Your screen is not wide enough to diaplay %d bars\n",BARS);
	return 1;
}
	clearscreen();
        FILE *fp=fopen("test.wav","r");
        WAVheader h= readwavhdr(fp);
        displaywavhdr(h);
	getchar();
	wavdata(h, fp);
	fclose(fp);
}
