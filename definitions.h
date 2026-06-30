
//NPC and PLAYER and WORLD definitions

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>


typedef unsigned short int unshint;

typedef struct{
	unshint x; 
	unshint y;
	char type_action; //char is chosen because of it's size.
}ENTITY;
/*description of actions for each number:
 * 1  up for intruder
 * 2  down for intruder
 * 3  left for intruder
 * 4  right for intruder
 * 5  up for ship
 * 6  down for ship
 * 7  left for ship
 * 8  right for ship
 * 9  change in form of the net width+
 * 10 change in form of the net height+  
*/




#define WORKHERE 666

#define RAWS 30
#define COLS 60 //Fixed size of a screen. Maybe temporary, maybe not.

#define PLUG 1000 //just a marker for the end of the array for example.

#define SHIPSZ 6         /* All sizes here are wrote as length of the one side of the object*/
#define NETMAX 18
#define NETMIN 12
#define NETAREA 216


// This is the part of game world beyond the screen
#define EXTRAPOL (NETMAX - SHIPSZ)/2 











