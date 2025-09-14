// Unit Test for the Scaler

// If the light is low going from 0-800, the buzzer should make 200 Hz
// If the light is in range of 800-900, the buzzer should make 200-1000 Hz
// If the light is higher than 900, the buzzer should make 1000 Hz

#include <ArduinoUnit.h>

float Scaler(int sensorValue){
  float scaled = 200 + ((sensorValue - 800) * (1000-200) / (900-800));
  if (scaled < 200) scaled = 200;
  if (scaled > 1000) scaled = 1000;
}

test(Scaler_test_low){
  assertEqual(Scaler(0), 200);
}

test(Scaler_test_in_range){
  assertEqual(Scaler(800), 200);
  assertEqual(Scaler(900), 1000);
}

test(Scaler_test_high){
  assertEqual(Scaler(1200), 1000);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Test::run();  
}
