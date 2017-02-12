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
int count=0;

int v1=11;
int v2=10;
int v3=A0;
int v4=A1;
int v5=A2;
int v6=A3;
int v7=A4;
int v8=A5;

int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;

int code=0;
int code1=0;
int code2=0;
int newcode=0;

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

Serial.begin(9600);
  pinMode(v1, INPUT);
  pinMode(v2, INPUT);
  pinMode(v3, INPUT);
  pinMode(v4, INPUT);
  pinMode(v5, INPUT);
  pinMode(v6, INPUT);
  pinMode(v7, INPUT);
  pinMode(v8, INPUT);

count=0;
}

void loop()
{
  
  c1=digitalRead(v1);
  c2=digitalRead(v2);
  c3=digitalRead(v3);
  c4=digitalRead(v4);
  c5=digitalRead(v5);
  c6=digitalRead(v6);
  c7=digitalRead(v7);
  c8=digitalRead(v8);
  
  code1=c4*8 + c3*4 + c2*2 + c1*1;
  code2=c8*8 + c7*4 + c6*2 + c5*1;
  // testing with led
  
  
    code=code2 + 10*code1;
    
    if(newcode!=code)
  {
  Serial.println(code);
//  delay(1000);
  } 
  newcode=code;
  
     pos4=shld1.read();
     pos3=shld3.read();
     pos2=elbow.read();
     pos1=palm.read();   
  if (Serial.available() > 0)
   {
   incom=Serial.read();
   Serial.println(pos2);
   }
   if(incom==111)  // for lifting the object
   {
     for(pos = pos4; pos > 10; pos -= 1)  // goes from 0 degrees to 180 degrees 
     {                                  // in steps of 1 degree 
        shld1.write(pos);              // tell servo to go to position in variable 'pos' 
        shld2.write(pos);              // tell servo to go to position in variable 'pos'     
        delay(15);                       // waits 15ms for the servo to reach the position 
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

       if(pos3 > motor_angle) // works when the currrent position of the
        {
           if(pos4>50)
           {
             if(count==0)
             {
               delay(2000);
               sang=pos4+8;
//               sang=pos4+16;
               for(pos=pos4 ; pos < sang ; pos+=1)
               {
                  shld1.write(pos);
                  shld2.write(pos);              
                  delay(25);
               }
               pos4=shld1.read();
               eang=pos2+12;
//               eang=pos2+24;
               for(pos=pos2 ; pos < eang ; pos+=1)
               {
                  elbow.write(pos);
                  delay(25);
               }
               pos2=elbow.read();
               incom=0;
               delay(2000);
             }
            if(count!=0)
            {            
             motor_angle=pos4-5;
             for(pos=pos4 ; pos > motor_angle ; pos-=1)
             {
                 shld1.write(pos);
                 shld2.write(pos);
                 delay(20);
             }
              motor_angle=pos2-10;
             for(pos=pos2 ; pos > motor_angle ; pos-=1)
             {
                 elbow.write(pos);
                 delay(20);
             }             
           incom=0;
            }
            count=count+1;
           }  
           if(angcode==1)
           {
             motor_angle=pos3+10;
           }
           if(angcode==2)
           {
             motor_angle=pos3-10;
           }
           angcode=0;
           
           for(pos=pos3 ; pos > motor_angle ; pos-=1)
           {
              shld3.write(pos);
              delay(25);
           }

        }
         motor_angle=0;
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
         motor_angle=pos4+10;
       }
       if(angcode==2)
       {
         motor_angle=pos4-10;
       }
       angcode=0;
       
        if(pos4 > motor_angle) // works when the currrent position of the
        {

           for(pos=pos4 ; pos > motor_angle ; pos-=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(15);
           }
           incom=0;
        }
   
        if(pos4 < motor_angle)
        {
           for(pos=pos4 ; pos < motor_angle ; pos+=1)
           {
              shld1.write(pos);
              shld2.write(pos);              
              delay(15);
           }
           incom=0;
        }
     }
//     if(pos2<=30 && angcode==2)
//     {
//       motor_code=0;
//     }
     if(motor_code==5)  //for elbow motor and shoulder 1 & 2 combined
     {
       pos4=shld1.read();
       if(angcode==1)
       {
         if(pos4 < 80)
         {
           eang=pos2+0;
         }
         else
         {
           eang=pos2+12;
         }
       }
       if(angcode==2)
       {
         if(pos4 < 80)
         {
           eang=pos2-0;
         }
         else
         {
           eang=pos2-12;
         }
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
