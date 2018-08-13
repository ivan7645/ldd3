## Linux Device Drivers, 3e

**Linux ver: 4.15.0-29-generic**

### hello_world
	make
	insmod hello_world.ko
	rmmod hello_word.ko

### hello_world\_p
	make
	insmod hello_world_p.ko 
	rmmod hello_word_p.ko
	
### scull
	make
	sudo sh ./scull_load
	sudo sh ./scull_unload
*app.c : R/W /dev/scull0*

	gcc -Wall -o app app.c
	sudo ./app 'Your String'
