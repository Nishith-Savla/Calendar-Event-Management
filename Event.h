//
// Created by Admin on 12-12-2020.
//

#include <iostream>

using namespace std;

#ifndef CALENDAREVENTMANAGEMENT_EVENT_H
#define CALENDAREVENTMANAGEMENT_EVENT_H


class Event {
    string name;
    string description;
    int dateOfCompletion[3]{};
//    bool doesRepeat; TODO add repeat feature
    bool hasCompleted{};
    static int totalEvents;
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        this->description = description;
    }

    const int *getDateOfCompletion() const {
        return dateOfCompletion;
    }

    void setDateOfCompletion(int date[]) {
        for (int i = 0; i < sizeof(date) / sizeof(int); ++i) {
            this->dateOfCompletion[i] = date[i];
        }
    }

    bool getHasCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        this->hasCompleted = hasCompleted;
    }

    void checkCompleted(const int currentDate[]);

    static int getTotalEvents() {
        return totalEvents;
    }

    Event();

    Event(const string& name, const string& description, int date[]);
};

#endif //CALENDAREVENTMANAGEMENT_EVENT_H
