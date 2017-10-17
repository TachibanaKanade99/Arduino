#include <LedControl.h>
/*
pin 2 is connected to the DataIn
pĩn 4 is connected to the CLK
pỉn 3 is connected to LOAD
The last parameter is the number of LED matrix
 */
LedControl lc = LedControl(2,4,3,1);

byte left[8] = {B11111111, B01010101, B10101010, B01010101, B10101010, B01010101, B10101010, B01010101};

void setup(){
	/*
	The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
	 */
	lc.shutdown(0,false);
	/* Set the brightness to a medium values */
	lc.setIntensity(0,8);
	/* and clear the dislay */
	lc.clearDisplay(0);
	
	// turn on all LEDS for a test
	for (int row=0;row<8;row++) {
		lc.setRow(0, row, 255);
		delay(100);
	}
delay(300);
}
 void loop(){
 	// put your main code here, to run repeatedly:
 	for(int row=0;row<8;row++){
 		lc.setRow(0, row, left[row]);
 		delay(100);
 	}
 	delay(300);
 }
