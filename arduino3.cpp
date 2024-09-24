// C++ code
// Continuously fade the LED in and out by changing the brightness value between 0 and 255.

int LED = 3;          // defines that LED is connected to pin 3.
int brightness = 0;   // sets initial brightness to 0 (i.e. off).
int fadeAmount = 5;   // controls how much brightness changes each time it loops
                      // (increases and decreases by 5 units).

void setup()
{
  pinMode(LED, OUTPUT);  // sets pin 3 as an output.
  Serial.begin(9000);    // initializes serial communication at 9000 baud.
}

void loop()
{
  analogWrite(LED,brightness);  // sends a PWM signal to the LED, setting its brightness.
                                // brightness ranges from 0 (off) to 255 (fully on).
  
  brightness = brightness + fadeAmount;  // change brightness by the fadeAmount.

  // checks if the brightness is at its minimum (0) or maximum (255).
  // if so, negate fadeAmount to reverse the direction of fading.
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // pauses the loop for 30 milliseconds to control fading speed.
  delay(30);
}
