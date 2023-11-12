#include <Servo.h>

Servo servoMotor;

int servoPin = 9; // Pin al que está conectado el servo

int joystickPinX = A0; // Pin analógico para el eje X del joystick
int joystickPinY = A1; // Pin analógico para el eje Y del joystick

int joystickX; // Valor del eje X del joystick
int joystickY; // Valor del eje Y del joystick

void setup() {
  servoMotor.attach(servoPin); // Asignar el pin al servo
  Serial.begin(9600); // Iniciar comunicación serial
}

void loop() {
  joystickX = analogRead(joystickPinX); // Leer el valor del eje X del joystick
  joystickY = analogRead(joystickPinY); // Leer el valor del eje Y del joystick

  // Mapear los valores del joystick a los ángulos del servo
  int servoAngleX = map(joystickX, 0, 1023, 0, 180);
  int servoAngleY = map(joystickY, 0, 1023, 0, 180);

  // Mover el servo a los ángulos correspondientes
  servoMotor.write(servoAngleX);
  delay(100); // Pequeño retardo para evitar vibraciones
  
  servoMotor.write(servoAngleY);
  delay(100); // Pequeño retardo para evitar vibraciones
}
