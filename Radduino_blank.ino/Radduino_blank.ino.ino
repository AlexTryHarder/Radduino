#include "Keyboard.h"
int buttonState = 0;  
int onetime = 0;
void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}void input()
{
////INPUT HERE////
delay(500);
typeKey(KEY_LEFT_GUI);
Keyboard.releaseAll();




Serial.print('N');

//////////////////
 Keyboard.end();
 ledRx( false);
 onetime = 0;
}

void ledRx( boolean on)
{
  if( on)
  {pinMode( LED_BUILTIN_RX, OUTPUT);
    digitalWrite( LED_BUILTIN_RX, LOW);
  }else
  {
    pinMode( LED_BUILTIN_RX, INPUT);   
  }}

void setup() {
  onetime = 0;
  ledRx( false);
  Keyboard.begin();
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}
void loop() {
  buttonState = digitalRead(2);
   if (buttonState == HIGH) {
    if (onetime == 0){onetime = 1;input();ledRx( true);}
     }
}
