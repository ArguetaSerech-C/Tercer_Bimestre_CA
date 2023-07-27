/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: acelerometro
   Dev: Carlos Argueta Serech
*/

#include <Wire.h>
#include <SPI.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>

//Directivas
#define ancho_matriz 8 
#define alto_matriz 8
#define DATO_PIN 11
#define CLK_PIN 13
#define CS_PIN 10

//Variables
float xg,yg,zg;
float soh;
float tilt;
float angle;

const byte derecha5[8] = {
B00000000,
B11111111,
B11111111,
B00000001,
B00000001,
B11111111,
B11111111,
B00000000
};

const byte derecha4[8] = {
B00000000,
B11111111,
B11111111,
B00000011,
B00000011,
B11111111,
B11111111,
B00000000
};

const byte derecha3[8] = {
B00000000,
B11111111,
B11111111,
B00000110,
B00000110,
B11111111,
B11111111,
B00000000
};

const byte derecha2[8] = {
B00000000,
B11111111,
B11111111,
B00001100,
B00001100,
B11111111,
B11111111,
B00000000
  };

const byte derecha1[8] = {
B00000000,
B11111111,
B11111111,
B00001000,
B00001000,
B11111111,
B11111111,
B00000000
  };

const byte centrado[8] = {
B00000000,
B11111111,
B11111111,
B00011000,
B00011000,
B11111111,
B11111111,
B00000000};

const byte izquierda1[8] = {
B00000000,
B11111111,
B11111111,
B00010000,
B00010000,
B11111111,
B11111111,
B00000000};

const byte izquierda2[8] = {
B00000000,
B11111111,
B11111111,
B00110000,
B00110000,
B11111111,
B11111111,
B00000000
};

const byte izquierda3[8] = {
B00000000,
B11111111,
B11111111,
B01100000,
B01100000,
B11111111,
B11111111,
B00000000
};

const byte izquierda4[8] = {
B00000000,
B11111111,
B11111111,
B11000000,
B11000000,
B11111111,
B11111111,
B00000000
};

const byte izquierda5[8] = {
B00000000,
B11111111,
B11111111,
B10000000,
B10000000,
B11111111,
B11111111,
B00000000
};

//Constructores
LedControl Matrisjl = LedControl(DATO_PIN,CLK_PIN,CS_PIN,1);
ADXL345 posicion = ADXL345();
void setup() {
   Serial.begin(9600);    
   Matrisjl.shutdown(0,false);    
   Matrisjl.setIntensity(0,15);   
   Matrisjl.clearDisplay(0);    
   posicion.powerOn();           
   posicion.setRangeSetting(8);       

}

void loop() {
   nivelacion();
   animacion(); 
}

void nivelacion(){
  int sumax = 0;
  int x, y, z;
  posicion.readAccel(&x, &y, &z);
     xg = x*0.0039;
     yg = y*0.0039;
     zg = z*0.0039;
     soh = xg/zg;
     tilt = atan(soh)*57.296;
}
void animacion(){
  if(tilt >= -5 && tilt <= 5){  //centro
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, centrado[i]);
      }
  }

  if((tilt > 5) && (tilt <= 15 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, derecha1[i]);
      }
  }
  
  if((tilt > 15) && (tilt <= 30 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, derecha2[i]);
      }
  }

  if((tilt > 30) && (tilt <= 45 )){  
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, derecha3[i]);
      }
  }
  
  if((tilt > 45) && (tilt <= 60 )){  
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, derecha4[i]);
      }
  }
  if((tilt > 60) && (tilt <= 90 )){  
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, derecha5[i]);
      }
  }
    if((tilt < -60) && ( tilt >= -90) ){
    for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i,derecha5[i]);
      }
  }
  if((tilt < -45) && (tilt >= -60 )){ 
    for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i,derecha4[i]);
      }
  }
    if((tilt < -30) && (tilt >= -45 )){ 
    for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i,derecha3[i]);
      }
  }
    if((tilt < -15) && (tilt >= -30 )){  
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i,derecha2[i]);
      }
  }
    if((tilt < -5) && (tilt >= -15 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    Matrisjl.setColumn(0, i, izquierda1[i]);
      }
  }
  }
