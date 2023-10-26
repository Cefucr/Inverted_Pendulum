#define PWMA   6           //Left Motor Speed pin
#define AIN2   A0          //Motor-L forward
#define AIN1   A1          //Motor-L backward
#define PWMB   5           //Right Motor Speed pin
#define BIN1   A2          //Motor-R forward
#define BIN2   A3          //Motor-R backward
  
void setup() {
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //Checks the value of the potentiometer to see how much the stick has tilted
  int tasapaino = analogRead(5);

  if(tasapaino < 560){
    //goes forward
    analogWrite(PWMA,250);
    digitalWrite(AIN1,HIGH);
    digitalWrite(AIN2,LOW);
    analogWrite(PWMB,250);
    digitalWrite(BIN1,HIGH); 
    digitalWrite(BIN2,LOW);

  }else if(tasapaino > 580){
    //goes backwards
    analogWrite(PWMA,250);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);
    analogWrite(PWMB,250);
    digitalWrite(BIN1,LOW); 
    digitalWrite(BIN2,HIGH);

  }else{
    //stops
    analogWrite(PWMA,50);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,LOW);
    analogWrite(PWMB,50);
    digitalWrite(BIN1,LOW); 
    digitalWrite(BIN2,LOW);
  }
  Serial.println(tasapaino);
}
