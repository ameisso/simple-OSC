#include "simple-OSC/simple-OSC.h"

UDP udp;

IPAddress outIp(192, 168, 0, 14);
unsigned int outPort = 1234;

void setup()
{
    Serial.begin(115200);
    udp.begin(inPort);
    
    while (!WiFi.ready())
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
}

void loop()
{
    //SEND
    OSCMessage outMessage("/pong");
    outMessage.addString("test");
    outMessage.addFloat(-3.14);
    outMessage.addInt(-1);
    outMessage.send(udp,outIp,outPort);
}
