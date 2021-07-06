int row[]={11,10,9,8};// Defining array-row pins of keypad connected to Arduino pins
int col[]={7,6,5,4};//Defining array-column pins of keypad connected to Arduino
int i,j; // Two counter variables to count inside for loop
int col_scan; // Variable to hold value of scanned columns
void setup()
{
Serial.begin(9600);
for(i=0;i<=3;i++)
{
pinMode(row[i],OUTPUT);
pinMode(col[i],INPUT);
digitalWrite(col[i],HIGH);
} }


void loop()
{ 
for(i=0; i<=3; i++)
{
digitalWrite(row[0],HIGH);
digitalWrite(row[1],HIGH);
digitalWrite(row[2],HIGH);
digitalWrite(row[3],HIGH);
digitalWrite(row[i],LOW);
for(j=0; j<=3; j++)
{
col_scan=digitalRead(col[j]);
if(col_scan==LOW)
{
keypress(i,j);
delay(300);
}}
}}

char keyMap[4][4] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

void keypress(int i, int j)
{
    Serial.println("Presiono la tecla: "+String(keyMap[j][i]));
}
