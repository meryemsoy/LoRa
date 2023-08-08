#include <LoRa.h>
#include <SPI.h>

#define SS    5
#define RESET 14
#define DIO0  2

int counter = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(5000);
  Serial.println("LoRa Sender");
  LoRa.setPins(SS,RESET,DIO0);
  if(!LoRa.begin(868E6)){
    Serial.println("Starting LoRa Failed");
    while(1);
  }
  else{
    Serial.println("Starting LoRa Succesfull");
  }

}

void loop() {
  Serial.print("Sender packet: ");
  Serial.println(counter);
  LoRa.beginPacket();
  LoRa.print("Hello");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++ ;
  
  delay(10000);
}