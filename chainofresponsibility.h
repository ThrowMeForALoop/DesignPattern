#ifndef CHAINOFREPONSIBILITY_H
#define CHAINOFREPONSIBILITY_H

/*
 * Chain of responsibility
 *
 * Use case:
 * Case 1: When user press to a rectangle button and this button contains a radio button
 -> event will be raised until one of two button handle it.
   For understandable example, I consider a rectangle button as a even number handler and a radio button as an odd number handler

 * Idea:
 * 1) Use a linklist-like structure to pass events through this linklist.
 * 2) If a node doesn't handle the event, the next node will continue to handle it.
 */

#include <iostream>
class BaseHandler {
private:
    BaseHandler* mNext;
public:
    virtual void handle(int number) {
        mNext->handle(number);
    }

    // add handler to the end of list
    void addHandler(BaseHandler* handler) {
        if (mNext)
            mNext->addHandler(handler);
        else
            mNext = handler;
    }
};

class EvenNumberHandler: public BaseHandler {
public:
    void handle(int number) {
        if (number % 2 == 0)
            cout << "EvenHandler handles value " << number << endl;
        else {
            // Pass event to next handle
            BaseHandler::handle(number);
        }
    }
};

class OddNumberHandler: public BaseHandler {
public:
    void handle(int number) {
        if (number % 2 != 0)
            cout << "OddHandler handles value " << number << endl;
        else {
            // Pass event to next handle
            BaseHandler::handle(number);
        }
    }
};

#endif // CHAINOFREPONSIBILITY_H
