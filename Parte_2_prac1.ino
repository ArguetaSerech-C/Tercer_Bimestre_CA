/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: INTERRUPCIONES POR MEDIO DE SOFTWARE
*/

#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define boton 2
//Funcion ISR
void sensortemp();
void push_boton();


Ticker accion_temperatura(sensortemp,3000);
Ticker state_boton(push_boton,6000);
OneWire ourWire(4);
DallasTemperature sensor(&ourWire);

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  accion_temperatura.start();
  state_boton.start();
  sensor.begin();
}

void loop() {
  accion_temperatura.update();
  state_boton.update();
}

void sensortemp(){
  sensor.requestTemperatures();   
  float temp= sensor.getTempCByIndex(0); 
  Serial.println("Sensor de Temperatura");
  Serial.print("La Temeperatura es: ");
  Serial.print(temp);
  Serial.println(" C");
}

void push_boton(){
  int estado = digitalRead(boton);
 
  if(estado == HIGH){
    Serial.println("El boton esta");
    Serial.println("Boton Presionado");
  }

  if(estado == LOW){
    Serial.println("El boton esta");
    Serial.println("Boton No Presionado");
  }
}
