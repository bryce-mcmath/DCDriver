#include <Encoder.h>

Encoder myEnc(2, 3);				//declaring encoder pins (both interrupts)

int potPin = A0;              		//declaring pins
int pwmA = 5;        		        // "
int pwmB = 6;             		    // "


void setup() {
  
  pinMode (potPin, INPUT);          //setting inputs and outputs
  pinMode (potPin, INPUT);          // "
  pinMode (potPin, INPUT);          // "

  Serial.begin(9600);
}

long oldPosition  = -999;

void loop() {

    long newPosition = myEnc.read();

      oldPosition = newPosition;
      Serial.println("Encoder pulse count is: " + String(newPosition));

  int x = analogRead(potPin);         	//read output from pot
  int y;
  
  if(x >= 512) {
    
  analogWrite(pwmB, 0);					//sets alternate PWM pin to low
  y = map(x, 512, 1023, 0, 255);        //as the potentiometer turns clockwise from
  analogWrite (pwmA, y);            	//center, the clockwise motor output increases

  //print input and output values to serial monitor 
  Serial.println("Potentiometer: " + String(x) + ", output A: " + String(y) + ", output B: 0.");

  }

  else {
    
  analogWrite(pwmA, 0);					//sets alternate PWM pin to low
  y = map(x, 511, 0, 0, 255);         	//as the potentiometer turns counter-clockwise from
  analogWrite (pwmB, y);            	//center, the counter-clockwise motor output increases

  //print input and output values to serial monitor
  Serial.println("Potentiometer: " + String(x) + ", output A: 0, output B: " + String(y) + ".");
  
  }

  delay(1000);                			//loop per second
}