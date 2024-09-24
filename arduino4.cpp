// Continuously triggers the ultrasonic sensor, 
// measures the time it takes for the echo to return, and 
// calculates the distance to the nearest object in centimeters. 
// Then the distance is printed to the serial monitor.


// Define the signal pin for the ultrasonic sensor
const int sigPin = 9;  // SIG pin for the ultrasonic sensor

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the signal pin as output for triggering and input for echo
  pinMode(sigPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(sigPin, LOW);  // Ensure pin is low for a stable signal
  delayMicroseconds(2);       // Wait for 2 microseconds
  digitalWrite(sigPin, HIGH); // Send a 10-microsecond pulse to trigger
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);  // Turn off the pulse

  // Now switch the pin mode to input to listen for echo
  pinMode(sigPin, INPUT);
  long duration = pulseIn(sigPin, HIGH);  // Measure the time of the high pulse (echo)
  
  // Calculate distance in centimeters
  long distance = (duration / 2) / 29.1;  // Divide by 29.1 to convert microseconds to cm

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);  // Small delay before the next reading
  pinMode(sigPin, OUTPUT);
}
