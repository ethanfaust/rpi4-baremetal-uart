#!/bin/bash

make clean
BSP=rpi4 make

cp kernel8.img /path/to/sd/

#umount /path/to/sd/
