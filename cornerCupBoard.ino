#define trigPin 2
#define echoPin 0
#define upperLed 1
#define lowerLed 3

void setup() {
  //Serial.begin (9600); // Trinket has no Serial interface  https://learn.adafruit.com/trinket-fake-usb-serial/how-it-works
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(upperLed, OUTPUT);
  pinMode(lowerLed, OUTPUT);

  switchOff();
  startSequence();
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 4) {
    switchOn();
    delay(10000);
    //Serial.println("open");
  } else {
    switchOff();
    //Serial.println("closed");
  }

/*
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
*/
  delay(100);
}

void startSequence() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(upperLed, HIGH);
    delay(100);
    digitalWrite(upperLed, LOW);
    digitalWrite(lowerLed, HIGH);
    delay(100);
    digitalWrite(lowerLed, LOW);
  }
}

void switchOn() {
  digitalWrite(upperLed, HIGH);
  delay(300);
  digitalWrite(lowerLed, HIGH);
}

void switchOff() {
  digitalWrite(upperLed, LOW);
  delay(300);
  digitalWrite(lowerLed, LOW);
}
