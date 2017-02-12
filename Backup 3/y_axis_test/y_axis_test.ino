#include <Servo.h>

Servo shld1;
Servo shld2;     
Servo shld3;
Servo elbow;
Servo palm;

int incom=0;
int pos=0;
int motor_code;
int motor_angle;

int pos1=0;
int pos2=0;
int pos3=0;
int pos4=0;
int angcode=0;
int sang=0;
int eang=0;
void setup()
{
 Serial.begin(9600);
 shld1.attach(12);
 shld2.attach(9); 
 shld3.attach(8); 
 elbow.attach(7); 
 palm.attach(4);  
 
 shld1.write(120);
 shld2.write(120);
 shld3.write(90);
 elbow.write(150);

//  for(pos = 120; pos < 160; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(25);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(1000);
//  
//  for(pos = 120; pos > 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    shld1.write(pos);              // tell servo to go to position in variable 'pos' 
//    shld2.write(pos);              // tell servo to go to position in variable 'pos'     
//    delay(25);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(1000);
//  
//  for(pos = 160; pos > 30; pos -= 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    elbow.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(25);                       // waits 15ms for the servo to reach the position 
//  } 
}

void loop()
{

     pos4=shld1.read();
     pos3=shld3.read();
     pos2=elbow.read();
     pos1=palm.read();   
  if (Serial.available() > 0)
   {
   incom=Serial.read();
   Serial.println(pos2);
   }
   if(incom==111)
   {
     for(pos = 10; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
     {                                  // in steps of 1 degree 
        shld1.write(pos);              // tell servo to go to position in variable 'pos' 
        shld2.write(pos);              // tell servo to go to position in variable 'pos'     
        delay(25);                       // waits 15ms for the servo to reach the position 
     } 
     incom=0;
   }     
   if(incom!=0)
   {
     motor_code=incom/10;
     angcode=incom-motor_code*10;
     
// part for opening and closing of palm     
      if(motor_code==1)
      {
        if(angcode==1)
        {
             for(pos = 20; pos < 160; pos += 1)  // goes from 0 degrees to 180 degrees 
             {                                  // in steps of 1 degree 
                 palm.write(pos);              // tell servo to go to position in variable 'pos' 
                 delay(15);                       // waits 15ms for the servo to reach the position 
             } 
        }
        if(angcode==2)
        {
             for(pos = 160; pos>=20; pos-=1)     // goes from 180 degrees to 0 degrees 
             {                                
                 palm.write(pos);              // tell servo to go to position in variable 'pos' 
                 delay(15);                       // waits 15ms for the servo to reach the position 
             } 
        }
        incom=0;
        
      }
          

     if(motor_code==2)  //for elbow motor
     {
       if(angcode==1)
       {
         motor_angle=pos2+5;
       }
       if(angcode==2)
       {
         motor_angle=pos2-5;
       }
       angcode=0;

       if(pos2 > motor_angle) // works when the currrent position of the
        {

           for(pos=pos2 ; pos > motor_angle ; pos-=1)
           {
              elbow.write(pos);
              delay(25);
           }
           incom=0;
        }
   
        if(pos2 < motor_angle)
        {
           for(pos=pos2 ; pos < motor_angle ; pos+=1)
           {
                elbow.write(pos);
                delay(25);
           }
           incom=0;
        }
     } // end of elbow part


     if(motor_code==3) // for shoulder 3 motor
     {
       if(angcode==1)
       {
         motor_angle=pos3+10;
       }
       if(angcode==2)
       {
         motor_angle=pos3-10;
       }
       angcode=0;

       if(pos3 > motor_angle) // works when the currrent position of the
        {

           for(pos=pos3 ; pos > motor_angle ; pos-=1)
           {
              shld3.write(pos);
              delay(25);
           }
           incom=0;

        }
   
        if(pos3 < motor_angle)
        {
           for(pos=pos3 ; pos < motor_angle ; pos+=1)
           {
                shld3.write(pos);
                delay(25);
           }
           incom=0;

        }
     }  // end of shld3 part
     
     if(motor_code==4)
     {
       if(angcode==1)
       {
         motor_angle=pos4+5;
       }
       if(angcode==2)
       {
         motor_angle=pos4-5;
       }
       angcode=0;
       
        if(pos4 > motor_angle) // works when the currrent position of the
        {

           for(pos=pos4 ; pos > motor_angle ; pos-=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(25);
           }
           incom=0;
        }
   
        if(pos4 < motor_angle)
        {
           for(pos=pos4 ; pos < motor_angle ; pos+=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(25);
           }
           incom=0;
        }
     }
     if(pos2<=30 && angcode==2)
     {
       motor_code=0;
     }
     if(motor_code==5)  //for elbow motor and shoulder 1 & 2 combined
     {
       if(angcode==1)
       {
         eang=pos2+12;
       }
       if(angcode==2)
       {
         eang=pos2-12;
       }
       angcode=0;

       if(pos2 > eang) // works when the currrent position of the
        {
           sang=pos4-8;
           for(pos=pos4 ; pos > sang ; pos-=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(25);
           }

           for(pos=pos2 ; pos > eang ; pos-=1)
           {
              elbow.write(pos);
              delay(25);
           }
           incom=0;
        }
//        eang=0;
        if(pos2 < eang)
        {
           sang=pos4+8;
           for(pos=pos4 ; pos < sang ; pos+=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(25);
           }
           for(pos=pos2 ; pos < eang ; pos+=1)
           {
                elbow.write(pos);
                delay(25);
           }
           incom=0;
        }
     }     
   }
}
