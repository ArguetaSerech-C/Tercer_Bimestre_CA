/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en electronica
  Quinto perito
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: Carlos Argueta Serech
  Carne: 2022335
  Proyecto: Multimetro
*/



// Declaración de variables 
char opcion;          // Variable para almacenar la opción seleccionada
String msg;

// Definición de pines
#define DV_PIN A0               // Pin para medir la resistencia
#define VOLTAGE_SENSOR_PIN A1   // Pin para medir el voltaje

unsigned int raw_sensor = 0;    // Variable para almacenar la lectura analógica del sensor
int texto();                     // Declaración de funciones
int medicionResistencia();
int Divisor;
int medicionCorriente();
bool MT = true;
float sensibilidad = 0.185;
float Vt = 0;
float voltaje_sensado = 0;
float vcc = 5;
float R1 = 0;
float R2 = 10000;

void setup() {
  Serial.begin(9600);            // Inicialización de comunicación serial a 9600 baudios
  pinMode(VOLTAGE_SENSOR_PIN, INPUT);  // Configuración del pin como entrada
}

void loop() {
  if (Serial.available()) {
    opcion = Serial.read();       // Leer la opción seleccionada desde el puerto serial
  }

  switch (opcion) {               // Evaluar la opción seleccionada
    case 'A':
      if (MT) {
        Serial.println("menu de opciones");
        Serial.println("Para medir resistencia pon R");
        Serial.println("para medir otra cosa solo pon r");
        Serial.println("para medir voltaje pon V");
        Serial.println("para medir otra cosa solo pon v");
        Serial.println("para medir corriente por C");
        Serial.println("para medir otra cosa solo pon c");
        texto();
        MT = false;
      }
      break;

    case 'V':
      medicionVoltaje();
      break;

    case 'R':
      medicionResistencia();
      break;

    case 'C':
      float Idc = calculoCorriente(100);
      Serial.print("corriente: ");
      Serial.println(Idc, 3);
      delay(100);
      break;
  }
}

int medicionResistencia() {
  Divisor = analogRead(DV_PIN);   // Leer el valor analógico del pin DV_PIN
  if (Divisor) {
    Vt = analogRead(DV_PIN);       // Leer el valor analógico nuevamente
    Vt = Vt * 5 / 1023;            // Convertir el valor a voltaje
    R1 = (R2 * 5 / Vt) - (R2);     // Calcular la resistencia
    Serial.println(R1);            // Imprimir el valor de la resistencia
    delay(2000);                   // Esperar 2 segundos
  } else {
    Serial.println("no hay resistencia"); // Imprimir mensaje si no se detecta resistencia
    delay(500);
    return 0;
  }
}

int texto() {
  Serial.println("que desea medir?");  // Imprimir mensaje de solicitud de medición
}

void medicionVoltaje() {
  raw_sensor = analogRead(VOLTAGE_SENSOR_PIN);  // Leer el valor analógico del pin VOLTAGE_SENSOR_PIN
  voltaje_sensado = fmap(raw_sensor, 0, 1023, 0.0, 25.0); // Convertir la lectura a voltaje lineal
  Serial.print("El voltaje medido es de: ");
  Serial.println(voltaje_sensado); // Imprimir el voltaje medido
  delay(1000); // Esperar 1 segundo
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float calculoCorriente(int numeroMuestras) {
  float leerAcs712 = 0;
  float intensidad = 0;
  for (int i = 0; i < numeroMuestras; i++) {
    leerAcs712 = analogRead(A3) * (5.02 / 1023.0); // Leer valor analógico y convertirlo a voltaje
    intensidad = intensidad + (leerAcs712 - 2.5) / sensibilidad; // Calcular la corriente
  }
  return (intensidad / numeroMuestras); // Devolver el promedio de la corriente
}
