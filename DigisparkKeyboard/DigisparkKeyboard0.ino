// --------------------------------------
// Digispark keyboard emulator
// --------------------------------------


#include <DigiKeyboard.h>
#define LED_PIN 1

int i = 0;
bool IsLed = true;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, IsLed);   

  DigiKeyboard.delay(3000);

  DigiKeyboard.println("\nDigisparkKeyboard");
}


void loop()
{
  i++; 
  IsLed = !IsLed;
  DigiKeyboard.print("Line ");
  DigiKeyboard.println(i);
  
  digitalWrite(LED_PIN, IsLed);   

  DigiKeyboard.delay(3000);           // wait 5 seconds for next scan
}


