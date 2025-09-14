
enum Note {
  NOTE_C4 = 262,
  NOTE_D4 = 294,
  NOTE_E4 = 330,
  NOTE_F4 = 349,
  NOTE_G4 = 392,
  NOTE_A4 = 440,
  NOTE_B4 = 494,
  NOTE_C5 = 523
};

const int sensorPin = 28;
int sensorValue = 0;
const int buzzer = 16;
// song
int Ode_to_Joy[] = {
NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_C4
};
// duration of notes 
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
  for (int i = 0; i < sizeof(Ode_to_Joy)/sizeof(Ode_to_Joy[0]); i++) {
    int duration = 1000 / noteDurations[i]; // 4 = quarter = 250ms at 60 bpm
    tone(buzzer, Ode_to_Joy[i], duration);
    delay(duration * 1.30);  // pause between notes
    noTone(buzzer);
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
