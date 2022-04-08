
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;
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


#define RED_LED 10 // Red led is connected on PMW pin 10
#define BLUE_LED 11 // Blue led is connected on PMW pin 11
#define GREEN_LED 9 // Green led is connected on PMW pin 9

int red_switch = 0;
int Switch = 0;
int blue_switch = 0;
int green_switch = 0;
int timer = 0;
int Timer = 0;
int Rbrightness = 0;
int Bbrightness = 0;
int Gbrightness = 0;
int last_state = 0;
void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
  
  // TODO you setup code
  
}
void Auto()
{
  int RBright = 0;
  int BBright = 0;
  int GBright = 0;
  int rbrightness = 255;
  int bbrightness = 255;
  int gbrightness = 255;
  analogWrite(BLUE_LED,0);
  analogWrite(GREEN_LED,0);
  analogWrite(RED_LED,0);
//    delay(100);
    for(int i = 0;i<256;i++)
    {
      analogWrite(RED_LED,RBright);
      RBright +=1;
      delay(Timer);
      }
//     delay(Timer+10);
    
    for(int  i =0;i<256;i++)
    {
      analogWrite(RED_LED,rbrightness);
      analogWrite(BLUE_LED,BBright);
      rbrightness -=1;
      BBright +=1;
      delay(Timer);
      }
      delay(Timer+10);
    
    for(int i =0;i<256;i++)
    {
      analogWrite(BLUE_LED,bbrightness);
      bbrightness-=1;
      delay(Timer);
      }
//      delay(Timer+10);
    
   for(int i = 0; i<256;i++)
   {
    analogWrite(GREEN_LED,GBright);
    GBright+=1;
    delay(Timer);
    }
//    delay(Timer+10);
 
   for(int i = 0;i<256;i++)
   {
    analogWrite(GREEN_LED,gbrightness);
    analogWrite(RED_LED,RBright);
    gbrightness-=1;
    RBright +=1;
    delay(Timer);
    }
//    delay(Timer+10);
  
  for(int i = 0;i<256;i++)
  {
    analogWrite(RED_LED,rbrightness);
    rbrightness-=1;
    delay(Timer);
    }
//    delay(Timer+10);
  
  for (int i = 0;i<256;i++)
  {
    analogWrite(BLUE_LED,BBright);
    BBright +=1;
    delay(Timer);
    }
//    delay(Timer+10);
 
  for(int i = 0;i<256;i++)
  {
    analogWrite(BLUE_LED,bbrightness);
    analogWrite(GREEN_LED,GBright);
    bbrightness-=1;
    GBright+=1;
    delay(Timer);
    }
//    delay(Timer+10);
  
  for(int i = 0;i<256;i++)
  {
    analogWrite(BLUE_LED,BBright);
    BBright+=1;
    delay(Timer);
    }
//    delay(Timer+10);
  
  for (int i = 0;i<256;i++)
  {
    analogWrite(RED_LED,RBright);
    RBright +=1;
    delay(Timer);
    }
//    delay(Timer+10);
 
 for(int i= 0;i<256;i++)
 {
  analogWrite(RED_LED,rbrightness);
  analogWrite(BLUE_LED,bbrightness);
  analogWrite(GREEN_LED,gbrightness);
  rbrightness-=1;
  bbrightness-=1;
  gbrightness-=1;
  delay(Timer);
  }
//  delay(Timer+10);
  
  
  }

void loop() 
{ 
  
  RemoteXY_Handler ();
  red_switch = RemoteXY.RED;
  blue_switch = RemoteXY.BLUE;
  green_switch = RemoteXY.GREEN;
  Switch = RemoteXY.SWITCH;
  timer = RemoteXY.TIMER;
  Timer = map(timer,0,100,1,10);  
  if(Switch == 0){
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
  if(Switch == 1){
    Auto();}
    
        
}
  
   
  //analogWrite(RED_LED,0);
  
  
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
