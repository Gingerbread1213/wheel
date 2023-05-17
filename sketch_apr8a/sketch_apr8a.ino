#include <Arduino.h>
#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

#define CLK D6
#define DIO D7

TM1637Display display(CLK, DIO);

int num = 0; // 在函数外部定义变量
bool prevD2State = HIGH;

char auth[] = "TPUtyUA-SISzRN1tqd_8mQETYF4_G2fb";
char ssid[] = "NETGEAR48";
char pass[] = "gentleskates819";

const char DEVICE_LOGIN_NAME[]  = "08d62018-4d0b-4083-86f9-efd491513fdb";
const char SSID[]               = "NETGEAR48";   // Network SSID (name)
const char PASS[]               = "gentleskates819";   // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = "E7A4E0UMAFWSOXIVAT7W";    // Secret device password

void onRoundChange();

int roundNum = 0;
float distance;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(roundNum, READWRITE, ON_CHANGE, onRoundChange);
  ArduinoCloud.addProperty(distance, READWRITE, ON_CHANGE, onDistanceChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);


void setup() {
  display.setBrightness(0x0f);
  pinMode(D3, INPUT);
  pinMode(D1, INPUT);
  display.showNumberDec(0);
  num = 0; // 初始化全局变量

  // wifi setup
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

void loop() {

  ArduinoCloud.update();
  
  bool currentD2State = digitalRead(D3);

  if(currentD2State == LOW && prevD2State == HIGH) {
    num++;
    display.showNumberDec(num);
    roundNum = num;
    distance = num*3.14159*16/100;
  }

  prevD2State = currentD2State;



}

void onRoundChange()  {
  
 

}

void onDistanceChange()  {
  // Add your code here to act upon Distance change
}

// 08d62018-4d0b-4083-86f9-efd491513fdb
// E7A4E0UMAFWSOXIVAT7W











