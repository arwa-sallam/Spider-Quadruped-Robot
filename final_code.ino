#include <WiFi.h>

const char *ssid = "ESP32";
const char *password = "12345678";

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pulseWidth = Adafruit_PWMServoDriver();

#define servoMIN 150
#define servoMAX 600

void setup() {
  WiFi.softAP(ssid, password);
  pulseWidth.begin();
  pulseWidth.setPWMFreq(60);
  start_star();
}

void loop() {
//  start_star();
//  spinning();
//  forward();
//  backward();
//  left();
//  right();
//  stand_up();
  
  shut_down();
    
}

double localization()
{
  double distance=0;
  int numNetworks = WiFi.scanNetworks();
  Serial.println("--------------------------------------------------");
  for (int i = 0; i < numNetworks; i++)
  {
    Serial.println(WiFi.SSID(i) + " | RSSI: " + String(WiFi.RSSI(i)));
    if(String(WiFi.SSID(i))=="quader")
    {
      Serial.println("RSSI: " + String(WiFi.RSSI(i)));
      double s = (-59 - WiFi.RSSI(i)) / (10.0 * 3);
      distance = pow(10.0, s);
      Serial.println("Whole Term: " + String(s));
      Serial.println("distance distance: " + String(distance));
    }
  }
  return distance ;
}

void setAngle(int servoNum,int ang){
    int pulse = map(ang ,0,180,servoMIN,servoMAX);
    pulseWidth.setPWM(servoNum, 0, pulse);
}

void start_star(){
  setAngle(0,90);
  setAngle(1,90);
  setAngle(2,90);
  setAngle(3,90);
  delay(1000);
  setAngle(8,0);
  setAngle(9,0);
  setAngle(10,0);
  setAngle(11,0);
  delay(1000);
}

void spinning(){
//  this fn should be called before the spinning fn
//  start_star();
  
    setAngle(0,40+90);
    setAngle(8,30);
    setAngle(2,40+90);
    setAngle(10,30);
    delay(500);
  

    setAngle(8,0);
    setAngle(10,0);
    delay(1000);

    setAngle(3,20+90);
    setAngle(11,30);
    setAngle(1,40+90);
    setAngle(9,30);
    delay(500);
 

    setAngle(11,0);
    setAngle(9,0);
    delay(1000);
  
  
    setAngle(0,90);
    setAngle(1,90);
    setAngle(2,90);
    setAngle(3,90);
    delay(1000);
  }

void forward(){
//  this fn should be called before the forward fn
//  start_star();
  setAngle(9,40);
  delay(500);
  setAngle(1,90+30);
  delay(500);
  setAngle(9,0);
  delay(500);

  setAngle(8,20);
  setAngle(10,20);
  delay(500);
  
  setAngle(11,40);
  delay(500);
  setAngle(3,90-40);
  delay(500);
  setAngle(11,0);
  delay(500);

  setAngle(1,90);
  setAngle(3,90);
  delay(500);
  }

void backward(){
//  this fn should be called before the forward fn
//  start_star();
  setAngle(9,40);
  delay(500);
  setAngle(1,90-30);
  delay(500);
  setAngle(9,0);
  delay(500);

  setAngle(8,20);
  setAngle(10,20);
  delay(500);
  
  setAngle(11,40);
  delay(500);
  setAngle(3,90+40);
  delay(500);
  setAngle(11,0);
  delay(500);

  setAngle(1,90);
  setAngle(3,90);
  delay(500);
  }

void left(){
  setAngle(8,40);
  delay(500);
  setAngle(0,90-40);
  delay(500);
  setAngle(8,0);
  delay(500);

  setAngle(10,40);
  delay(500);
  setAngle(2,90+40);
  delay(500);
  setAngle(10,0);
  delay(500);

  setAngle(0,90);
  setAngle(2,90);
  delay(500);
  }

void right(){
  setAngle(8,40);
  delay(500);
  setAngle(0,90+40);
  delay(500);
  setAngle(8,0);
  delay(500);

  setAngle(11,20);
  setAngle(9,20);
  delay(500);
  
  setAngle(10,40);
  delay(500);
  setAngle(2,90-40);
  delay(500);
  setAngle(10,0);
  delay(500);

  setAngle(0,90);
  setAngle(2,90);
  delay(500);
  }

void stand_up(){
  setAngle(8,0);
  setAngle(9,0);
  setAngle(10,0);
  setAngle(11,0);
  delay(1000);
  }

void shut_down(){
  setAngle(8,90);
  setAngle(9,90);
  setAngle(10,90);
  setAngle(11,90);
  delay(1000);

  setAngle(0,145);
  delay(500);
  
  setAngle(1,35);
  delay(500);
  
  setAngle(2,145);
  delay(500);
  
  setAngle(3,55);
  delay(500);
  }
