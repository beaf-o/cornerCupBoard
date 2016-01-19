#define trigPin 0
#define echoPin 2
#define led 1

void setup() {
  //Serial.begin (9600); // Trinket has no Serial interface  https://learn.adafruit.com/trinket-fake-usb-serial/how-it-works
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 4) {
    digitalWrite(led,HIGH);
    delay(60000);
    //Serial.println("open");
  } else {
    digitalWrite(led,LOW);
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
