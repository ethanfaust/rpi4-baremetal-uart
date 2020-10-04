## How to use
1. Can be run via QEMU
2. Can be run as bare metal on Pi 4B by writing to SD Card
    Setup instructions: https://github.com/rust-embedded/rust-raspberrypi-OS-tutorials

See Makefile

## Acknowledgements
https://github.com/bztsrc/raspi3-tutorial
https://github.com/rust-embedded/rust-raspberrypi-OS-tutorials

## License
MIT license

## Tutorial
Derived from https://github.com/bztsrc/raspi3-tutorial
(0-5)

Added support for Pi 4B.

## Serial Console
sudo screen /dev/ttyUSB0 115200,cs8,ixoff,-istrip
