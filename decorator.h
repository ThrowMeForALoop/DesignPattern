#ifndef DECORATOR_H
#define DECORATOR_H

/*
 * Decorator Pattern
 * Use case: Extend a class with a combination of functions instead of fixing ones.
 * Example: A window UI can be extended with vertical scroll or horizontal scroll or both.

 * Idea:
 * 1) Keep core method of your original class.
 * 2) Extend the original class with a derived class, which involves a wrapper to contain function-extended class.

 */

#include <iostream>
using namespace std;

// Core Interface

class WindowInterface {
public:
    virtual void coreMethod() = 0;
};

class Window: public WindowInterface {
    void coreMethod() {
        cout << "Window method" << "; ";
    }
};

// Base Wrapper Class
class WindowWrapper: public WindowInterface {
private:
    WindowInterface* mWrapper;
public:
    WindowWrapper (WindowInterface* wrapper) {
        mWrapper = wrapper;
    }

    void coreMethod() {
        mWrapper->coreMethod();
    }
};

class WindowWithVerticalScroll: public WindowWrapper {
public:
    WindowWithVerticalScroll (WindowInterface* core): WindowWrapper (core) {

    }

    void coreMethod() {
        WindowWrapper::coreMethod();
        cout << "Add Vertical Scroll to window" << "; ";
    }
};

class WindowWithHorizontalScroll: public WindowWrapper {
public:
    WindowWithHorizontalScroll (WindowInterface* core): WindowWrapper (core) {

    }

    void coreMethod() {
        WindowWrapper::coreMethod();
        cout << "Add Horizontal Scroll to window" << "; ";
    }
};

#endif // DECORATOR_H
