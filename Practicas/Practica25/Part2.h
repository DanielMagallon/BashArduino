#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
    
    #define pinLamp 13
    int v;
    
    void initProg()
    {
        pinMode(pinLamp,OUTPUT);

    }
    
    void runner()
    {
          v = analogRead(LDRPin);  
    
          Serial.println(String(v)+" luz");
          
          digitalWrite(pinLamp, v!=0);

          delay(700);  
    }

#endif //_HEADER_FILE_H_
