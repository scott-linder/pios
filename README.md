# pios #

Kernel for RaspberryPi written in C++

## It's an "OS" ##

To say that its an OS is a bit of a stretch at this point. In fact to say its a
kernel is generous.

It doesn't actually _do_ anything yet. It will (probably) compile and be run on
the RaspberryPi SoC, though.

## Rationale ##

There is no clear goal in mind, only to work at hardware level abstraction, or
as close as possible to it. My goal is to have a command line interface running
over some form of serial debugger.

Besides the C++ compiler and the RaspberryPi hard-floating-point toolchain (see
below) I'm trying to avoid pulling in any dependencies so I can say I
understand every part of the kernel, however little that is.

## Dependencies ##

In order to compile for the RaspberryPi (which is the _only_ target platform)
you will need the proper GCC/clang toolchain from over at
[raspberrypi/tools](https://github.com/raspberrypi/tools.git) That is, you will
need arm-bcm2708hardfp-linux-gnueabi/bin/\* in your path.

For obvious reasons the kernel makes limited use (if at all) of the STL.

