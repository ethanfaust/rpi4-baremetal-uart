## What is this?
This code can be run bare metal on Raspberry Pi 3 or 4B. It sets up the UART and prints the board serial number. This can be used as a starting point for bare metal projects.

## How to use
1. Can be run via QEMU
```
make qemu
```

2. Can be run as bare metal on Pi 4B by writing to SD Card
See below.

## Initial setup
1. Build toolchain, following [these directions](https://github.com/bztsrc/raspi3-tutorial/tree/master/00_crosscompiler)
   I was able to use the latest versions of all mentioned software, at time of writing this was
    * binutils-2.35
    * cloog-0.18.1
    * gcc-10.2.0
    * gmp-6.2.0
    * isl-0.18
    * mpc-1.2.0
    * mpfr-4.1.0
2. Make for Pi 3 or Pi 4 (see Makefile)
Example:
```
BSP=rpi4 make
```

3. Set up Raspberry Pi for serial output
https://github.com/rust-embedded/rust-raspberrypi-OS-tutorials

4. Prepare bootable SD Card
Follow [these directions](https://github.com/rust-embedded/rust-raspberrypi-OS-tutorials/blob/master/06_drivers_gpio_uart/README.md)
In addition 
Copy kernel8.img from build above to SD Card (see synthesize.sh)

5. Start Pi, connect with serial console
```
sudo screen /dev/ttyUSB0 115200,cs8,ixoff,-istrip
```

## Acknowledgements
Derived from https://github.com/bztsrc/raspi3-tutorial
(0-5)

Added support for Pi 4B.

* https://github.com/bztsrc/raspi3-tutorial
* https://github.com/rust-embedded/rust-raspberrypi-OS-tutorials

## License
MIT license
