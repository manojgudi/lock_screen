/*
This program is specifically for aakash device where lock_screen_button has file-descriptor event /dev/input/event0 and keycode 116
Author: Manoj G <manoj.p.gudi@gmail.com> 
Reference: http://www.thelinuxdaily.com/2010/05/grab-raw-keyboard-input-from-event-device-node-devinputevent/
*/

#include "lock_screen.h"

void perror_exit(char *error)
{
  perror (error);
  exit(1);
}

int main(int argc, char *argv[])
{

  extern int TOGGLE_SWITCH;
  struct input_event ev;
  int fd, size = sizeof (struct input_event);
  char name[256] = "Unknown";
  char *device = NULL;
  
  
  //Setup check
  if (argv[1] == NULL) {
    printf("Please specify (on the command line) the path to the dev event interface device\n");
    exit (0);
  }
  if ((getuid ()) != 0) {
    printf ("You are not root!\n");
    exit(1);
  }
  if (argc > 1) {
    device = argv[1];
  }
  
  
  //Open Device
  if ((fd = open (device, O_RDONLY)) == -1) {
    printf ("%s is not a vaild device.\n", device);
  }
  
  
  //Print Device Name
  ioctl (fd, EVIOCGNAME (sizeof (name)), name);
  printf ("Reading From : %s (%s)\n", device, name);


  while (1){
    if ((read (fd, &ev, size)) < size) {
      perror_exit ("read()");
    }
    
    if (ev.type == 1 && ev.value == 1 ){ // Only read the key press event
      printf ("Code[%d]\n", (ev.code));
      
      	if(ev.code == 116){    // Change this value if the key-value is not 116
      		TOGGLE_SWITCH = ~(TOGGLE_SWITCH); // TOGGLING

      	int status =  (TOGGLE_SWITCH%2 == 0) ? turn_screen_off() : turn_screen_on();
      	}
    }
  }
  return 0;
}
