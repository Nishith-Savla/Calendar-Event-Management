#ifndef CALENDAREVENTMANAGEMENT_EVENT_H
#define CALENDAREVENTMANAGEMENT_EVENT_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "Functions.h"

using namespace std;

class Event{
    int id = totalEvents + 1;
    string name;
    string description;
    vector<int> dateOfCompletion;

//    bool doesRepeat; TODO add repeat feature
    bool hasCompleted = false;
    static int totalEvents;
public:
    int getId() const {
        return id;
    }

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

    void setDateOfCompletion(const vector<int> &dateOfCompletion) {
        this->dateOfCompletion = dateOfCompletion;
        this->checkCompleted(getTodaysDate());
    }

    void setDateOfCompletion(const vector<string> &dateOfCompletion) {
        this->dateOfCompletion.clear();
        for (const auto &i : dateOfCompletion) {
            this->dateOfCompletion.push_back(stoi(i));
        }
        this->checkCompleted(getTodaysDate());
    }

    bool isCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        this->hasCompleted = hasCompleted;
    }

    void checkCompleted(const vector<int> &currentDate);

    static int getTotalEvents() {
        return totalEvents;
    }

    static vector<int> getTodaysDate() {
        time_t currentTime = time(nullptr);
        tm *ltime = localtime(&currentTime);
        vector<int> date;
        date.push_back(ltime->tm_mday);
        date.push_back(ltime->tm_mon + 1); // +1 as tm_mon returns month based on index 0
        date.push_back(ltime->tm_year + 1900); // +1900 as tm_year returns years passed after 1900
        return date;
    }

    string dumpToString();

    void dumpToFile(const string &fileName=".eventstorage(do_not_modify).csv") {
        const string &stringToDump=this->dumpToString();
        ofstream outputFile;
        outputFile.open((string) getenv("USERPROFILE") + "/" + fileName, ios_base::app | ios_base::out);
        outputFile << stringToDump << endl;
        outputFile.close();
    }

    static void dumpAllToFile(vector<Event> events, const string &fileName=".eventstorage(do_not_modify).csv") {
        ofstream outputFile;
        outputFile.open((string) getenv("USERPROFILE") + "/" + fileName, ios_base::out);
        for (auto event: events) {
            outputFile << event.dumpToString() << endl;
        }
        outputFile.close();
    }

    Event();

    explicit Event(vector<string>);

    Event(const string &name, const string &description, const vector<int> &dateOfCompletion);

    static Event addEvent();

    static void showEvent(Event event);

    static void updateEvent(vector<Event> &eventList);

    static void deleteEvent(vector<Event> &eventList);
};

#endif //CALENDAREVENTMANAGEMENT_EVENT_H
