#include <Servo.h>
/*To Do
 * Setup Function 
 * Avg
 */

Servo zservo;  // create servo object for z servo
Servo tiltservo;  // create servo object for xy servo

int zpos = 90;    // variable to store the servo position
int tiltpos = 90;
int LDR1;
int LDR2;
int LDR3;
int LDR4;

void setup() {
  zservo.attach(5);
  tiltservo.attach(6);
}

void loop() {
  LDR1 = analogRead(A1);
  LDR2 = analogRead(A2);
  LDR3 = analogRead(A3);
  LDR4 = analogRead(A4);

  int left = LDR1 - LDR2;
  int front = LDR3 - LDR4;
  int right = LDR1 - LDR3;
  int back = LDR2 - LDR4;
      
      if(abs(left)<100 && abs(right)<100){
        delay(10);
      }
        else{
          if(left>0){
            zpos--;
            zservo.write(zpos);
            delay(50);
          }

          if(left<0){
            zpos++;
            zservo.write(zpos);
            delay(50);
          }
  
         if(right>0){
            zpos++;
            zservo.write(zpos);
            delay(50);
          }

         if(right<0){
            zpos--;
            zservo.write(zpos);
            delay(50);
          }
        }
        
     if(abs(front)<100 && abs(back)<100){
       delay(10);
      }

      else{
        
        if(front>0){
            tiltpos--;
            tiltservo.write(tiltpos);
            delay(50);
          }

        if(front<0){
            tiltpos++;
            tiltservo.write(tiltpos);
            delay(50);
          }
        
        
        if(back>0){
            tiltpos++;
            tiltservo.write(tiltpos);
            delay(50);
          }

        if(back<0){
            tiltpos--;
            tiltservo.write(tiltpos);
            delay(50);
          }
      }
}
