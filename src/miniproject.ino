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
// Sensor reading values
int sensorValue = 0;
// Pin that the buzzer is connected to
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
  // Play song
  for (int i = 0; i < sizeof(Ode_to_Joy)/sizeof(Ode_to_Joy[0]); i++) {
    int duration = 1000 / noteDurations[i]; // 4 = quarter = 250ms at 60 bpm
    tone(buzzer, Ode_to_Joy[i], duration);
    delay(duration * 1.30);  // pause between notes
    noTone(buzzer);
  }
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
