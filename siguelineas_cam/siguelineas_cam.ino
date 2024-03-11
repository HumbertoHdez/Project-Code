#include <ESP32Servo.h>
#include "esp32cam.h"

Servo servoLeft;  // Servo izquierdo
Servo servoRight; // Servo derecho

// Configuración de pines para los servos
int leftServoPin = 13;
int rightServoPin = 12;

// Configuración de pines de la cámara ESP32-CAM
const int camera_xclk = 0;
const int camera_pclk = 0;
const int camera_vsync = 0;
const int camera_sda = 0;
const int camera_scl = 0;
const int camera_reset = 0;
const int camera_pwdn = 0;
const int camera_sioc = 0;
const int camera_siod = 0;

void setup() {
  // Inicialización de los servos
  servoLeft.attach(leftServoPin);
  servoRight.attach(rightServoPin);

  // Inicialización de la cámara
  esp32cam_init(camera_xclk, camera_pclk, camera_vsync, camera_sda, camera_scl, camera_reset, camera_pwdn, camera_sioc, camera_siod);
}

void loop() {
  // Aquí irá la lógica para el seguidor de línea usando la cámara.
  // Esto implica capturar imágenes, procesarlas para detectar la línea y controlar los motores en consecuencia.

  // Ejemplo básico de movimientos
  // Gira a la izquierda
  moveLeft();
  delay(1000);

  // Gira a la derecha
  moveRight();
  delay(1000);

  // Avanza
  moveForward();
  delay(1000);
}

void moveForward() {
  // Lógica para que el carro avance
  // Por ejemplo:
  servoLeft.write(90);  // ajusta el servo izquierdo para avanzar
  servoRight.write(90); // ajusta el servo derecho para avanzar
}

void moveLeft() {
  // Lógica para que el carro gire a la izquierda
  // Por ejemplo:
  servoLeft.write(70);  // ajusta el servo izquierdo para girar a la izquierda
  servoRight.write(110); // ajusta el servo derecho para girar a la izquierda
}

void moveRight() {
  // Lógica para que el carro gire a la derecha
  // Por ejemplo:
  servoLeft.write(110);  // ajusta el servo izquierdo para girar a la derecha
  servoRight.write(70); // ajusta el servo derecho para girar a la derecha
}