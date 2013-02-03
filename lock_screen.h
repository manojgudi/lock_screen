#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>


int TOGGLE_SWITCH = 1;


int turn_screen_off(){
	int status = system("fbset -xres 0");
	return status;
}


int turn_screen_on(){
	int status = system("fbset -xres 800");
	return status;
}





