#include <TimedBlink.h>
#define temp_pin A0

TimedBlink led(LED_BUILTIN);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, OUTPUT);
}

void loop() {
  int adcData = analogRead(temp_pin); //Read Raw ADC data
  float voltage = adcData * (5.0 / 1024.0); // Convert that ADC Data into voltage
  float temperature = voltage * 100; // Convert the voltage into temperature

  if(temperature > 30) { // When temperature goes beyond 30 degree Celsius
    led.blink(500,500); // LED blinks for 500 milliseconds
  }
  else{ //When temperature is less than 30 degree Celsius
    led.blink(250,250); // LED blinks for 250
  }
}
