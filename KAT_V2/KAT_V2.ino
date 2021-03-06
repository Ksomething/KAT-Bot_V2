// LEFT Motor
#define motorA1 46
#define motorA2 52
#define motorAS 7
// RIGHT Motor
#define motorB1 50
#define motorB2 48
#define motorBS 6

const int sensor1_trig = 28;
const int sensor1_echo = 4;
const int sensor2_trig = 24;
const int sensor2_echo = 2;
const int sensor3_trig = 26;
const int sensor3_echo = 12;

long distance1 = 0;
long distance2 = 0;
long distance3 = 0;
long duration = 0;

int a_speed = 50;
int b_speed = 50;

void setup() {
  // put your setup code here, to run onsce:
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAS, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBS, OUTPUT);
  
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
  Serial.println("cm");   MoveForward();
  
 /* if (distance2 <= 15 and distance3 <=15 and distance1 > 15){
    MoveForward(130);
    }else if (distance2 <= 15 and distance3 > 15 and distance1 > 15){
      RotateRight(130);
    }else if (distance2 <= 15 and distance3 > 15 and distance1 <= 15){
        RotateRight(130);
    }

  if (distance2 > 15 and distance3 <= 15 and distance1 > 15){
      MoveForward(130);
    }else if (distance2 > 15 and distance3 <= 15 and distance1 <= 15){
        RotateLeft(130);
     }

   if (distance2 <= 15 and distance3 <= 15 and distance1 <= 15){
        RotateRight(130);
      }  */
}

// Sensor Function
void DetectSensor(int sensor_trig, int sensor_echo) {
  
  digitalWrite(sensor_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_trig, LOW);
  
  duration = pulseIn(sensor_echo, HIGH);
}

// Functions for motors and direction
void MoveForward() {

  dontHit();
  analogWrite(motorAS, a_speed);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);

  analogWrite(motorBS, b_speed);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  dontHit();
}

void MoveBack(int spd) {

  analogWrite(motorAS, a_speed);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);

  analogWrite(motorBS, b_speed);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void RotateLeft(int spd) {

  analogWrite(motorAS, a_speed);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);

  analogWrite(motorBS, b_speed);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void RotateRight(int spd) {

  analogWrite(motorAS, a_speed);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);

  analogWrite(motorBS, b_speed);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void dontHit(){ 
  int dl = distance2;
  int dr = distance3;
  if (dl > dr){
    b_speed = 160; 
  } else if (dr > dl){
    a_speed = 160;
  }else{
    b_speed = 50;
    a_speed = 50;
  }
}


