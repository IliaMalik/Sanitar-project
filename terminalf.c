// TERMINAL
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <signal.h>
#include <stdlib.h>
#include <syscalls.h>

#define SAVEERROR 801
#define GOOD 800


static struct termios original_terminal; //observable for whole project
static struct termios work_terminal; //the one that will be raw


unshint save_original_terminal(){
	if(tcgetattr(STDIN_FILENO, &original_terminal) < 0){
		printf("Save of the original terminal error");
		return SAVEERROR;
	}
	return GOOD;
}

void set_raw_mode(){
	work_terminal = original_terminal;
	work_terminal.c_lflag &= ~ICANON;//Turns off the by-line mode (waiting for "Enter" button)
	work_terminal.c_lflag &= ~ECHO;//Makes letters not to print if you press them
	work_terminal.c_cc[ VTIME ] = 0;//Time the programm will wait untill returning data
	work_terminal.c_cc[ VMIN  ] = 1;//Size of bufer?
	tcsetattr(STDIN_FILENO,//WORKHERE 

}


  





