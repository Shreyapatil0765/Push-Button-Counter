# Push-Button-Counter

*Company*: CODTECH IT SOLUTIONS
*NAME*: SHREYA PATIL
*INTERN ID*: CT04DF2846
*DOMAIN*: EMBEDDED SYSTEMS
*DURATION*: 4 WEEKS
*MENTOR*: NEELA SANTOSH

##This project involves creating a simple push button counter using an Arduino Uno, a push button, and a 16x2 I2C LCD display. The goal is to increment a counter each time the button is pressed and display the updated count on the LCD.

Project Components:
Arduino Uno
16x2 I2C LCD display
Push button
Breadboard and jumper wires

Circuit Description:
The push button is connected to digital pin 2 of the Arduino. The other leg of the button is connected to ground (GND). No external resistor is required because we use the Arduino’s internal pull-up resistor. The LCD is connected to the Arduino via I2C communication protocol using the SDA and SCL pins (A4 and A5 on the Uno). Power (VCC) and GND are also connected to the LCD accordingly.

Working Principle:
Initially, the LCD displays a welcome message and the count, which starts from zero. Every time the button is pressed, the count increases by one, and the LCD updates to show the new value. This is a common beginner project for understanding digital input, LCD output, and debouncing.

Problem Faced:
1. Initially, one end of the push button was connected to pin 13 of the Arduino. However, this caused unreliable button behavior. This is because pin 13 is connected internally to the onboard LED, which interferes with the pin's voltage levels and can lead to false readings. The issue was resolved by switching the button connection to pin 2.
2. When we configure a pin as an input using pinMode(button, INPUT); the pin is said to be "floating" when it is not connected to a definite voltage level. This means it can randomly read HIGH or LOW based on electrical noise, resulting in unreliable or inconsistent behavior. That is exactly what was happening — the Arduino couldn't consistently detect button presses.
3. The code and wiring were correctly designed for detecting button presses and updating the LCD. However, the counter did not increase on button presses, even though the LCD initialized correctly and showed the initial count. The problem was not in the code or logic but in the electrical connection of the push button.

Solution for 'floating': Internal Pull-Up Resistor
The fix was simple yet crucial: using INPUT_PULLUP instead of INPUT. This enables the Arduino’s internal pull-up resistor, which keeps the input pin in a known HIGH state when the button is not pressed. When the button is pressed, it connects the pin to GND, changing the state to LOW.
This change made the detection stable. Now the pin is HIGH when idle and becomes LOW only when the button is pressed, making the transition from HIGH to LOW a reliable event to count.

Debouncing
Mechanical buttons do not generate a clean digital signal when pressed. They tend to bounce; rapidly opening and closing several times in milliseconds. This can cause multiple counts for a single press. To avoid this, debouncing is implemented using a small delay (like 50 ms) to ensure that rapid changes are ignored. The code uses millis() to measure the time between changes and only accepts valid button presses if enough time has passed.

Future enhancements :
This project can be extended by using multiple buttons (increment and decrement), EEPROM to store the count, or sound feedback using a buzzer.
