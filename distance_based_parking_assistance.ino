const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 10) {
    Serial.println("Buzzer ON - Close Distance");
    digitalWrite(buzzer, HIGH); 
  } else {
    Serial.println("Buzzer OFF - Safe Distance");
    digitalWrite(buzzer, LOW); 
  }

  delay(100);
}
