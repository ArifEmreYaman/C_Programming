#include <MPU6050.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <Servo.h>

MPU6050 ACC_GYR; 

Servo servo1;
Servo servo2;
Servo servo3;


int16_t  accx, accy, accz;
int16_t  gyrx, gyry, gyrz;

int deger, deger2, deger3, eskideger, eskideger2, eskideger3, x, y ,z ;

int yaw1 =  60;
int yaw2 =  100;
int roll1 = 60;
int roll2 = 120;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  ACC_GYR.initialize();
  Serial.println(ACC_GYR.testConnection() ? "BAĞLANDI" : "BAĞLANAMADI");
  
  
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  delay(100);
}

void loop() {
 
  //ACC_GYR.getMotion6(&accx, &accy, &accz,&gyrx, &gyry, &gyrz);

  ACC_GYR.getAcceleration(&accx, &accy, &accz);
  ACC_GYR.getRotation(&gyrx, &gyry, &gyrz);
  
  deger =  map (accx, -17000, 17000, 0, 180);
  deger2 = map(accy, -17000, 17000, 0, 180);
  deger3 = map(accz, -17000, 17000, 0, 180);

  
// YAW

  
  if (yaw1 < deger && deger < yaw2)   
  {    
    servo1.write(80);
    Serial.print(80);
    Serial.print("/");
  }
    else if(yaw2 <= deger) {
      y= deger - 0 ;
      servo1.write(y);
      eskideger = deger;
      Serial.print("x ekseni:");
      Serial.print(deger);
      Serial.print("/");
    }
    else if( deger <= yaw1) {
      y= deger - 0 ;
      servo1.write(y);
      eskideger = deger;
      Serial.print("x ekseni:");
      Serial.print(deger);
      Serial.print("/");
      
        
  }


// ROLL 
  if (roll1 < deger2 &&  deger2 < roll2) {    
    servo1.write(89);
    Serial.print(89);
    Serial.println("");
    
  }
    else if(roll2<= deger2) {
      x= deger2 - 25 ;
      servo1.write(x);
      eskideger2 = deger2;
      Serial.print("x ekseni:");
      Serial.print(deger2);
      Serial.println("");
    } 
    else if( deger2 <= roll1) {
      x= deger2 - 25 ;
      servo1.write(x);
      eskideger2 = deger2;
      Serial.print("x ekseni:");
      Serial.print(deger2);
      Serial.println("");
  } 

// PİTCH
  
  if (roll1 < deger3 &&  deger3 < roll2) {    
    servo1.write(89);
    Serial.print(89);
    Serial.println("");
    
  }
    else if(roll3<= deger3) {
      x= deger - 25 ;
      servo1.write(x);
      eskideger2 = deger2;
      Serial.print("x ekseni:");
      Serial.print(deger2);
      Serial.println("");
    } 
    else if( deger2 <= roll1) {
      x= deger2 - 25 ;
      servo1.write(x);
      eskideger2 = deger2;
      Serial.print("x ekseni:");
      Serial.print(deger2);
      Serial.println("");
  } 




}








  

