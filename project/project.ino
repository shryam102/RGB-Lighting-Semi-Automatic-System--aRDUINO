/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 59 bytes
  { 255,5,0,0,0,52,0,16,121,1,4,0,10,34,7,18,12,26,4,0,
  29,34,7,18,1,26,4,0,47,34,7,18,6,26,4,0,28,80,7,18,
  243,26,2,0,21,63,22,11,2,26,31,31,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t GREEN; // =0..100 slider position 
  int8_t RED; // =0..100 slider position 
  int8_t BLUE; // =0..100 slider position 
  int8_t TIMER; // =0..100 slider position 
  uint8_t SWITCH; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


#define RED_LED 10
#define BLUE_LED 11
#define GREEN_LED 9

int red_switch = 0;
int Switch = 0;
int blue_switch = 0;
int green_switch = 0;
int timer = 0;
int Rbrightness = 0;
int Bbrightness = 0;
int Gbrightness = 0;
void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
  
  // TODO you setup code
  
}
void TurnON_RED(int r,int timer) {
   for (int i = 0; i < r; i++) { 
       analogWrite(RED_LED, Rbrightness);
       Rbrightness += 1;
       delay(timer);
   }
}
void TurnON_BLUE(int b,int timer){
   for (int i = 0; i < b; i++) { 
       analogWrite(BLUE_LED, Bbrightness);
       Bbrightness += 1;
       delay(timer);
   }
}
void TurnON_GREEN(int g,int timer){   
   for (int i = 0; i < g; i++) { 
       analogWrite(GREEN_LED, Gbrightness);
       Gbrightness += 1;
       delay(timer);
   }   
}
void TurnOFF_RED(int r) {
   for (int i = 0; i < r; i++) { 
       analogWrite(RED_LED, r);
       r-= 1;
   }
}
void TurnOFF_BLUE(int b){
   for (int i = 0; i < b; i++) { 
       analogWrite(BLUE_LED, b);
       b-= 1;
   }
}
void TurnOFF_GREEN(int g){   
   for (int i = 0; i < g; i++) { 
       analogWrite(GREEN_LED,g);
       g-= 1;
   }   
}

void loop() 
{ 
  RemoteXY_Handler ();
  red_switch = RemoteXY.RED;
  blue_switch = RemoteXY.BLUE;
  green_switch = RemoteXY.GREEN;
  Switch = RemoteXY.SWITCH;
  timer = RemoteXY.TIMER;
  if (Switch == 0){
     int rBright = 0;
     int bBright = 0;
     int gBright = 0;
     rBright = map(red_switch,0,100,0,255);
     bBright = map(blue_switch,0,100,0,255);
     gBright = map(green_switch,0,100,0,255);
     analogWrite(BLUE_LED,bBright);
     analogWrite(GREEN_LED,gBright);
     analogWrite(RED_LED,rBright);
    }
 
  
}
  
   
  //analogWrite(RED_LED,0);
  
  
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
