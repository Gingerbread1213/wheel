#include <Arduino.h>
#include <TM1637Display.h>

#define CLK D6
#define DIO D7

TM1637Display display(CLK, DIO);

int num = 0; // 在函数外部定义变量
bool prevD2State = HIGH;

void setup() {
  display.setBrightness(0x0f);
  pinMode(D3, INPUT);
  pinMode(D1, INPUT);
  display.showNumberDec(0);
  num = 0; // 初始化全局变量
}

void loop() {
  bool currentD2State = digitalRead(D3);

  if(currentD2State == LOW && prevD2State == HIGH) {
    num++;
    display.showNumberDec(num);
  }

  prevD2State = currentD2State;
<<<<<<< HEAD:1.0/sketch_may16a.ino
}
=======
}
>>>>>>> refs/remotes/origin/main:sketch_apr8a/sketch_apr8a.ino
