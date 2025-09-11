const int sensorPin = 28;
int sensorValue = 0;
const int buzzer = 16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("starting!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  pinMode(buzzer, OUTPUT);
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
