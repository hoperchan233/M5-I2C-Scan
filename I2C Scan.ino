#include <M5Core2.h>            //core
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nI2C Scanner");
  Wire.begin();
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.println("Scan finished");
  }

  delay(5000);
}
