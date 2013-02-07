#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>


int TOGGLE_SWITCH = 1;


int turn_screen_off(){
	system("rmmod ft5x_ts"); // Change the touch screen module "ft5x_ts" with proper module if this doesnt work
	int status = system("fbset -xres 0");
	return status;
}


int turn_screen_on(){
	system("modprobe ft5x_ts")
	int status = system("fbset -xres 800");
	return status;
}





