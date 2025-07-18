# Controlling-LEDs-With-SerialMonitor
This Arduino code controls three LEDs (red, yellow, blue) connected to pins 9, 10, and 11, respectively, allowing the user to select an LED and set its brightness via serial communication.
In the setup function, it initializes serial communication at 9600 baud and sets the LED pins as outputs, initially turning all LEDs off. In the loop function, it prompts the user to input the desired LED color (Red, Yellow, or Blue) through the serial monitor. 
It reads the input as a string, trims whitespace, converts it to lowercase, and clears the serial buffer. 
If the input matches "red," "yellow," or "blue," it then prompts for a brightness level (1-10). 
The brightness input is read as an integer, and the serial buffer is cleared again. 
If the brightness is valid (1-10), it calculates an analog write value using an exponential formula (2^((8/10 * brightness) - 1)), turns off all LEDs, and sets the selected LED to the calculated brightness using analogWrite. 
If the brightness is invalid, it prints an error message. 
If the LED color is invalid, it prints a different error message. 
The loop delays for 1 second before repeating.
