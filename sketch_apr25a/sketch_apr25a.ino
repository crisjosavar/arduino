int tiempo = 1000;               // Variable tiempo 150 milisegundos
int pin;                        // variable pin

void setup()

{
  for(pin = 0; pin <= 4; pin++)    // aqui agregamos el ciclo for, pines a utilizar 0,1,2,3,4
{
    pinMode(pin, OUTPUT);          // pines del arduino 0,1,2,3,4 se configuran como salida
  }
}

void loop()                       // Empesamos con el secuencial con leds

{
  for(pin = 0; pin <= 4; pin++)   // los leds se encenderan y apagaran de a uno en forma creciente
{
      digitalWrite(pin, HIGH);    // los leds se encienden         
      delay(tiempo);
      digitalWrite(pin, LOW);     // los leds se apagan
      delay(tiempo);
 }

   for(pin = 4; pin >= 0; pin--)    // los leds se encenderan y apagaran de a uno en forma decreciente
{
      digitalWrite(pin, HIGH);      // los leds se encienden   
      delay(tiempo);
      digitalWrite(pin, LOW);       // los leds se apagan
      delay(tiempo);
 }

}
