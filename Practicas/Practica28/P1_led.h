#include <Servo.h>

#define MAX 4
int pinesLed[MAX] = {A0,A1,A2,A3};
int index=-1;
int contador7=0;
Servo  servoMotor;

void nextLed();

void initProg()
{
    for(int i=0; i<MAX; i++)
    {
        pinMode(pinesLed[i],OUTPUT);
    }

    nextLed();
}

void nextLed()
{

   index++;

   if(index==MAX)
   {
      digitalWrite(pinesLed[MAX-1],LOW);
      digitalWrite(pinesLed[0],HIGH);
      index=0;
   }
   else
    {  
      digitalWrite(pinesLed[index],HIGH);
      digitalWrite(pinesLed[index-1],LOW);
    }

   
}

void previousLed()
{
   index--;
    
   if(index<=-1)
   {
      index=MAX-1;
      digitalWrite(pinesLed[0],LOW);
   }
   else digitalWrite(pinesLed[index+1],LOW);

  digitalWrite(pinesLed[index],HIGH);
}

boolean play=false;
void playLeds()
{
    
    for(int i=0; i<MAX; i++)
    {
        digitalWrite(pinesLed[i],HIGH);
    }

    delay(300);

    for(int i=0; i<MAX; i++)
    {
        digitalWrite(pinesLed[i],LOW);
    }

    delay(300);
}

void more()
{
    if(play)
      playLeds();
}

void turn(int led)
{
    for(int i=0; i<MAX; i++)
    {
        digitalWrite(pinesLed[i],led==i);
    }
}

void girarServo(int val)
{
    
    servoMotor.write(val);   
}


boolean turnOn=true;

void runner(decode_results results,void *func(int) )
{
    switch(results.value)
    {

      case CHPLUS:
      Serial.println("Rotando der");
      girarServo(90);
      break;


      case CHMINUM:
      Serial.println("Rotando izq");
      girarServo(0);
      break;


      case CHSTOP:
        digitalWrite(pinLampara,turnOn);
        turnOn=!turnOn;
        break;

      case PLUS:
        contador7++;
        if(contador7==10)
          contador7=0;
        Serial.println("Cont: "+String(contador7));
        func(contador7);
        break;

      case MINUM:
        contador7--;
        if(contador7==-1)
          contador7=9;
        Serial.println("Cont: "+String(contador7));
        func(contador7);
        break;
      
      case ONE:
        if(!play)
        {
          index=-1;
          turn(0);
        }
        break;  

      case TWO:
        if(!play)
        {
          index=-1;
          turn(1);
        }
        break;


      case THREE:
        if(!play)
          turn(2);
        break;

      case FOUR:
        if(!play)
          turn(3);
        break;

      case LEFT:
        if(!play)
        {
          turn(MAX);
          previousLed();
        }
        break;

        

      case PLAY_STOP:
        index=-1;
        play=!play;
        break;

      case RIGTH:
        if(!play)
        {
          turn(MAX);
          nextLed();
        }
        break;
    }

}
