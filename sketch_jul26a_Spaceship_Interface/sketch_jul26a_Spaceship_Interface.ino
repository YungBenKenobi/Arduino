int switchState = 0;
void setup() 
{
  // Set pins
  pinMode(3, OUTPUT); // Green LED
  pinMode(4, OUTPUT); // Red LED 1
  pinMode(5, OUTPUT); // Red LED 2
  pinMode(2, INPUT); // Pushbutton
  }

void loop() 
{
  switchState = digitalRead (2);
  if (switchState == LOW) // Button is not pressed
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else // Button is pressed
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250); // Wait for 250 milliseconds
    // Toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250); // Wait for 250 milliseconds
  }    
} // Go back to the beginning of the loop
