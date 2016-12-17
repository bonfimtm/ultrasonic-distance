/*
 * Distances in centimeters
 */
float THRESHOLD = 20.0;
float distance = 0.0f;

/*
 * Pins
 */
int ECHO = 12;
int TRIG = 11;
int RELAY = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

void loop()
{
  // Sends the signal
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Calculates the distance
  distance = pulseIn(ECHO, HIGH) / 58.0f;

  if (distance < THRESHOLD) {
    digitalWrite(RELAY, HIGH);
  } else {
    digitalWrite(RELAY, LOW);
  }

  // Prints the distance in the serial port
  Serial.println(distance);
  
  delay(200);
}
