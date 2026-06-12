
//NPC and PLAYER and WORLD definitions

typedef unsigned short int unshint;

#define WORKHERE 666

#define RAWS 30
#define COLS 60 //Fixed size of a screen. Maybe temporary, maybe not.

#define PLUG 1000 //just a marker for the end of the array for example.


#define UP_I 1
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
 *  
 *  
*/


unshint* signal_intruder(unshint x_cord, unshint y_cord);
