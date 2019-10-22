/*
  Digispark buttons test
  
*/

#define LED_PIN 1
#define BUTTON_START 0
#define BUTTON_ESC 2

#define DELAY 1000
//-------------------------------------------------------------------
// Программа начальной установки
//-------------------------------------------------------------------
void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_ESC, INPUT_PULLUP);
  
  digitalWrite(LED_PIN, HIGH);   
}

//-------------------------------------------------------------------
// Главный цикл программы
//-------------------------------------------------------------------
void loop() 
{
  bool x = digitalRead(BUTTON_START);  
  bool y = digitalRead(BUTTON_ESC);  
  digitalWrite(LED_PIN, y);   
}
