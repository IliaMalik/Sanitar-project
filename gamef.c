//NPC and PLAYER and WORLD realizations of functions

#include "definitions.h"
#include "renderdef.h"
#include "terminaldef.h"

/*------------Living things--------*/

static unshint score = 0;
static unshint formfactor = 0;
static ENTITY* intruders = NULL;

/*------------Functions------------*/

void init_intruders_array(void){ // +- half of game world can be filled by intruders
	intruders = malloc((get_window_size().ws_row + 2*EXTRAPOL) * (get_window_size().ws_col + 2*EXTRAPOL) * sizeof(ENTITY));
}







void Tick(){

	


	get_ship_pivot_points( ---, ---);
	init screen();
	draw_ship();
	draw_net(formfactor);
	upload_to_file_and_plot(score);
}




