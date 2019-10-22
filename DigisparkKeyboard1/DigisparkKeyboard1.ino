// --------------------------------------
// Digispark keyboard emulator
// --------------------------------------


#include <DigiKeyboard.h>
#define LED_PIN 1

int i = 0;
int BsLength = 6;
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
  DigiKeyboard.print(i);
  
  digitalWrite(LED_PIN, IsLed);   

  DigiKeyboard.delay(3000);  

  if(i > 9) BsLength = 7;
  if(i >99) BsLength = 8;
  for(int j = 0; j < BsLength; j++) DigiKeyboard.print("\b");        
}


