//This is the file for the realization of functions to render the image
/* Escape sequencies instruction: 
 *
 *
 *
 *
 *
 */
#include "definitions.h"

void rerender(unshint screen[RAWS][COLS], unshint* changes){ /*changes is an array looking
							       like [x1,y1,who1,x2,y2,who2..., xn, yn, whon, PLUG]*/
	int i = 0;
	while(changes[i] != PLUG){
		screen[i][i+1] = 
		
		
		i++;
	}	
	
	free(changes);
}


void dr_lod(unshint x, unshint y){		
	
	
	
	
	
}



