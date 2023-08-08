const int sensorPin = A0; // Triboelectric pressure sensor pin
const int voltagePin = A1; // Voltage output pin
const int length = 45; // Length of the sensor in mm
long time1;
long time2;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(voltagePin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int pressure = analogRead(sensorPin); // Read the pressure applied to the sensor
  int voltage = (pressure * 5.0) / 1023; // Calculate voltage generated from the sensor
  analogWrite(voltagePin, voltage); // Output voltage to the voltage pin
  if (voltage > 0) {
    time1 = millis(); // Get the time when the voltage is detected
  }
  if (voltage == 0) {
    time2 = millis(); // Get the time when the voltage is no longer detected
  }
  // Calculate the time taken by the vehicle to pass through the sensor
  float timeTaken = (time2 - time1) * 0.001;
  // Calculate the speed of the vehicle
  float speed = abs(length / timeTaken) ;
  Serial.print("Vehicle speed: ");
  Serial.print(speed);
  Serial.println(" mm/s");
  delay(500);
}