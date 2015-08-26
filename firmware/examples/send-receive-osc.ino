#include "simple-OSC.h"

UDP udp;

IPAddress outIp(192, 168, 0, 14);
unsigned int outPort = 1234;
unsigned int inPort = 8001;

void setup()
{
  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");

  udp.begin(inPort);
  
  while (!WiFi.ready())
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  IPAddress ip = WiFi.localIP();
  Serial.print(F("ip : ")); Serial.print(ip);
  Serial.print(F(" : ")); Serial.print(inPort);
}

void loop()
{
    
    //RECEIVE
    int size = 0;
    OSCMessage inMessage;
    if ( ( size = udp.parsePacket()) > 0)
    {
          while (size--)
        {
            inMessage.fill(udp.read());
        }
        if( inMessage.parse())
        {
            inMessage.route("/ping", PING);
        }
    }
    
    //SEND
    OSCMessage outMessage("/pong");
    outMessage.addString("test");
    outMessage.addFloat(-3.14);
    outMessage.addInt(-1);
    outMessage.send(udp,outIp,outPort);
}

void PING(OSCMessage &inMessage)
{
//Do something
}
