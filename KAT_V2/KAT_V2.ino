const int sensor1_trig = 28;
const int sensor1_echo = 4;
const int sensor2_trig = 24;
const int sensor2_echo = 2;
const int sensor3_trig = 26;
const int sensor3_echo = 3;

long distance1 = 0;
long distance2 = 0;
long distance3 = 0;
long duration = 0;

void setup() {
  // put your setup code here, to run onsce:
  Serial.begin(9600);
  pinMode(sensor1_trig, OUTPUT);
  pinMode(sensor1_echo, INPUT);
  pinMode(sensor2_trig, OUTPUT);
  pinMode(sensor2_echo, INPUT);
  pinMode(sensor3_trig, OUTPUT);
  pinMode(sensor3_echo, INPUT);
}

void loop() {
  DetectSensor(sensor1_trig, sensor1_echo);
  distance1 = (duration/2) / 29.1;
  DetectSensor(sensor2_trig, sensor2_echo);
  distance2 = (duration/2) / 29.1;
  DetectSensor(sensor3_trig, sensor3_echo);
  distance3 = (duration/2) / 29.1;

  Serial.print("Sensor 1 - Distance: ");
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print("Sensor 2 - Distance: ");
  Serial.print(distance2);
  Serial.println("cm");
  Serial.print("Sensor 3 - Distance: ");
  Serial.print(distance3);
  Serial.println("cm");
}

void DetectSensor(int sensor_trig, int sensor_echo) {
  
  digitalWrite(sensor_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_trig, LOW);
  
  duration = pulseIn(sensor_echo, HIGH);
}

/*
void DetectSensor2() {
  
  digitalWrite(sensor2_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor2_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor2_trig, LOW);
  duration2 = pulseIn(sensor2_echo, HIGH);
  distance2 = (duration2/2) / 29.1;

  Serial.print("Sensor 2 - Distance: ");
  Serial.print(distance2);
  Serial.println("cm");
}
void DetectSensor3() {
  
  digitalWrite(sensor3_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor3_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor3_trig, LOW);
  duration3 = pulseIn(sensor3_echo, HIGH);
  distance3 = (duration3/2) / 29.1;

  Serial.print("Sensor 3 - Distance: ");
  Serial.print(distance3);
  Serial.println("cm");
}
*/

