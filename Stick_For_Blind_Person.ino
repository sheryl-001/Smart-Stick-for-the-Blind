// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int motor = 5;
const int led_pin = 7;
// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(motor, OUTPUT);
//pinMode(motor, INPUT); 
pinMode(led_pin,OUTPUT);


digitalWrite(led_pin,LOW);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 30){
  digitalWrite(buzzer, HIGH);
  digitalWrite(motor, HIGH);
  Serial.print("Obstacle -------vibration motor on! ");
  digitalWrite(led_pin,HIGH);
  delay(500);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(motor, LOW);
  digitalWrite(led_pin,LOW);
  delay(500);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance(cm): ");
Serial.println(distance);
}

//ultrasonic sensor vcc to vin, trig to d9, echo to d10, gnd to gnd
//buzzer -ve to gnd, +ve to d11