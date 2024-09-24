// C++ code
// Make an LED blink on and off every second.

const int led = 13;  // LED is connected to pin 13

void setup()
{
  pinMode(led, OUTPUT);  // sets pin 13 as an output
}

void loop()
{
  digitalWrite(led, HIGH); // turns the LED on (HIGH = sends a voltage to the pin)
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(led, LOW); // turns the LED off (LOW = stops the voltage to the pin)
  delay(1000); // Wait for 1000 millisecond(s)
}
