#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
using namespace std;
/*
 * Abstract Factory
 *
 * Use case:
 * A number of views have to be updated when the related model changes (MVC)
    View = Observer
    Model = Reporter
 * Idea:
 * 1) Reporter shows observer its "attach" interface to listen to reporter's notifications.
 * 2) Reporter updates their registered observers on some changes.
 */
class Model;

class Observer {
public:
    virtual void update (int value) {}
};

class View1: public Observer {
public:
    void update (int value) {
        cout << "View 1 updated value : " << value << endl;
    }
};

class View2: public Observer {
public:
    void update (int value) {
        cout << "View 2 updated value: " << value << endl;
    }
};

class Model {
private:
    vector <Observer*> mObservers;
public:
    void attach (Observer* observer) {
        mObservers.push_back(observer);
    }

    void notify (int value) {
        for (unsigned int i = 0; i < mObservers.size(); i ++) {
            mObservers[i]->update(value);
        }
    }
};

#endif // OBSERVER_H
