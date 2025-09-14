const int sensorPin = 28;
int sensorValue = 0;
const int buzzer = 16;

int Ode_to_Joy[] = {
E4, E4, F4, G4,
  G4, F4, E4, D4,
  C4, C4, D4, E4,
  E4, D4, C4
};

int noteDurations[] = {
  4, 4, 4, 4,   // quarter notes
  4, 4, 4, 4,
  4, 4, 4, 4,
  2, 2, 2       // half notes at the end
};

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 // Serial.println("starting!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
 pinMode(buzzer, OUTPUT);
  //Play song
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
    int duration = 1000 / noteDurations[i]; // 4 = quarter = 250ms at 60 bpm
    tone(speakerPin, melody[i], duration);
    delay(duration * 1.30);  // pause between notes
    noTone(speakerPin);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin) - 100;
  Serial.println(sensorValue);

  float scaled = 200 + ((sensorValue - 800) * (1000.0 -200) / (900.0-800.0));
  if (scaled < 200) scaled = 200;
  if (scaled > 1000) scaled = 1000;

  tone(buzzer,scaled);
  delay(100);
}
