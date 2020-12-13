//
// Created by Admin on 12-12-2020.
//4

#include <iostream>
#include <vector>

using namespace std;

#ifndef CALENDAREVENTMANAGEMENT_EVENT_H
#define CALENDAREVENTMANAGEMENT_EVENT_H


class Event {
    string name;
    string description;
    vector<int> dateOfCompletion{3};
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

    vector<int> getDateOfCompletion() const {
        return dateOfCompletion;
    }

    void setDateOfCompletion(vector<int> dateOfCompletion) {
        for(int i = 0; i < dateOfCompletion.size(); i++) {
            this->dateOfCompletion[i] = dateOfCompletion[i];
        }
    }

    bool getHasCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        this->hasCompleted = hasCompleted;
    }

    void checkCompleted(vector<int> currentDate);

    static int getTotalEvents() {
        return totalEvents;
    }

    Event();

    Event(const string& name, const string& description, vector<int> dateOfCompletion);
};

#endif //CALENDAREVENTMANAGEMENT_EVENT_H