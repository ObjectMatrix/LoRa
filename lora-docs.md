## LoRa: Symbol Generation. 
LoRa is a chirp spread spectrum (CSS) modulation based wireless networking standard
Chirp stands for **Compressed High Intensity Radar Pulse.** It is a signal which frequency either increase or decrease with time. It is very common is sonar and radar. It is also used in spread spectrum.  

+ CSS techniques helps to transmit signals for very large distances.   
+ Bandwidth, time product is always greater than one (B*T > 1).  
+ CSS is resistive to Doppler shift. 
+ It is used for low power and low data rates.

## LoRa Chirp Spread Spectrum Modulation. 

LoRa PHY (Physical Layer) includes 8 preamble symbols, 2 synchronisation symbols, physical payload and optional CRC.

![Tux, the Linux mascot](/img/chirp-spread-spectr.png)

 + SF8 takes exact twice the time of SF7 and SF9 takes exact twice time of SF8.  
 + Symbol Rate(Rs), Bandwidth(BW) and Spreading Factor(SF) relation:  
    Rs = BW / (2<sup>SF</sup>)  
 + Higher the Spreading Factor -> Higher the over-the-air time.
 + Lower the Spreading Factor ->  Higher the Data Rate. 
