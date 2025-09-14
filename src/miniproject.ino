const int sensorPin = 28;
int sensorValue = 0;
const int buzzer = 16;

void setup() {
  Serial.begin(9600);
  Serial.println("starting!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // read sensor
  sensorValue = analogRead(sensorPin) - 100;

  // scale value
  // float scaled = 200 + ((sensorValue - 800) * (1000.0 -200) / (900.0-800.0));
  float scaled = map(sensorValue, 700, 900, 200, 600);

  Serial.print("scaled: ");
  Serial.println(scaled);


  // note definitions
  if (scaled < 262) {
    // C4
    scaled = 262;
  } else if (scaled >= 262 && scaled < 294) {
    // D4
    scaled = 294;
  } else if (scaled >= 294 && scaled < 330) {
    // E4
    scaled = 330;
  } else if (scaled >= 330 && scaled < 349) {
    // F4
    scaled = 349;
  } else if (scaled >= 349 && scaled < 392) {
    // G4
    scaled = 392;
  } else if (scaled >= 392 && scaled < 440) {
    // A4
    scaled = 440;
  } else if (scaled >= 440 && scaled < 494) {
    // B4
    scaled = 494;
  } else if (scaled >= 494) {
    // C5
    scaled = 523;
  }

  tone(buzzer,scaled);
  delay(100);
}
