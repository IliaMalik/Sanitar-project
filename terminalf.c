// TERMINAL
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h> 

#include "definitions.h" //mine definitions
#include "terminaldef.h" 

#define GETWINDOWSIZEERROR 802
#define SAVEERROR 801
#define GOOD 800



static struct termios original_terminal; //observable for whole project
static struct termios work_terminal; //that one will be raw


unshint save_original_terminal(void){
	if(tcgetattr(STDIN_FILENO, &original_terminal) < 0){
		printf("Save of the original terminal error");
		return SAVEERROR;
	}
	return GOOD;
}

void set_raw_mode(void){
	work_terminal = original_terminal;
	work_terminal.c_lflag &= ~ICANON;//Turns off the by-line mode (waiting for "Enter" button)
	work_terminal.c_lflag &= ~ECHO;//Makes letters not to print if you press them
	work_terminal.c_cc[ VTIME ] = 0;//Time the programm will wait untill returning data
	work_terminal.c_cc[ VMIN  ] = 1;//Size of bufer?
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &work_terminal);

}

void set_original_terminal(void){
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_terminal);
}
  
struct winsize get_window_size(void){
	struct winsize window;
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &window) == -1){ //TIOCGWINSZ-Terminal Input Output Control Get Window Size
		printf("\nError of getting window's size");
		exit(GETWINDOWSIZEERROR);
	} else {
		return window;
	}
}




