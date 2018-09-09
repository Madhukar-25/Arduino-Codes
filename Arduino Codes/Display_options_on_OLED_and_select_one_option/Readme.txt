The code will display 4 options on the OLED(.96 inch) and one option can be selected. 
As we press key 1, the selection will move up and key 2 will move the selection down.
The selection will invert the color at the current position, like in this case , the background becomes white and text becomes black.
In this experiment I am using 4x4 Matrix keyboard for keys.

Connections:
1] Arduino to OLED:
			OLED			Arduino
		1. Ground -------- Ground
		2. VCC    -------- VCC
		3. SCL    -------- 10
		4. SDA    -------- 9
		5. RESET  -------- 13
		6. D/C    -------- 11
		
2] Arduino to 4x4 Matrix keyboard
		  Keyboard     Arduino
		1. R1 ----------- 6
		2. R2 ----------- 5
		3. C1 ----------- 3
		
		
You will need 3 libraries:
1. Adafruit ssd1306
2. Adafruit GFX library
3. keypad

All three libraries can be installed from Arduino IDE> Sketch> Include library> Manage library, and then type the library name accordingly and install.