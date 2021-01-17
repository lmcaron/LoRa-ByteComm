//*****Reception de donnée byte via LORA*****

#include <SPI.h>
#include <LoRa.h>

uint8_t input = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

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
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet ");

    // read packet
    while (LoRa.available()) {
      input = LoRa.read();
      Serial.print(input);
    }

   
    // print RSSI of packet
    Serial.print(" with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
