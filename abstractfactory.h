#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
/*
 * Abstract Factory
 *
 * Use case:
 * You have a view that contains buttons and menus but they might depend on operating system.
   For example: WindowButton vs LinuxButton.
   -> Rather than use #ilef (Your operating system) for each createdButton or createdMenu, you can buid Window Factory and Linux Factory
   to produce buttons and menus of each factory.

 * Idea:
 * Build an abstract factory to define which type of products that "real" factories want to produce
   NOTE**: Users only use the factory to produce product rather than instances it on their own.
 */

#include <iostream>
using namespace std;
/* Abstract Product */
class Widget {
public:
    virtual void draw () {
        cout << "Widget draws" << endl;
    }
};

/* Window Products */
class WindowButton: public Widget {
public:
    void draw () {
        cout << "Window Button draws" << endl;
    }
};

class WindowMenu: public Widget {
public:
    void draw () {
        cout << "Window Menu draws" << endl;
    }
};

/* Linux Products */
class LinuxButton: public Widget {
public:
    void draw () {
        cout << "Linux Button draws" << endl;
    }
};

class LinuxMenu: public Widget {
public:
    void draw () {
        cout << "Linux Button draws" << endl;
    }
};

/* Abstract Factory */
class OperatingSystemAbstract {
public:
    virtual Widget* createButton() = 0;
    virtual Widget* createMenu() = 0;
};

class WindowOps: public OperatingSystemAbstract {
public:
    Widget* createButton() {
        return new WindowButton;
    }

    Widget* createMenu() {
        return new WindowMenu;
    }
};

class LinuxOps: public OperatingSystemAbstract {
public:
    Widget* createButton() {
        return new LinuxButton;
    }

    Widget* createMenu() {
        return new LinuxMenu;
    }
};

#endif // ABSTRACTFACTORY_H
