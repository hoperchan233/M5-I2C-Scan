#include <M5Unified.h> // 引入M5Unified库
#include <Wire.h>

void setup() {
  M5.begin(); // 初始化M5设备
  M5.Display.setRotation(3); // 设置屏幕方向
  M5.Display.setTextSize(2); // 设置文字大小
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nI2C Scanner");
  M5.Display.println("\nI2C Scanner");
  Wire.begin();
}

void loop() {
  byte error, address;
  int nDevices = 0;
  M5.Display.fillScreen(BLACK);
  M5.Display.setCursor(0, 0);

  Serial.println("Scanning...");
  M5.Display.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      M5.Display.print("Found: 0x");
      if (address < 16) {
        Serial.print("0");
        M5.Display.print("0");
      }
      Serial.println(address, HEX);
      M5.Display.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found");
    M5.Display.println("No devices");
  } else {
    Serial.println("Scan finished");
    M5.Display.println("Scan finished");
  }

  delay(5000);
}
