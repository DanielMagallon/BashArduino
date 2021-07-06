#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_

    int v,i;
    const int pines[] =  {2,3,4,5,6,7,8,9};
    const int rangos[] = {10,540,700,900,930};

    void initProg()
    {
          for(int i=0; i<8; i++)
          {
            pinMode(pines[i],OUTPUT);
            digitalWrite(pines[i],LOW);
          }
    }
    
    void stateLed()
    {
      i++;
      i*=2;
      i-=2;
      int j;
      
      for(j=0; j<i; j++)
      {
          digitalWrite(pines[j],HIGH);
      }
      
      for(; j<8; j++)
      {
        
        digitalWrite(pines[j],LOW);
      }
      
    }
    
    
    void runner()
    {
        v = analogRead(LDRPin);  
      Serial.println(String(v)+" luz");

      for(i=0; i<4; i++)
      {
          if(v<=rangos[i])
          {
              break;  
          }
      }

      stateLed();
      delay(700);
    }

#endif //_HEADER_FILE_H_
