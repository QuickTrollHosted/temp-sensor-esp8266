#include <Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 // The OneWire where the Dallas 18B20 are connected (2 is GPOI2, D4)

unsigned long previousMillis = 0; // Counter when no deepsleep is used

const long interval = 10000; // Ms for collect mesurements

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// Count devices detected on boot
int devicesCount = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature module");

  //Initialize OneWire Dallas
  sensors.begin();

  // Collect number of devices on the bus
  devicesCount = sensors.getDeviceCount();
  Serial.printf("Devices count %i\n", devicesCount);
}



void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;

    sensors.requestTemperatures(); 

    for (int i=0; i<devicesCount; i++) {
      Serial.printf("Temperature °C (device#%i): %f\n", i, sensors.getTempCByIndex(i));
    }

  }
}