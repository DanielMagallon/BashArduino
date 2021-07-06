const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

const int N = 7;
const int SEGMENTOS[N] = {A,B,C,D,E,F,G};

const int anodoComunOn=0,anodoComunOff=1;

const int MAX_SEG=10;
const int DIGITOS[MAX_SEG][N] = {
/*0*/ {anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOn},
/*1*/ {anodoComunOn,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOn,anodoComunOn,anodoComunOn},
/*2*/ {anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOff},
/*3*/ {anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOn,anodoComunOff},
/*4*/ {anodoComunOn,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOn,anodoComunOff,anodoComunOff},
/*5*/ {anodoComunOff,anodoComunOn,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOff,anodoComunOff},
/*6*/ {anodoComunOff,anodoComunOn,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff},
/*7*/ {anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOn,anodoComunOn,anodoComunOn},
/*8*/ {anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff},
/*9*/ {anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOff,anodoComunOn,anodoComunOff,anodoComunOff},
};

const int OFF = anodoComunOn==1 ? HIGH : LOW;


void printNumber(int d){
  for (int i=0; i<N; i++){
    digitalWrite(SEGMENTOS[i], DIGITOS[d][i]);
  }
}

void init7display()
{
  for (int i=0; i<N; i++){
    pinMode(SEGMENTOS[i], OUTPUT);
    digitalWrite(SEGMENTOS[i], OFF);//apagar
  }
  
  printNumber(0);
}


