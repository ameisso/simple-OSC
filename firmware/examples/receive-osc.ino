#include "simple-OSC/simple-OSC.h"

UDP udp;

unsigned int inPort = 8001;

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
}

void PING(OSCMessage &inMessage)
{
    Serial.println("/ping ");
//Do something
}
