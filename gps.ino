#include <SoftwareSerial.h>
#include "TinyGPS++.h"

// Choose two Arduino pins to use for software serial
int RXPin =10;
int TXPin =11;
TinyGPSPlus gps;

//Default baud of NEO-6M is 9600
int GPSBaud = 9600;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);
 // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // Displays information when new sentence is available.
  while (gpsSerial.available() > 0)
    gps.encode(gpsSerial.read());
    if (gps.location.isUpdated())
    {
      Serial.print("lat=");Serial.print(gps.location.lat(), 9);Serial.print(" ");
      Serial.print("lng=");Serial.println(gps.location.lng(), 9);
    }
 }
