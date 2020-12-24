
#include "heltec.h" 
#include "images.h"

// US ISM Band
#define BAND 915E6  
String rssi = "RSSI --";
String packSize = "--";
String packet ;

void logo(){
  Heltec.display->clear();
}

void LoRaData(){
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_16); // othet font sizes: 10, 16, 24
  // Heltec.display->drawString(0 , 15 , "Received "+ packSize + " bytes");
  Heltec.display->drawStringMaxWidth(0 , 26 , 128, packet);
  /**
   * RSSI stands for Received Signal Strength Indicator. 
   * It is an estimated measure of power level that an RF client 
   * device is receiving from an access point or router. 
   * At larger distances, the signal gets weaker and the wireless data 
   * rates get slower, leading to a lower overall data throughput.
   */
  // Heltec.display->drawString(0, 0, rssi);  
  Heltec.display->display();
}

void cbk(int packetSize) {
  packet = "";
  packSize = String(packetSize,DEC);
  for (int i = 0; i < packetSize; i++) { packet += (char) LoRa.read(); }
  rssi = "RSSI " + String(LoRa.packetRssi(), DEC) ;
  LoRaData();
}

void setup() { 
  Heltec.begin(true /*DisplayEnable Enable*/,
  true /*Heltec.Heltec.Heltec.LoRa Disable*/,
  true /*Serial Enable*/,
  true /*PABOOST Enable*/,
  BAND /*long BAND*/);
 
  Heltec.display->init();
  Heltec.display->flipScreenVertically();  
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->clear();
  
  Heltec.display->drawString(0, 0, "ObjectMatrix success!");
  Heltec.display->drawString(0, 10, "Wait for incoming data...");
  Heltec.display->display();
  LoRa.receive();
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) { cbk(packetSize);  }
  delay(10);
}
