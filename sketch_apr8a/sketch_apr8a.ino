//傻逼
#include <Arduino.h>
#include <TM1637Display.h>

#define CLK D6
#define DIO D7

TM1637Display display(CLK, DIO);


void setup() {

  display.setBrightness(0x0f);

  pinMode(D8, INPUT);
  display.showNumberDec(0);

}

void loop() {

  int index;

  while(true){

    if(digitalRead(D8) == HIGH){
      index++;

    }

    display.showNumberDec(index);
    Serial.println(index);
  }


}