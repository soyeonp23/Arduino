int seg[7] ={2,3,4,5,6,7,8};
int dot   =  9;
int PLUS  = 13;
int MINUS = 12;
int num   =  0;
byte digits [16][7] = {
  {0,0,0,0,0,0,1}, //0
  {1,0,0,1,1,1,1}, //1
  {0,0,1,0,0,1,0}, //2
  {0,0,0,0,1,1,0}, //3
  {1,0,0,1,1,0,0}, //4
  {0,1,0,0,1,0,0}, //5
  {0,1,0,0,0,0,0}, //6
  {0,0,0,1,1,1,1}, //7
  {0,0,0,0,0,0,0}, //8
  {0,0,0,0,1,0,0}, //9
  {0,0,0,1,0,0,0}, //A
  {1,1,0,0,0,0,0}, //b
  {0,1,1,0,0,0,1}, //C
  {1,0,0,0,0,1,0}, //d
  {0,1,1,0,0,0,0}, //E
  {0,1,1,1,0,0,0}  //F
};

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<7; i++) {
    pinMode(seg[i],OUTPUT);
  }
  pinMode(dot,   OUTPUT);
  pinMode(PLUS,  INPUT_PULLUP);
  pinMode(MINUS, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PLUS)==LOW) {
    num++; //num=num+1
    if (num >15) num = 0;
  }
  if (digitalRead(MINUS)==LOW) {
    num--; //num=num-1
    if (num<0) num = 15;
  }
  displayDigit(num);
  delay(1000);
}

void displayDigit(int n) {
  for (int i=0; i<15; i++) {
    digitalWrite(seg[i], digits[n][i]);
  }
  if (n%2 == 0) digitalWrite(dot, LOW);
  else digitalWrite(dot, HIGH);
}