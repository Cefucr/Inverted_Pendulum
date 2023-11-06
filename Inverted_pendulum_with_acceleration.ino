//pin config

#define PWMA   6           //Left Motor Speed pin
#define AIN2   A0          //Left Motor Forward
#define AIN1   A1          //Left Motor Backwards

#define PWMB   5           //Right Motor Speed pin
#define BIN1   A2          //Right Motor Forward
#define BIN2   A3          //Right Motor Backwards


//this is the value of the potentiometer when it is standing straight
int midpoint = 570;

//the speed which the robot starts moving
int startspd = 150;

//gives the stick some space before it tells the robot to start moving
int space = 5;

void setup() {

  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);
  Serial.begin(9600);
  
  //gives you some time to put the robot down on the ground
  delay(2000);
}
void loop() {

  //Checks the value of the potentiometer to see how much the stick has tilted
  int potentio = analogRead(5);
  
  if(potentio < midpoint - space){
    //goes faster if stick is tilted more
    int acc = (potentio - midpoint) * (-1) * 4 + startspd;

    //in case the value is more than the max speed of the motor the value goes to the max speed
    if(acc > 250){
      int acc = 250;
      forward(acc);
    }else{
      forward(acc);
    }
  }else if(potentio > midpoint + space){
    int acc = (potentio - midpoint) * 4 + startspd;

    if(acc > 250){
      int acc = 250;
      backwards(acc);
    }else{
      backwards(acc);
    }
  }else{
    stop();
  }
}

void forward(int speed) {
  analogWrite(PWMA,speed);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);

  analogWrite(PWMB,speed);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
}

void backwards(int speed) {
  analogWrite(PWMA,speed);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);

  analogWrite(PWMB,speed);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);
  
}

void stop() {
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
}
