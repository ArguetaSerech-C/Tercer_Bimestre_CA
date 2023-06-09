/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: Control de brillo de led
*/

#define led 3
#define potenciometro A0
void setup() {
  pinMode(led, OUTPUT);
  pinMode(potenciometro, INPUT);
}
void loop() {
  analogWrite(led,analogRead(potenciometro)/4);
}
