#include "Event.h"

Event::Event() {
    ++Event::totalEvents;
    this->dateOfCompletion.reserve(3); // create 3 blocks of space in memory
}

Event::Event(const string &name, const string &description, const vector<int> &dateOfCompletion) : Event() {
    this->setName(name);
    this->setDescription(description);
    this->setDateOfCompletion(dateOfCompletion);
}

int Event::totalEvents = 0;

Event::Event(vector<string> event) {
    this->setName(event[0]);
    this->setDescription(event[1]);
    this->setHasCompleted(event[2] == "true");
    vector<int> date;
    vector<string> dateSplit = Functions::split(event[3], "/");
    date.reserve(3);
    for (const auto &i : dateSplit) {
        date.push_back(stoi(i));
    }
    this->setDateOfCompletion(date);
}

void Event::checkCompleted(const vector<int> &currentDate) {
    if (currentDate[2] > this->dateOfCompletion[2]) {
        this->hasCompleted = true;
        cout << "DEBUG: (from Event::checkCompleted) " << "Year is greater" << endl;
    } else if (currentDate[2] == this->dateOfCompletion[2]) {
        cout << "DEBUG: (from Event::checkCompleted) " << "Year is same" << endl;
        if (currentDate[1] > this->dateOfCompletion[1]) {
            this->hasCompleted = true;
            cout << "DEBUG: (from Event::checkCompleted) " << "Month is greater" << endl;
        } else if (currentDate[1] == this->dateOfCompletion[1]) {
            cout << "DEBUG: (from Event::checkCompleted) " << "Month is same" << endl;
            if (currentDate[0] > this->dateOfCompletion[0]) {
                cout << "DEBUG: (from Event::checkCompleted) " << "Day is greater" << endl;
                this->hasCompleted = true;
            }
        }
    }
}

string Event::dumpToString() {
    string event;
    event.append(this->name).append(",");
    event.append(this->description).append(",");
    event.append(this->hasCompleted ? "true" : "false").append(",");
    for (auto dateValue: this->dateOfCompletion) {
        event.append(to_string(dateValue)).append(" ");
    }
    return event;
}
