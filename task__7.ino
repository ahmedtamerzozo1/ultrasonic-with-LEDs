// C++ code
//
int trig = 9;
int echo = 8;
long distance;
long time;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH); 

  distance = 0.0343 * (time / 2);

  if (distance >= 75) {
    digitalWrite(10, HIGH); 
  } else {
    digitalWrite(10, LOW); 
  }

  if (distance >= 150) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }

  if (distance >= 250) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  if (distance >= 325) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); 
}