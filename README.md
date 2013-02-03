lock_screen
===========

event handling of lock-screen button (for aakash)


## Installing

The code has to be natively compiled, so use this requires gcc installed.

* Runnning install script which installs fbset package
$ ./install

* Compile the lock_screen.c
$ gcc lock_screen.h -o lock_screen.o


## Loading

lock_screen.o has to be loaded with following parameter

$ ./lock_screen.o /dev/input/event0

where */dev/input/event0*  is file descriptor of lock_screen button of aakash (it usually is event0, if its not, contact me)

*Thats it* it the button should toggle screen on or off. 

**NOTE: The backlight doesnt go off (yet).**


## Loading on boot

Put following line in rc.local before "exit0" 

*/path_to_lock_screen.o/lock_screen.o   /dev/input/event0*


