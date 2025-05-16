#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 15
#define CSN_PIN 2

const byte slaveAddr[5] = {'I','N','D','R','A'};

RF24 radio(CE_PIN,CSN_PIN);

struct dt {
  int j1;
  int j2;
  int j3;
  int j4;
  bool b1;
  bool b2;
};

//pin configuration -------------

#define joy1 13
#define joy2 12
#define joy3 14
#define joy4 27

#define dig1 26
#define dig2 25

dt data_sent;


unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1; 

void setup(){
//  Serial.begin(9600);
//  Serial.print("tx started");

  radio.begin();
  SPI.setFrequency(4000000);
  radio.setDataRate( RF24_250KBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setRetries(3,5);
  radio.openWritingPipe(slaveAddr);
  
  pinMode(joy1,INPUT);
  pinMode(joy2,INPUT);
  pinMode(joy3,INPUT);
  pinMode(joy4,INPUT);  

  pinMode(dig1,INPUT_PULLUP);
  pinMode(dig2,INPUT_PULLUP);
  
}
void loop(){
  data_sent.j1 = map(analogRead(joy1),0,4095,0,180);
  data_sent.j2 = map(analogRead(joy2),0,4095,0,180);
  data_sent.j3 = map(analogRead(joy3),0,4095,0,180);
  data_sent.j4 = map(analogRead(joy4),0,4095,0,180);

  data_sent.b1 = digitalRead(dig1);
  data_sent.b2 = digitalRead(dig2);
  
  bool r;
  r = radio.write(&data_sent, sizeof(dt));
  delayMicroseconds(100);
//
//  Serial.print(data_sent.j1);
//  Serial.print(" ");
//  Serial.print(data_sent.j2);
//  Serial.print(" ");
//  Serial.print(data_sent.j3);
//  Serial.print(" ");
//  Serial.print(data_sent.j4);
//  Serial.print(" ");
//  Serial.print(data_sent.b1);
//  Serial.print(" ");
//  Serial.print(data_sent.b2);

//  if (r){
//    Serial.println(" Ack received");
//  }
//  else{
//    Serial.println(" Tx Failed");
//  }
}
