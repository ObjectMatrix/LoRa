
#include "heltec.h"
#include "images.h"

#define BAND    915E6  

unsigned int counter = 0;
String rssi = "RSSI --";
String packSize = "--";
String packet ;
/**
 * sending a Haiku for receiver
 * https://en.wikipedia.org/wiki/Haiku
 */
char *haiku[] = {
  "-[Haiku]-",
  "old pond",
  "frog leaps in",
  "water's sound",
  "the first ",
  "cold shower",
  "even the monkey",
  "seems to want",
  "the little",
  "coat of straw",
  "-[End]-"
};
// unsigned int haikusize = sizeof(haiku);
void setup()
{
   //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
 
  Heltec.display->init();
  Heltec.display->flipScreenVertically();  
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "ObjectMatrix success!");
  Heltec.display->display();
  delay(1000);
}

void loop()
{
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  
  Heltec.display->drawString(10, 0, "old pond");
  Heltec.display->drawString(10, 10, "frog leaps in");
  Heltec.display->drawString(10, 20, "water's sound");
  Heltec.display->drawString(10, 35, "counter:");
  Heltec.display->drawString(60, 35, String(counter));
  Heltec.display->display();

  // send packet
  LoRa.beginPacket();
  
/*
 * LoRa.setTxPower(txPower,RFOUT_pin);
 * txPower -- 0 ~ 20
 * RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
 *   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
 *   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
 */
  LoRa.setTxPower(20,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(haiku[counter/11]);
  //  LoRa.print("Counter:");
  //  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
    delay(10);                       // wait for a second
}
