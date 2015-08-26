#include "application.h"

class OSCMessage
{
    
private:
    
    char * incomingBuffer;
    int incomingBufferSize;
    String inputAddress;//should be char array
    String inputTypes;
    char * inputDatas;
    
    String outputAddress;//should be char array
    String outputTypes;
    char * outputDatas;
    int outputDatasSize;
    
    void prinOutputDatas();
    
public:
    OSCMessage();
    OSCMessage(const char * address);
    ~OSCMessage();
    void setupMessage();
    void fill(char);
    bool parse();
    void route(const char * pattern, void (*callback)(OSCMessage &));
    int getInt(int offset);
    float getFloat(int offset);
    
    void addInt(int value);
    void addFloat(float value);
    void addString(const char * value);
    void send(UDP &udp, IPAddress remoteIP, unsigned int outPort);
};
