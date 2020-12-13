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
    bool hasCompleted = false;
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

    vector<int> getDateOfCompletion() {
        return dateOfCompletion;
    }

    void setDateOfCompletion(vector<int> dateOfCompletion) {
        this->dateOfCompletion.clear();
        for (int i = 0; i < dateOfCompletion.size(); ++i) {
            this->dateOfCompletion.push_back(dateOfCompletion[i]);
        }
    }

    bool getHasCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        this->hasCompleted = hasCompleted;
    }

    void checkCompleted(const vector<int> &currentDate);

    static int getTotalEvents() {
        return totalEvents;
    }

    Event();

    Event(const string &name, const string &description, vector<int> dateOfCompletion);
};

#endif //CALENDAREVENTMANAGEMENT_EVENT_H
