2.1 Via which communication protocol/peripheral does data and commands get writtent to the LCD? 

	Via SPI (Serial Peripheral Interface).

2.2 Does updating the LCD require using interrupts at all? 

	No you can update the LCD without interupts.

2.3 Does updating the LCD occupy the CPU significantly? Does it require waiting on certain events? If yes is this high overhead? If no, how is this achived?

	depends on the method used to display is we are using a DMA then the cpu haves nothing to do so wea have small overhead. If the CPU is used to update the whole frame buffer
	and then flash it to the video RAM then this takes some time . No waiting is requiered because first if we use DMA then the whole process of displaying is handled by the 
	DMA controller second if we dont use DMA the cpu simply writes data to the locall ram frame buffer and then flushe's it to the VRAM of the LCD.

3.2 What is the maximum value that can be read from the PIT? How many milliseconds is this?

	PIT includes  PIT_PIVR/PIIR Registers. Both have their 12MS bits as a counter that goes 1 up every time the PIT counts to the PIV value that is set to count.
	Everytime this happens the 20 LS bits(CPIV) part of the Registers reached the PIV value and the start again from 0. So the maximum value can be read from the pit is when 
	the 20 CPIV bits are set to 1 which means 2^20 = 1048576 ticks = 1048576/3003 = 349,176157 ms.

4.1 What is the difference between edge- vs. level-triggered interrupts? Which ones will you choose to use and why? 

	Edge-triggered interrupts are triggered by a specific edge of a signal, such as the rising edge or falling edge. On the other hand level-triggered interupts
	are triggered when a signal remains at a constand state. I chose edge triggered interupts because i want an interupt every time the transmit bufferTHR becomes empty. so i can 
	fill it with data again using a handler.This means that i need 1 signal every time the buffer is empty edge-triggered. 

5.2 What is the minimum frequency of PIT interrupts (max period)?

	assumming the prescaller is set to 65536
	Minimum PIT interrupt frequency = 48 MHz / (65536 x 0xFFFFFFFF) = 0.00001192 Hz
	This means that the maximum period of PIT interrupts would be 83.886.080 seconds or 2.66 years.

6.4 Try generating a beep every 1 minute and every 1 second as well. Does everything still work fine?



7.1 Measure the accuracy of your digital clock over a longer period. What is its accuracy? Why is it what it is (low or high)?

	Our clock is not accurate because there are  dynamic hardware delays. 

7.2 Is it possible that interrupts are lost while your program is running? How can this happen and what does it mean for each peripheral you use?



7.3 Is it possible that you receive nested interrupts? Explain?



7.4 How does the sound get generated after we send data via the SSC?



7.5 Can you control the volume of the sound? Modify the sound interface to do so.

	Yes you can control the volume by multiplying the pattern with a d parameter. 

7.6 Can you generate specific tones? 

	Yes you can generate different tones by changing the frequency. 
