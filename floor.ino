// Buttons
int button0 = A1;
int button1 = 9;
int button2 = 10;
int button3 = 11;

// LEDs
int led0 = A2;
int led1 = 12;
int led2 = 13;
int led3 = A0;

// Buzzer
int buzzer = A3;

// 7-segment
int a=2,b=3,c=4,d=5,e=6,f=7,g=8;

// ===== SETUP =====
void setup(){

  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  show0();
  groundIndication();
}

// ===== DISPLAY =====
void clearDisplay(){
  digitalWrite(a,LOW); digitalWrite(b,LOW); digitalWrite(c,LOW);
  digitalWrite(d,LOW); digitalWrite(e,LOW); digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void show0(){
  clearDisplay();
  digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH);
  digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH);
}

void show1(){
  clearDisplay();
  digitalWrite(b,HIGH); digitalWrite(c,HIGH);
}

void show2(){
  clearDisplay();
  digitalWrite(a,HIGH); digitalWrite(b,HIGH);
  digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(g,HIGH);
}

void show3(){
  clearDisplay();
  digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH);
  digitalWrite(d,HIGH); digitalWrite(g,HIGH);
}

// ===== LED + BUZZER TOGETHER =====
void alert(int led){

  digitalWrite(led, HIGH);
  tone(buzzer, 1000);   // buzzer ON

  delay(3000);          // 3 sec

  digitalWrite(led, LOW);
  noTone(buzzer);       // buzzer OFF
}

// ===== GROUND FLOOR =====
void groundIndication(){

  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);

  // blink 10 times
  for(int i=0;i<10;i++){
    digitalWrite(led0,HIGH);
    delay(300);
    digitalWrite(led0,LOW);
    delay(300);
  }

  alert(led0); // 3 sec LED + buzzer
}

// ===== NORMAL FLOORS =====
void operateLED(int led){

  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);

  // blink 5 times
  for(int i=0;i<5;i++){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }

  alert(led); // 3 sec LED + buzzer together
}

// ===== LOOP =====
void loop(){

  if(digitalRead(button0)==LOW){
    delay(50);
    if(digitalRead(button0)==LOW){
      show0();
      groundIndication();
      while(digitalRead(button0)==LOW);
    }
  }

  if(digitalRead(button1)==LOW){
    delay(50);
    if(digitalRead(button1)==LOW){
      show1();
      operateLED(led1);
      while(digitalRead(button1)==LOW);
    }
  }

  if(digitalRead(button2)==LOW){
    delay(50);
    if(digitalRead(button2)==LOW){
      show2();
      operateLED(led2);
      while(digitalRead(button2)==LOW);
    }
  }

  if(digitalRead(button3)==LOW){
    delay(50);
    if(digitalRead(button3)==LOW){
      show3();
      operateLED(led3);
      while(digitalRead(button3)==LOW);
    }
  }

}