// Unit Test for the Scaler

// If the light is low going from 0-800, the buzzer should make 200 Hz
// If the light is in range of 800-900, the buzzer should make 200-1000 Hz
// If the light is higher than 900, the buzzer should make 1000 Hz

float Scaler(int sensorValue) {
  float scaled = 200 + ((sensorValue - 800) * (1000 - 200) / (900 - 800));
  if (scaled < 200) scaled = 200;
  if (scaled > 1000) scaled = 1000;
  return scaled;
}

void assertEqual(float actual, float expected, const char* test) {
  if (actual == expected) {
    Serial.print(test);
    Serial.println(" passed");
  } else {
    Serial.print(test);
    Serial.print(" failed: expected ");
    Serial.print(expected);
    Serial.print(", got ");
    Serial.println(actual);
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  assertEqual(Scaler(0), 200, "Scaler_test_low");
  assertEqual(Scaler(800), 200, "Scaler_test_in_range_low");
  assertEqual(Scaler(900), 1000, "Scaler_test_in_range_high");
  assertEqual(Scaler(1200), 1000, "Scaler_test_high");
}

void loop() {

}


// If our logic is correct, which it will
// It should say something like Test ... passed in the Serial Monitor
