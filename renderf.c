//This is the file for the realization of functions to render and draw the image
/* Escape sequencies instruction: 
 * ■
 * □
 *
 *
 *
 */
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "definitions.h"
#include "terminaldef.h"




static struct winsize windowsize = get_window_size();

static char** screen = malloc();



void initial_draw(void){
	
	draw_ship(windowsize.ws_row /2 , windowsize.ws_col /2);
	draw_net( windowsize.ws_row /2 , windowsize.ws_col /2);
	update_score();	



}



void rerender(unshint screen[RAWS][COLS], ENTITY* collector){ /*collector is an array looking like
							      raw of ENTITY's and each entity says what it 
							      wants to do*/ 
	int i = 0;                   	
	while(collector[i] != PLUG){
		switch(/*type*/)


		screen[i][i+1] = WORKHERE;
		
		
		i++;
	}	
	
	free(collector);
}


void draw_ship(unshint mid_x, unshint mid_y){		
	
	
	
	
	
}

void draw_net(unshint ship_center_x, unshint ship_center_y, ){





}



