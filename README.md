# Lego_NXT-Digital_clock
Firmware for Lego NXT to display a digital clock and beep every 10 seconds.
Used PIT timer, AIC interrupts and SSC-PIO for Sound. 

# Prerequisites
- make
- (ubuntu easier setup)
- Lego toolchain repo

# How to run
In the makefile change the PREFIX (first line) to the lego toolchange dir e.g PREFIX=../lego-toolchain_23-master
