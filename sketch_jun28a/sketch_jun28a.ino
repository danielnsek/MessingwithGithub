//DEBUG PROGRAM
#include <DHT.h>
#include <DHT_U.h>
#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <Timer.h>
int pin = 7;
Timer t;
void setup(){
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
  t.oscillate(pin,1000,LOW);
  t.oscillate(pin,1000,HIGH);
  Serial.println(sizeof(unsigned long[2])); //4 bytes per place, if used in EEPROM must be grabbed at the same amount
  Serial.println(sizeof(long));//4
  Serial.println(sizeof(int));//2
  Serial.println(sizeof(double));//4
  Serial.println(sizeof(float));//4
  Serial.println(sizeof(uint16_t));//2
  Serial.println(sizeof(char));//1
  Serial.println(sizeof(String));//6
  Serial.println(sizeof(int[3])); //2 bytes per place, if used in EEPROM must be grabbed at the same amount
  Serial.println(sizeof(boolean));
  String appEui = "70B3D57ED000BBA3";
  String appKey = "42A5E2906491C846F1B112F59FCE98F4";
  Serial.println(sizeof(appEui));//6
  Serial.println(sizeof(appKey));//6
  Serial.println(sizeof(analogRead(0)));
  EEPROM.put(20,appEui);
  EEPROM.put(26,appKey);
  String s="";
  String d="";
  Serial.println(EEPROM.get(20,s));
  Serial.println(EEPROM.get(26,d));
  Serial.println(s);
  Serial.println(d);


}

void loop() {
//Serial.println(random());
//Serial.println(micros());
t.every(5000,memes);
t.update();


}
void memes(){
  Serial.println("5 seconds have passed");
}

