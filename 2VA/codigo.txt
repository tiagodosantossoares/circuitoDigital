#define e1 8
#define e2 9
#define e3 10
#define e4 11
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
boolean saidaA(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (!E2&&!E4) || (E1&&!E4) || (!E1&&E2&&E4) || (!E1&&!E2&&E3) || (E1&&E2&&E3) || (E1&&!E2&&!E3)||(E3&&!E4);
  }
boolean saidaB(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (!E2&&!E4) || (!E1&&!E2) || (!E1&&!E3&&!E4) || (E1&&!E3&&E4) || (!E1&&E3&&E4);
  }
boolean saidaC(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (E1&&!E2) || (!E2&&!E3) || (!E3&&E4) || (!E1&&E2) || (!E1&&E4);
  }
boolean saidaD(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (E1&&!E3&&!E4) || (!E2&&!E3&&!E4) || (E2&&!E3&&E4) || (!E2&&E3&&E4) || (!E1&&E3&&!E4) || (E2&&E3&&!E4);
  }
boolean saidaE(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (!E2&&!E4) || (E3&&!E4) || (E1&&E2) || (E1&&E3);
  }
boolean saidaF(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (E1&&!E2) || (!E3&&!E4 ) || (!E1&&E2&&!E3) || (E1&&E3) || (E2&&E3&&!E4);
  }
boolean saidaG(boolean E1,boolean E2, boolean E3,boolean E4) {
  return (E1&&!E2) || (E1&&E4) || (E3&&!E4) || (!E1&&!E2&&E3) || (!E1&&E2&&!E3);
  }


void setup() {
  //start serial connection
  
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(e1, INPUT);
  pinMode(e2, INPUT);
  pinMode(e3, INPUT);
  pinMode(e4, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  int a=0;
  for(a=0;a<7;a++){
    
  digitalWrite(a,1);
    delay(1000);
  }

  //Serial.begin(9600);
}

void loop() {
  boolean entrada1=digitalRead(e1);
  boolean entrada2=digitalRead(e2);
  boolean entrada3=digitalRead(e3);
  boolean entrada4=digitalRead(e4);
  //Serial.print(entrada1);
  //Serial.print(entrada2);
  //Serial.print(entrada3);
  //Serial.println(entrada4);
  digitalWrite(A,saidaA(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(B,saidaB(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(C,saidaC(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(D,saidaD(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(E,saidaE(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(F,saidaF(entrada1,entrada2,entrada3,entrada4));
  digitalWrite(G,saidaG(entrada1,entrada2,entrada3,entrada4));

  }