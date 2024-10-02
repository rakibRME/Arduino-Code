#include <SoftwareSerial.h> // Include the SoftwareSerial library

// Define the pins used for the GPS module
#define GPS_RX_PIN 4
#define GPS_TX_PIN 3

// Initialize the SoftwareSerial object for the GPS module
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  while (!Serial) {}

  // Start the serial communication for the GPS module
  gpsSerial.begin(9600);
  delay(1000);
}

void loop() {
  // Read data from the GPS module
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    Serial.write(c);
  }
}
