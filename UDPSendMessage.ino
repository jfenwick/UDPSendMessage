// This #include statement was automatically added by the Spark IDE.
#include "OSCMatch.h"

// This #include statement was automatically added by the Spark IDE.
#include "OSCData.h"

// This #include statement was automatically added by the Spark IDE.
#include "OSCMessage.h"

/*
    Make an OSC message and send it over UDP
    
    Adrian Freed
 */

//UDP Udp;

//the Arduino's IP
//IPAddress ip(128, 32, 122, 252);
//destination IP
IPAddress outIp(10, 0, 0, 23);
const unsigned int outPort = 9999;

// byte mac[] = {  
 // 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // you can find this written on the board of some Arduino Ethernets or shields
void setup() {
    Udp.begin(8888);

}


void loop(){
  //the message wants an OSC address as first argument
  OSCMessage msg("/analog/0");
  msg.add((int32_t)analogRead(0));
  
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

  delay(20);
}