/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: Control de secuencia de colores rbg
*/

#define LedR 3  
#define LedG 5
#define LedB 6
#define pot_pwm A0    


//Variables
unsigned int pot = 0;
unsigned int tiempo_v =0;
unsigned int Tiempo =0;


void setup()
{

 pinMode(pot_pwm, INPUT); 
 pinMode(LedR, OUTPUT);  
 pinMode(LedB, OUTPUT); 
 pinMode(LedG, OUTPUT);  
 
}


void loop() 
{
pot = analogRead(pot_pwm); 
tiempo_v= map(pot, 0, 1022,100,1000);
  analogWrite(LedG, 92);
  analogWrite(LedR, 174);
  analogWrite(LedB, 230);
  delay(tiempo_v);
  analogWrite(LedG, 255);
  analogWrite(LedR, 255);
  analogWrite(LedB, 255);
  delay(tiempo_v);
  analogWrite(LedG, 255);
  analogWrite(LedR, 0);
  analogWrite(LedB, 255);
  delay(tiempo_v);
  analogWrite(LedG, 174);
  analogWrite(LedR, 189);
  analogWrite(LedB, 20);
  delay(tiempo_v);
  analogWrite(LedG, 87);
  analogWrite(LedR, 225);
  analogWrite(LedB, 35);
}
