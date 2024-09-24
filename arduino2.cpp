// C++ code
// Controls the brightness and color of LEDs using a potentiometer.

// Pins for RGB LED
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

const int potPin = A0;

void setup()
{
   // Set LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  
  // Read potentiometer value (0 - 1023)
  int potValue = analogRead(potPin);
  
  // Map potentiometer value to PWM range (0 - 255)
  int redValue = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 0, 255);
  int blueValue = map(potValue, 0, 1023, 0, 255);

  // Output PWM signals to control RGB LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, 255 - greenValue); // Inverse to vary colors
  analogWrite(bluePin, 255 - blueValue); // Inverse to vary colors
  
  // Small delay for stability
  delay(10);
}
