/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: Contador 00 a 50 (INTERRUPCIONES POR HARDWARE)
*/

//botones leds definos en su pin
#define btn_rising  2
#define btn_falling 3
#define a1 4
#define b1 5
#define c1 6
#define d1 7
#define a2 8
#define b2 9
#define c2 10
#define d2 11

//almacenamiento de valores
int c_Unidades = 0;
int c_Decenas = 0;
void funcionA(void); //asignacion de las funciones
void funcionB(void);

//indentificacion de entradas y salidas
void setup() {
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(btn_rising, INPUT);  //pin 2 como entrada
  pinMode(btn_falling, INPUT); //pin 3 como entrada
  attachInterrupt(digitalPinToInterrupt(btn_rising), funcionB, RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling), funcionA, FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente

}
// Variantes de LED, para cada valor de la suma
//UNIDADES
void loop() {
  switch (c_Unidades) {
    case 0:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 1:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 2:
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 3:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(d2, LOW);
      break;
    case 4:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 5:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 6:
      digitalWrite(a2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 7:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(c2, HIGH);
      digitalWrite(d2, LOW);
      break;
    case 8:
      digitalWrite(a2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, HIGH);
      break;
    case 9:
      digitalWrite(a2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(d2, HIGH);
      break;

  }
  //DECENAS
  switch (c_Decenas) {
    case 0:
      digitalWrite(a1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(d1, LOW);
      break;
    case 1:
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(d1, LOW);
      break;
    case 2:
      digitalWrite(a1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(d1, LOW);
      break;
    case 3:
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(d1, LOW);
      break;
    case 4:
      digitalWrite(a1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      break;
    case 5:
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      break;


  }
}

void funcionB(void) {

  //condicional para x situacion del display
  if (c_Decenas == 5 && c_Unidades == 0)
  {
    c_Decenas = 0;
    c_Unidades = -1;
  }
  // Valores de la suma
  c_Unidades = c_Unidades + 1;
  if (c_Unidades == 10) {
    c_Unidades = 0;
    c_Decenas = c_Decenas + 1;
  }


}

void funcionA(void) {
  // Valores de resta, bajo condicionales
  c_Unidades = c_Unidades - 1;
  if (c_Unidades < 0) {
    c_Unidades = 9;
    c_Decenas = c_Decenas - 1;
    if (c_Decenas < 0) {
      c_Decenas = 5;
      c_Unidades = 0;
    }
    //condicional para x situacion del display
    if (c_Unidades == 1 && c_Decenas == 0)
    {
      c_Unidades = 0;
    }
  }

}
