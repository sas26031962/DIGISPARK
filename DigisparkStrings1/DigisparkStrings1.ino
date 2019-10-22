/*
  Digispark sketch для эмуляции клавиатуры v1.0
  Версия 0: Чтение кнопок, если любая из них нажата, зажигается светодиод
  Библиотека эмуляции клавиатуры подключена для проверки объёма кода
*/
//-------------------------------------------------------------------
// Подключение библиотек
//-------------------------------------------------------------------
#include <DigiKeyboard.h>

//-------------------------------------------------------------------
// Константы
//-------------------------------------------------------------------
#define LED_PIN 1		//Светодиод
#define BUTTON_START 0	//Кнопка ENTER
#define BUTTON_ESC 2	//Кнопка ESC

#define DELAY 1000
#define DEBOUNCE_DWELL 100

//-------------------------------------------------------------------
// Классы и структуры
//-------------------------------------------------------------------
struct sKey{
  int Pin;                 // Вывод кнопки
  bool Current;            // Текущее состояние кнопки
  bool Previous;           // Предыдущее состояние кнопки
  bool Debounce;           // Состояние подавления дребезга
  
  bool Event;              // Событие отпускания кнопки
  
  int DebounceCounter;     //
  
  int State;               // Состояние ключа
  
  void install(int pin);   // Конструктор
  void operate();          // Реализация ключа 
};//End of struct sKey

//
// Реализации методов
//
void sKey::install(int pin)
{
  this->Pin = pin;
  pinMode(this->Pin, INPUT_PULLUP);
  this->Current = digitalRead(this->Pin);
  this->Previous = this->Current;
  this->Debounce = false; 
  this->Event = false;
  this->DebounceCounter = 0;
}

void sKey::operate()
{
  // Чтение состояния кнопки
  this->Current = digitalRead(this->Pin);
  // Обработка подавления дребезга
  if(this->Debounce)
  {
    digitalWrite(LED_PIN, true);//Включить светодиод
    
    this->DebounceCounter++;
    if(this->DebounceCounter > DEBOUNCE_DWELL)
    {
      digitalWrite(LED_PIN, false);//Выключить светодиод
      this->Debounce = false;
      if(this->Current && this->Previous && this->Current)
        this->Event = true;
    }
  }
  else
  {
    // Фиксация момента изменения состояния кнопки
    if(this->Current != this->Previous)
    {
      this->Previous = this->Current;
      this->Debounce = true;
      this->DebounceCounter = 0;
    }
  }

}//End of void sKey::operate()

//-------------------------------------------------------------------
// Глобальные переменные
//-------------------------------------------------------------------
sKey EnterKey;
sKey EscKey;

//-------------------------------------------------------------------
// Программа начальной установки
//-------------------------------------------------------------------
void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  EnterKey.install(BUTTON_START);
  EscKey.install(BUTTON_ESC);
  
  //pinMode(BUTTON_START, INPUT_PULLUP);
  //pinMode(BUTTON_ESC, INPUT_PULLUP);
  
  digitalWrite(LED_PIN, HIGH);   
}

//-------------------------------------------------------------------
// Главный цикл программы
//-------------------------------------------------------------------
void loop() 
{
  EnterKey.operate();
  EscKey.operate();
  //bool x = digitalRead(BUTTON_START);  
  //bool y = digitalRead(BUTTON_ESC);  
  //bool z = !(x & y);
  //digitalWrite(LED_PIN, z);   
}
