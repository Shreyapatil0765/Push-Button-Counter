#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int button = 2;
int currentState;    // Debounced/clean state of the button
int previousState;   //Last reading; used to detect change
int counter = 0;     //Total number of valid button presses

unsigned long lastChangeTime = 0;   //Time when button was last pressed or released
unsigned long waitTime = 50;        //Wait time to confirm stable press (50 ms)

void setup() {
  pinMode(button, INPUT_PULLUP);  //the internal pull-up resistor; to make the pin stay HIGH by default
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  // Read initial button state once and assign to both states
  currentState = digitalRead(button);
  previousState = currentState;

  Serial.print("Initial Count: ");
  Serial.println(counter);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Counter");
  lcd.setCursor(0,1);
  lcd.print("Count: ");
  lcd.print(counter);
}

void loop() {
  int reading = digitalRead(button);  //Read the current signal

  if (reading != previousState) {     //check if the button state has changed
    lastChangeTime = millis();        //store the time of change
  }

  if ((millis() - lastChangeTime) > waitTime)    //if the change has stayed same for more than 50ms 
  {
    if (reading == LOW && currentState == HIGH)  //pressed=low, unpressed=high
    {
      counter++;
      lcd.setCursor(7,1);
      lcd.print("     ");  // Clear previous number
      lcd.setCursor(7,1);
      lcd.print(counter);
      Serial.print("Count: ");
      Serial.println(counter);
    }
    currentState = reading;
  }

  previousState = reading;
}
