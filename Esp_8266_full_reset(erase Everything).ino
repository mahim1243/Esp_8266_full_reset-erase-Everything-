#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <FS.h> // For SPIFFS (if you're using LittleFS, include <LittleFS.h> instead)

void eraseEEPROM(int size) {
  EEPROM.begin(size);
  for (int i = 0; i < size; i++) {
    EEPROM.write(i, 0xFF); // Erase by setting each byte to 0xFF
  }
  EEPROM.commit();
  EEPROM.end();
}

void formatSPIFFS() {
  if (SPIFFS.begin()) {
    Serial.println("Formatting SPIFFS...");
    SPIFFS.format();
    Serial.println("SPIFFS formatted.");
  } else {
    Serial.println("SPIFFS mount failed.");
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("---- ESP8266 FULL RESET ----");

  // 1. Erase Wi-Fi credentials
  Serial.println("Erasing Wi-Fi credentials...");
  WiFi.disconnect(true);
  delay(1000);

  // 2. Erase flash config
  Serial.println("Erasing flash config...");
  if (ESP.eraseConfig()) {
    Serial.println("Flash config erased.");
  }

  // 3. Erase EEPROM (size depends on how much you use, 512 is common)
  Serial.println("Erasing EEPROM...");
  eraseEEPROM(512);

  // 4. Erase SPIFFS (skip this if you're using LittleFS)
  formatSPIFFS();

  Serial.println("Reset complete. Restarting...");
  ESP.restart();
}

void loop() {
  // Nothing here
}