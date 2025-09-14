// Unit Test for the map function

int mapTest(int sensorValue){
  float scaled = map(sensorValue, 700, 900, 200, 600);

  if (scaled < 262) return 262;
  else if (scaled < 294) return 294;
  else if (scaled < 330) return 330;
  else if (scaled < 349) return 349;
  else if (scaled < 392) return 392;
  else if (scaled < 440) return 440;
  else if (scaled < 494) return 494;
  else return 523;
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

  assertEqual(mapTest(700), 262, "Note_test_low");
  assertEqual(mapTest(800), 440, "Note_test_middle");
  assertEqual(mapTest(900), 523, "Note_test_high");
}

void loop() {

}


// If our logic is correct, which it will
// It should say something like Test ... passed in the Serial Monitor
