// Declaración de pines
int motorIzquierdoA = 2;
int motorIzquierdoB = 3;
int motorDerechoA = 4;
int motorDerechoB = 5;
int centro=1;

void setup() {
   // Inicialización de la comunicación serial
  Serial.begin(115200);
  Serial.setTimeout(10);
  while(!Serial){}
  // Configuración de los pines como salida
  pinMode(motorIzquierdoA, OUTPUT);
  pinMode(motorIzquierdoB, OUTPUT);
  pinMode(motorDerechoA, OUTPUT);
  pinMode(motorDerechoB, OUTPUT);
}

void loop() {
 if(Serial.available()>1){
  // Lee los datos recibidos
  int centro = Serial.parseInt();
  //Serial.print(centro);
  
  // Control de los motores en función del centro del pasillo
  if (centro == 315) { // Si el centro está a la izquierda
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
    digitalWrite(motorDerechoA, HIGH);
    digitalWrite(motorDerechoB, LOW);
    delay(100);
  } else if (centro == 325) { // Si el centro está a la derecha
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, HIGH);
    delay(100);
  } else if (centro == 320){ // Si el centro está en el centro del pasillo
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
    digitalWrite(motorDerechoA, HIGH);
    digitalWrite(motorDerechoB, LOW);
  } else {
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, LOW);
    digitalWrite(motorDerechoA, LOW);
    digitalWrite(motorDerechoB, LOW);
  }
  }
}