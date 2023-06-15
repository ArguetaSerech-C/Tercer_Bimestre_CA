/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: OHMIMETRO
*/


#include <LiquidCrystal.h>
#define voltajeDivisor A0 
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define RS  6
#define Enable 7

int medicionRES();

LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7); 

  void setup()
{
  lcd.begin(16,2); 
  Serial.begin(9600);
  pinMode(voltajeDivisor, INPUT);
}
void loop() {
  lcd.setCursor(0,0);
  lcd.print("Resistencia");
  
  unsigned long int ohms = medicionRES();
  lcd.setCursor(7,2);
  lcd.print("k");

}
 int medicionRES(){
    int lectura = 0;   
    int Ve = 5;  
    float VR2 = 0;    
    float R1 = 10000;    
    float R2 = 0;        
    float relacion = 0;
     lectura = analogRead(voltajeDivisor);
   if(lectura) 
  {
    relacion = lectura * Ve; 
    VR2 = (relacion)/1023.0;  
  relacion = (Ve/VR2) -1;   
    R2= (R1 * relacion)-10;  
  
    delay(500);
   
    lcd.setCursor(0,2);
    Serial.println(R2);
    lcd.print(R2);

    return R2;
  } 
  }
