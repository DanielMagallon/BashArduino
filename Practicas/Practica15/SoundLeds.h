#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_

    int pinNivelAlto[2] = {2,3};
    int pinNivelMedio[3] = {4,5,6};
    int pinNivelBajo[5] = {7,8,9,10,12};
    
    void nivel_alto(bool turnOn);
    void nivel_bajo(bool turnOn);
    void nivel_medio(bool turnOn);

    void nivel_alto(bool turnOn)
    {
        for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelAlto[i],turnOn);
        }
        
        if(turnOn)
        {
            nivel_medio(!turnOn);
            nivel_bajo(!turnOn);
        }        
    }
    
    void nivel_medio(bool turnOn)
    {
        for(int i=0; i<3; i++)
        {   
            digitalWrite(pinNivelMedio[i],turnOn);
        }
        
         if(turnOn)
        {
            nivel_alto(!turnOn);
            nivel_bajo(!turnOn);
        }  
    }
    
    void nivel_bajo(bool turnOn)
    {
        for(int i=0; i<5; i++)
        {   
            digitalWrite(pinNivelBajo[i],turnOn);
        }
        
        if(turnOn)
        {
            nivel_medio(!turnOn);
            nivel_alto(!turnOn);
        }  
    }
    
    void apagarTodo(){
    for(int i=0; i<5; i++)
        {   
            digitalWrite(pinNivelBajo[i],0);
        }
        
         for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelAlto[i],0);
        }
        
        for(int i=0; i<3; i++)
        {   
            digitalWrite(pinNivelMedio[i],0);
        }
        
    }
    
#endif //_HEADER_FILE_H_
