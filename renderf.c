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

#define LEBO 0 // determines angle in which will be net's pivot point
#define LEUP 1
#define RIUP 2
#define RIBO 3

/*--------Static varibles----------*/
static struct winsize windowsize; // gets it's value in function "init_screen()"

static char* screen = NULL;
// screen array will be set as: | 0 row | 1 row | 2 row | ...
static unshint rows;
static unshint cols;

static spiv_x;
static spiv_y;



/*----------Functions--------------*/




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
	short int i = 0;
	
/*	short int stopper_x;//  determines farthest column to draw 
	short int stopper_y;//  determines farthest row to draw

	if ((pivot_y - 5) < 0){				//better not to allow the ship to move out of borders
		stopper_y = 5 + (pivot_y - 5);
	} else if((pivot_y + 1) > row){

	}
*/


	for(; i < 6; i++){
		screen[pivot_x * row - (i*row) + pivot_y    ] = '█'; //left side
		screen[pivot_x * row + i + pivot_y          ] = '█'; //bottom side
		screen[pivot_x * row - (i*row) + pivot_y + 6] = '█';//right side
		screen[pivot_x * row + i + pivot_y - 6*row  ] = '█'; //upper side	
}

void set_net_pivot(unshint type_of_net_pivot, unshint* netpivot_x, netpivot_y){
	switch (type_of_net_pivot){
		case LEBO:
			netpivot




	}
}

void draw_net(unshint ship_pivot_x, unshint ship_pivot_y, unshint formfactor){
	unshint netpivot_x;
	unshint netpivot_y;
	unshint height;
	unshint width;
	short int stopper_x; // determines the furthest column to draw
	short int stopper_y; // determines the furthest row to draw
	short int i; // will be used in two cykles later
	short int j;
	unshint type_of_net_pivot; // look definitions at the begining  

	switch (formfactor){ // 0 is the heighest, 3 is the widest form
		case (0):
			if ((ship_pivot_y - 5) < 0){
				stopper_y = 5 + (pivot_y - 5);
				type_of_net_pivot = LEBO;
				netpivot_x = ship_pivot_x - 3;	
				netpivot_y = ship_pivot_y - 6;
			} else if(ship_pivot_y > row){
				stopper_y =  
			}

			height = 18;
			width  = 12;
				
			
			break;
		case (1):
			netpivot_x = ship_pivot_x - 4;	
			netpivot_y = ship_pivot_y - 5;
			height = 16;
			width  = 14;
			break;	
		case (2):
			netpivot_x = ship_pivot_x - 5;	
			netpivot_y = ship_pivot_y - 4;
			height = 14;
			width  = 16;
			break;
		case (3):
			netpivot_x = ship_pivot_x - 6;	
			netpivot_y = ship_pivot_y - 3;
			height = 12;
			width  = 18;
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

