#include <iostream>
#include "abstractfactory.h"
#include "chainofresponsibility.h"
#include "decorator.h"
#include "factorymethod.h"
#include "observer.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    /*---------------------------------
    // Abstract Factory Pattern Example
    OperatingSystemAbstract* ops;

#if defined (_WIN32) || defined (_WIN64) || defined (__APPLE__)
    ops = new WindowOps;
#else
    ops = new LinuxOps;
#endif

    Widget* widgets[] = {ops->createButton(), ops->createMenu() };
    widgets[0]->draw();
    widgets[1]->draw();
    */

    /*---------------------------------
    // Decorator Pattern Example
    WindowInterface* windowWithVerticalScroll = new WindowWithVerticalScroll(new Window);
    windowWithVerticalScroll->coreMethod();

    cout << endl;

    WindowInterface* windowWithVerticalAndHorizontalScroll = new WindowWithHorizontalScroll(new WindowWithVerticalScroll (new Window));
    windowWithVerticalAndHorizontalScroll->coreMethod();
    */

    /*--------------------------------
     // Factory Method Pattern Example
    ProtocolInterface* protocol = ProtocolInterface::createProtocol(TCP);
    protocol->sendMessage();
    */

    /*--------------------------------
    // Observer Pattern Example
    Model* model = new Model();
    View1* view1 = new View1;
    model->attach(view1);

    View2* view2 = new View2;
    model->attach(view2);

    model->notify(100);
    return 0;
    */

    // Chain of responsibility Pattern example
    BaseHandler rootHandler;
    EvenNumberHandler evenNumberHandler;
    OddNumberHandler oddNumberHandler;
    rootHandler.addHandler(&evenNumberHandler);
    rootHandler.addHandler(&oddNumberHandler);

    for (int i = 0 ; i < 10; i ++) {
        rootHandler.handle(i);
    }
    /*----------------------------------
    */
}
