//NPC and PLAYER and WORLD realizations of functions
#include <stdlib.h>
#include "definitions.h"



unshint* signal_intruder(unshint x_cord, unshint y_cord){
	unshint* x_y_direction = malloc(3*sizeof(unshint));
	x_y_direction[0] = x_cord;
	x_y_direction[1] = y_cord;
	x_y_direction[2] = WORKHERE;//there should be random value in range [0,4]
		
	
	return x_y_direction;
}

unshint* signal_ship(unshint x_cord, unshint y_cord, char button_pressed){
	unshint* x_y_type_of_movement = malloc(3*sizeof(unshint));
	unshint* x_y_type_of_movement[0] = x_cord;
	unshint* x_y_type_of_movement[1] = y_cord;
	unshint* x_y_type_of_movement[2] = (unshint) button_pressed;

	return x_y_type_of_movement;
}






