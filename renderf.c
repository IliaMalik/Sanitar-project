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
#include "render.h"

/*------------Definitions----------*/

#define LEBO 0 // determines angle in which will be net's pivot point
#define RIBO 1
#define LEUP 2
#define RIUP 3

/*--------Static varibles----------*/
static struct winsize windowsize; // gets it's value in function "init_screen()"

static char* screen = NULL;
// screen array will be set as: | 0 row | 1 row | 2 row | ...
static unshint row;
static unshint col;

static short int spiv_x;
static short int spiv_y;



/*----------Functions--------------*/


void get_ship_pivot_points(short int piv_x, short int piv_y){
	spiv_x = piv_x;
	spiv_y = piv_y;
}

void init_screen(void){
	windowsize = get_window_size(); // this function is located in terminalf.c (terminaldef.h)
	screen = malloc(windowsize.ws_row * windowsize.ws_col * sizeof(char));
	row = windowsize.ws_row;//Just a rename for readability
	col = windowsize.ws_col;//Just a rename for readability
}



void upload_to_file_and_plot(unshint score){
	int size = (row * (col + 1) + 8*10 + 50) * sizeof(char);	/* 8*10 is for 10 ASCII escape sequences
							   		col + 1 is for \n at the end of a row
							   		+50 is just for dusevny pokoj.*/
	char *buf = malloc(size * sizeof(char));
	FILE* file = fmemopen(buf, size, "w");
	for (int i = 0; i < row; i++){
		fwrite(screen + i * col, sizeof(char), col, file);
		fputc('\n', file);
		
	}
	fprintf(file, "\033[1;1HScore: %d", score);

	fclose(file);
	write(STDOUT_FILENO, buf, strlen(buf));
	free(buf);
}

void initial_draw(void){
	//get_ship_pivot_points()  probably this function should be called in gamef.c file
	init_screen();
	draw_ship();
	draw_net();
	//update_score(0,0,0);	
	upload_to_file_and_plot(score);
}


// Just an artifact for ideas in future
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


	for(; i < SHIPSZ; i++){
		screen[spiv_x * row - (i*row) + spiv_y    ] = '█'; //left side
		screen[spiv_x * row + i + spiv_y          ] = '█'; //bottom side
		screen[spiv_x * row - (i*row) + spiv_y + SHIPSZ] = '█'; //right side
		screen[spiv_x * row + i + spiv_y - SHIPSZ*row  ] = '█'; //upper side	
}

void set_net_pivot(unshint type_of_net_pivot, short int extrah, short int extraw, short int* netpivot_x, short int* netpivot_y){
	switch (type_of_net_pivot){
		case LEBO:
			*netpivot_y = spiv_y - extrah;
			*netpivot_x = spiv_x - extraw;
			break;
		case RIBO:
			*netpivot_y = spiv_y - extrah;
			*netpivot_x = spiv_x + SHIPSZ + extraw;
			break;
		case LEUP:
			*netpivot_y = spiv_y + SHIPSZ + extrah;
			*netpivot_x = spiv_x - extraw;
			break;
		case RIUP:
			*netpivot_y = spiv_y + SHIPSZ + extrah;
			*netpivot_x = spiv_x + SHIPSZ + extraw;
			break;
	}
}

void draw_net(short int formfactor){
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
			break;
		case (1):
			height = 16;
			width  = 14;
				
			break;	
		case (2):
			height = 14;
			width  = 16;
		
			break;
		case (3):
			height = 12;
			width  = 18;
			break;
	}
	
	
	extrah = (height  - 6)/2;
	extraw = (width   - 6)/2;
	if ((spiv_y + extrah  + 5) > row){ // check for upper bound
		stopper_y = extrah + 6 + row - (spiv_y + 5);
		type_of_net_pivot = LEBO;
	} else if(spiv_y - extrah < 0){ // check for bottom bound
		stopper_y = 2 * extrah - spiv_y + 5;
		type_of_net_pivot = LEUP;
	} else{
		stopper_y = height;
		type_of_net_pivot = LEBO;
	}
	if (spiv_x + extraw + 5 > col){ // check for the right bound
		stopper_x = extraw + 6 + col - (spiv_x + 5);
	}else if(spiv_x < col){ // check for the left bound
		stopper_x = extraw + spiv_x + 5;
		type_of_net_pivot++ // will switch whatever there was to the right side
	}else{
		stopper_x = width;
	}
	
	set_net_pivot(type_of_net_pivot, extrah, extraw, &netpivot_x, &netpivot_y);

	/*** LEBO pivot  (1) ***/
	if (type_of_net_pivot == LEBO){
		for(i = 0; i < stopper_x; i++){ //horizontal sides
			screen[netpivot_y * row + i + netpivot_x] = '░'░; // bottom side
			if (stopper_y == height)
				screen[(netpivot_y + height) * row + i + netpivot_x] = '░'; // upper side
		}
		for(j = 0; j < stopper_y; j++){ // vertical sides
			screen[(netpivot_y + j) * row + netpivot_x] = '░'; // left side
			if (stopper_x == width)
				screen[(netpivot_y + j) * row + netpivot_x + width] = '░'; // right side
		}
	}
	/*** RIBO pivot (2) ***/
	if (type_of_net_pivot == RIBO){
		for(i = 0; i < stopper_x; i++){ //horizontal sides
			screen[netpivot_y * row - i + netpivot_x] = '░'; // bottom side
			if (stopper_y == height)
				screen[(netpivot_y + height) * row - i + netpivot_x] = '░'; // upper side
		}
		for(j = 0; j < stopper_y; j++){ // vertical sides
			if (stopper_x == width)
				screen[(netpivot_y + j) * row + netpivot_x] = '░'; // left side
			screen[(netpivot_y + j) * row + netpivot_x + width] = '░'; // right side
		}
	}
	/*** LEUP pivot (3) ***/
	if(type_of_net_pivot == LEUP){
		for(i = 0; i < stopper_x; i++){ //horizontal sides
			if(stopper_y == height)
				screen[(netpivot_y - height) * row + i + netpivot_x] = '░'; // bottom side
			screen[(netpivot_y) * row + i + netpivot_x] = '░'; // upper side
		}
		for(j = 0; j < stopper_y; j++){ // vertical sides
			screen[(netpivot_y - j) * row + netpivot_x] = '░'; // left side
			if (stopper_x == width)
				screen[(netpivot_y - j) * row + netpivot_x + width] = '░'; // right side
		}
	}
	/*** RIUP pivot (4) ***/
	if(type_of_net_pivot == RIUP){
		for(i = 0; i < stopper_x; i++){ //horizontal sides
			if(stopper_y == height)
				screen[(netpivot_y - height)* row - i + netpivot_x] = '░'; // bottom side
			screen[netpivot_y * row - i + netpivot_x] = '░'; // upper side
		}
		for(j = 0; j < stopper_y; j++){ // vertical sides
			if (stopper_x == width)
				screen[(netpivot_y - j) * row + netpivot_x - width] = '░'; // left side
			screen[(netpivot_y - j) * row + netpivot_x] = '░'; // right side
		}
	}
}

