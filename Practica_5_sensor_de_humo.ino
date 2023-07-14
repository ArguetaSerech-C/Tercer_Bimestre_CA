#include <Ticker.h>
#include <LedControl.h>


int adc, cover;

int valor;

volatile static bool estado_mq2;
void isr_mq2(void);

Ticker isr_accion_detecteccionMQ2(isr_mq2, 2000);

LedControl matriz_ca = LedControl(11, 13, 10, 1);


void setup()
{
  Serial.begin(9600);
  matriz_ca.shutdown(0, false);
  matriz_ca.setIntensity(0, 4);
  matriz_ca.clearDisplay(0);

  isr_accion_detecteccionMQ2.start();
}
void loop()


{
  isr_accion_detecteccionMQ2.update();
}


void funcion_copoDnieve()

{
  byte copo[8] =
  {
    B00000000,
    B00011000,
    B01011010,
    B00111100,
    B11100111,
    B00111100,
    B01011010,
    B00011000,
  };



  for (int i = 0; i < 8; i++)
  {
    matriz_ca.setRow(0, i, copo[i]);
  }
}






void funcionDllama()
{

  byte fuego[8] =
  {
    B00100000,
    B00110000,
    B00101000,
    B01000110,
    B01000011,
    B10000001,
    B11000001,
    B00111110,
  };

  for (int i = 0; i < 8; i++)
  {
    matriz_ca.setRow(0, i, fuego[i]);
  }
}
void isr_mq2(void)
{
  adc = analogRead(A1);
  cover = map(adc, 0, 1024, 0, 100);
  Serial.print("adc:");
  Serial.print(adc);
  Serial.println("   porcentaje:");
  Serial.println(cover);
  Serial.println(adc);



  if (adc > 400)
  {
    if (valor == 0)
    {
      parpadear();
    }
    if (valor == 1)
    {
      funcionDllama();
    }
  }

  else {
    funcion_copoDnieve();
    valor = 0;
  }
}

void parpadear()
{
  funcionDllama();
  delay(1000);
  matriz_ca.clearDisplay(0);
  delay(1000);
  funcionDllama();
  delay(1000);
  matriz_ca.clearDisplay(0);
  delay(1000);
  funcionDllama();
  delay(1000);
  valor = 1;
}     
