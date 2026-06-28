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

/*------------Definitions----------*/

#define LEBO 0 // determines angle in which will be net's pivot point
#define RIBO 1
#define LEUP 2
#define RIUP 3

/*--------Static varibles----------*/
static struct winsize windowsize; // gets it's value in function "init_screen()"

static char* screen = NULL;
// screen array will be set as: | 0 row | 1 row | 2 row | ...
static unshint rows;
static unshint cols;

static short int spiv_x;
static short int spiv_y;



/*----------Functions--------------*/


void get_ship_pivot_points(unshint piv_x, piv_y){
	spiv_x = piv_x;
	spiv_y = piv_y;
}

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
	//get_ship_pivot_points()  probably this function should be called in another place
	init_screen();
	draw_ship();
	draw_net();
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


void draw_ship(void){ // pivot point is the bottom left point of the ship		
	short int i = 0;
	
/*	short int stopper_x;//  determines farthest column to draw 
	short int stopper_y;//  determines farthest row to draw

	if ((spiv_y - 5) < 0){				//better not to allow the ship to move out of borders
		stopper_y = 5 + (spiv_y - 5);
	} else if((spiv_y + 1) > row){

	}
*/


	for(; i < 6; i++){
		screen[spiv_x * row - (i*row) + spiv_y    ] = '█'; //left side
		screen[spiv_x * row + i + spiv_y          ] = '█'; //bottom side
		screen[spiv_x * row - (i*row) + spiv_y + 6] = '█'; //right side
		screen[spiv_x * row + i + spiv_y - 6*row  ] = '█'; //upper side	
}

void set_net_pivot(unshint type_of_net_pivot, unshint* netpivot_x, netpivot_y){
	switch (type_of_net_pivot){
		case LEBO:
			netpivot




	}
}

void draw_net(unshint formfactor){
	short int netpivot_x;
	short int netpivot_y;
	short int height;
	short int width;
	short int stopper_x; // determines the furthest column to draw
	short int stopper_y; // determines the furthest row to draw
	short int i; // will be used in two cykles later
	short int j;
	unshint type_of_net_pivot; // look definitions at the begining  
	short int extrah; // a vertical part of the net beyond the ship (idk how to explain this)
	short int extraw;


	switch (formfactor){ // 0 is the heighest, 3 is the widest form
		case (0):
			height = 18;
			width  = 12;
			extrah = (height  - 6)/2;
			extraw = (width   - 6)/2;
			if ((spiv_y + extrah  + 5) > row){ // check for upper bound
				stopper_y = extrah + row - (spiv_y + 5);
				type_of_net_pivot = LEBO;
			} else if(spiv_y - extrah < 0){ // check for bottom bound
				stopper_y = 2 * extrah - spiv_y + 5;
				type_of_net_pivot = LEUP;
			} else{
				stopper_y = height
			if (spiv_x + extraw + 5 > cols){ // check for the right bound
				stopper_x = cols - spiv_x;
			}else if(spiv_x < cols){ // check for the left bound
				type_of_net_pivot++ // will switch whatever there was to the right side
			}


							
			
			break;
		case (1):
			height = 16;
			width  = 14;
			extrah = (height  - 6)/2;
			extraw = (width   - 6)/2;		
			break;	
		case (2):
			height = 14;
			width  = 16;
			extrah = (height  - 6)/2;
			extraw = (width   - 6)/2;
			break;
		case (3):
			height = 12;
			width  = 18;
			extrah = (height  - 6)/2;
			extraw = (width   - 6)/2;
			break;
		for(i = 0; i < width; i++){ //horizontal sides
			screen[netpivot_y * row + i + netpivot_x           ] = ''; // bottom side
			screen[(netpivot_y - height) * row + i + netpivot_x] = ''; // upper side
		}
		for(j = 0; j < height; j++){
			screen[(netpivot_y - j) * row + netpivot_x         ] = ''; // left side
			screen[(netpivot_y - j) * row + netpivot_x + width ] = ''; // right side
		}
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

