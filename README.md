# Lego_NXT-Digital_clock
Firmware for Lego NXT to display a digital clock and beep every 10 seconds.
Used PIT timer, AIC interrupts and SSC-PIO for Sound.
NXT uses Atmel® 32-bit ARM® processor, AT91SAM7S256
This repo was created based on the Atmel manual for AT91SAM ARM-based Flash MCU

# Prerequisites
- make
- (ubuntu easier setup)
- Lego toolchain repo

# How to run
In the makefile change the PREFIX (first line) to the lego toolchange dir e.g PREFIX=../lego-toolchain_23-master

- make clean
- make
- set NXT on re-program mode (one way to do this is by the pin hidden on the back of the brick)
- make download
