int redLed = 9;
int blueLed = 10;
int yellowLed = 11;
String led;

int lb;
int writeVal;

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(yellowLed, LOW);
  // put your setup code here, to run once:

}

void loop() {
  Serial.print("What LED do you want to turn on (Red, Yellow, Blue): ");
  while (Serial.available() == 0){

  }
  led = Serial.readStringUntil('\n');
  led.trim();
  led.toLowerCase();
  while (Serial.available() > 0){
    Serial.read();
  }
  Serial.println(led);

  if (led == "red" || led == "yellow" || led == "blue"){
    Serial.print("How Bright do you want it to be (1-10): ");
    while (Serial.available() == 0){
  
    }
    lb = Serial.parseInt();
    while (Serial.available() > 0) {
      Serial.read(); // Clear the serial buffer
    }
    Serial.println(lb);
    if (lb >= 1 && lb <= 10){
      writeVal = pow(2,(8./10. * lb) - 1);
      analogWrite(redLed, 0);
      analogWrite(yellowLed, 0);
      analogWrite(blueLed, 0);
      
      if (led == "red"){
        analogWrite(redLed, writeVal);
      }
      else if (led == "yellow"){
        analogWrite(yellowLed, writeVal);
      }
      else if (led == "blue"){
        analogWrite(blueLed, writeVal);
      }
    }
    else{
    	Serial.println("Invalid Brightness Level (must be 1-10)");
    }
  }
  else {
    Serial.println("Invalid LED");
  }
  delay(1000);
  // put your main code here, to run repeatedly:

}
