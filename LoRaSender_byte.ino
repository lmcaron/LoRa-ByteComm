
#include <SPI.h>
#include <LoRa.h>

int counter = 0;
uint8_t data;     

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(434E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

//  LoRa.setSpreadingFactor(12);
//  LoRa.setSignalBandwidth(250000);
//  LoRa.setCodingRate4(8);
//  LoRa.enableCrc();
}

void loop() {
  
  data = map(analogRead(A0),0,1023,0,255);
  Serial.print("Sending packet: ");
  Serial.println(data);

  // send packet
  LoRa.beginPacket();
  LoRa.write(data);
  LoRa.endPacket();

  counter++;

  delay(3000);
}
