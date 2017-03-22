#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

/*
 * Factory Method Pattern
 *
 * Use case: I have two class TCP and class UDP which symbolize ways to send messages
 -> However user only cares about sending message instead of what called TCP or UDP
 -> Factory Method Pattern will provide way to switch between TCP and UDP easily with a few changes in user source code

 * Idea:
 * 1) Build an interface for both class (Factory)
 * 2) Use a static method that manufactures products from the factory :D
   NOTE**: Users only use the factory to create TCP or UDP object rather than instances it on their own.
 */

#include <iostream>
using namespace std;

enum ProtocolType {
    TCP = 0,
    UDP
};

// Factory
class TCPProtocol;
class UDPProtocol;

class ProtocolInterface {
public:
    static ProtocolInterface* createProtocol(ProtocolType protocolType);
    virtual void sendMessage() = 0;
};

class TCPProtocol: public ProtocolInterface {
public:
    void sendMessage() {
        cout << "TCP send message" << endl;
    }
};

class UDPProtocol: public ProtocolInterface {
public:
    void sendMessage() {
        cout << "UDP send message" << endl;
    }
};

ProtocolInterface* ProtocolInterface::createProtocol(ProtocolType protocolType) {
    if (protocolType == TCP)
        return new TCPProtocol;
    else
        return new UDPProtocol;
}

#endif // FACTORYMETHOD_H
