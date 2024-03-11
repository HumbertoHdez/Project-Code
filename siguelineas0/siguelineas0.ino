#define pwm0 26
#define pwm1 25
#define frecuencia 1000
#define canal_0 0
#define canal_1 1
#define resolution 12 

int Lec_1=0,Lec_2=0,Lec_3=0,Lec_4=0;
int pin_1=13,pin_2=12,pin_3=14,pin_4=27;
int m0=15,m1=2,m2=4,m3=16;
int vec_lec[4]={Lec_1,Lec_2,Lec_3,Lec_4};
int vec_pin[4]={pin_1,pin_2,pin_3,pin_4};
int vec_motor[4]={m0,m1,m2,m3};


void setup() {
  for(int i=0; i<=3; i++){
    pinMode(vec_pin[4],INPUT);
  }
  
  for(int i=0; i<=3; i++){
    pinMode(vec_motor[4],OUTPUT);
  }
  Serial.begin(115200);
  ledcSetup(canal_0,frecuencia,resolution);
  ledcSetup(canal_1,frecuencia,resolution);
  ledcAttachPin(pwm0,canal_0);
  ledcAttachPin(pwm1,canal_1);
}

void loop() {
  for(int i=0; i<=3; i++){
    vec_lec[i]=digitalRead(vec_pin[i]);
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" Valor del sensor: ");
    Serial.println(vec_lec[i]);
    delay(500);
  }
  //APAGADO
  if(Lec_1==0 || Lec_2==0 || Lec_3==0 || Lec_4==0){
    digitalWrite(m0,LOW);
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    ledcWrite(canal_0,0);
    ledcWrite(canal_1,0);
  }
  //REVERSA
  if(Lec_1==1 || Lec_2==1 || Lec_3==1 || Lec_4==1){
    digitalWrite(m0,LOW);
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
    ledcWrite(canal_0,4095);
    ledcWrite(canal_1,4095);
  }
  //ADELANTE
  if(Lec_1==0 || Lec_2==1 || Lec_3==1 || Lec_4==0){
    digitalWrite(m0,HIGH);
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    ledcWrite(canal_0,4095);
    ledcWrite(canal_1,4095);
  }
  //IZQUIERDA
  if(Lec_1==1 || Lec_2==1 || Lec_3==0 || Lec_4==0){
    digitalWrite(m0,HIGH);
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
    ledcWrite(canal_0,2047);
    ledcWrite(canal_1,4095);
  }
  //DERECHA
  if(Lec_1==0 || Lec_2==0 || Lec_3==1 || Lec_4==1){
    digitalWrite(m0,LOW);
    digitalWrite(m1,HIGH);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    ledcWrite(canal_0,4095);
    ledcWrite(canal_1,2047);
  }
}
