int sensorValue;
int potValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  digitalWrite (ledPin, LOW);
}

void loop() 
{
  potValue = analogRead(A1);
 sensorValue = analogRead(A0);
 Serial.print("Sensor Value: ");
 Serial.print(sensorValue);
 Serial.print("\t Pot Value: ");
 Serial.println(potValue);
 int pitch = 
  map(sensorValue,sensorLow,sensorHigh, 50, 4000);
  tone(8,pitch,20);
  delay(10);
}
