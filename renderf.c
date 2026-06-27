//This is the file for the realization of functions to render and draw the image
/* Escape sequencies instruction: 
 * ■
 * □
 *
 * █
 * ░
 *
 */
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "definitions.h"
#include "terminaldef.h"




static struct winsize windowsize; // gets it's value in function "init_screen()"

static char* screen = NULL;
// screen array will be set as: | 0 row | 1 row | 2 row | ...
static unshint rows;
static unshint cols;



void init_screen(void){
	windowsize = get_window_size(); // this function is located in terminalf.c (terminaldef.h)
	screen = malloc(windowsize.ws_row * windowsize.ws_col * sizeof(char));
	row = windowsize.ws_row;//Just a rename for readability
	col = windowsize.ws_col;//Just a rename for readability

}



void upload_to_file_and_print(){
	int size = (windowsize.ws_row * (windowsize.ws_col + 1) + 8*10 + 50) * sizeof(char);
							/* 8*10 is for 10 ASCII escape sequences
							   col + 1 is for \n at the end of a row
							   +50 is just for dusevny pokoj.*/
	char *buf = malloc(size);
	FILE* file = fmemopen(buf, size, "w");
	


	free(buf);
}

void initial_draw(void){
	init_screen();
	draw_ship(row /2 , col /2);
	draw_net( row /2 , col /2);
	//update_score(0,0,0);	
	


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


void draw_ship(unshint pivot_x, unshint pivot_y){ // pivot point is the bottom left point of the ship		
	int i = 0;

	if ((pivot_x - 5) <)//WORKHERE finish a check if it is located inside the screen
	for(; i < 6; i++){
		screen[pivot_x * row - (i*row) + pivot_y] = '█'; //left side
		screen[pivot_x * row + i + pivot_y] = '█'; //bottom side
		screen[pivot_x * row - (i*row) + pivot_y + 6] = '█';//right side
		screen[pivot_x * row + i + pivot_y - 6*row] = '█'; //upper side	
}

void draw_net(unshint ship_pivot_x, unshint ship_pivot_y, /*WORKHERE add form factor as argument*/){





}
/*
void update_score(unshint added_huns, unshint added_tens, unshint added_ones){ 
	
	screen[0] = 's';		// probably this function won't be in the final version because
	screen[1] = 'c';		// it is easier to write number directly into the "file"
	screen[2] = 'o';
	screen[3] = 'r';
	screen[4] = 'e';
	screen[5] = ' ';
	if(added_huns <= (int)('9' - screen[6]))
		screen[6] += added_huns;
	screen[7] = ' ';
	screen[8] = ' ';

}
*/

