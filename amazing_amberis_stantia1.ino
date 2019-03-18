/*
 Input Pullup Serial

 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin 2 and prints the results to the serial monitor.
 
 OPEN THE SERIAL MONITOR TO SEE THE OUTPUT FROM THE INPUT PIN >>

 The circuit:
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  
  pinMode(13,OUTPUT );
  pinMode(12,INPUT_PULLUP );
  pinMode(11,INPUT_PULLUP );
  pinMode(7,INPUT_PULLUP );
  pinMode(6,INPUT_PULLUP );
  pinMode(5,INPUT_PULLUP );
  pinMode(4,INPUT_PULLUP );
  pinMode(3,INPUT_PULLUP );
  pinMode(2,INPUT_PULLUP );
  floop();
  

}
void loop(){
//delay(500);
//  digitalWrite(13,!digitalRead(13));

}
void floop() {
  while(true){
   delay(500);
   
  int AND=!digitalRead(7);//and
  int OR=!digitalRead(6);//or
  int XOR=!digitalRead(5);//xor
  int NAND=!digitalRead(4);//nand
  int NOR=!digitalRead(3);//nor
  int XNOR=!digitalRead(2);//XNOR
  
  int en1=!digitalRead(12);//XNOR
  int en2=!digitalRead(11);//XNOR
  
  
  if(AND==HIGH){
    Serial.println("and");
  	digitalWrite(13,en1&en2);
    continue;
  }
  if(OR==HIGH){
    Serial.println("or");
  	digitalWrite(13,en1|en2);
    continue;
  }
  if(XOR==HIGH){
    Serial.println("xor");
  	digitalWrite(13,en1^en2);
    continue;
  }
  if(NAND==HIGH){
    Serial.println("nand");
  	digitalWrite(13,!(en1&en2));
    continue;
  }
  if(NOR==HIGH){
    Serial.println("nor");
  	digitalWrite(13,!(en1|en2));
    continue;
  }
  if(XNOR==HIGH){
    Serial.println("xnor");
  	digitalWrite(13,!(en1^en2));
    continue;
  }
  }
}