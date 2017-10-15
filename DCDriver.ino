/* Simple sketch to test new DC motor drivers with a potentiometer using the map function */


int potPin = A0;								//declaring pins
int pwmA = 5;									// "
int pwmB = 6;									// "


void setup() {
	
	pinMode (potPin, INPUT);					//setting inputs and outputs
	pinMode (potPin, INPUT);					// "
	pinMode (potPin, INPUT);					// "

	Serial.begin(9600);
}

void loop() {

	int x = analogRead(potPin);					//read output from pot

	if(x >= 512) {

	y = map(x, 512, 1023, 0, 255);				//as the potentiometer turns clockwise from
	analogWrite (pwmA, y);						//center, the clockwise motor output increases

	//print input and output values to serial monitor 
	Serial.println("Potentiometer: " + x + ", output A: " + y + ", output B: 0.");

	}

	else {

	y = map(x, 511, 0, 0, 255);					//as the potentiometer turns counter-clockwise from
	analogWrite (pwmB, y);						//center, the counter-clockwise motor output increases

	//print input and output values to serial monitor
	Serial.println("Potentiometer: " + x + ", output A: 0, output B: " + y + ".");
	
	}

	delay(1000); 								//loop per second
}