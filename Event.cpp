#include "Event.h"
#include <vector>

Event::Event() {
    ++Event::totalEvents;
}

Event::Event(const string &name, const string &description, vector<int> dateOfCompletion) : Event() {
    this->setName(name);
    this->setDescription(description);
    this->setDateOfCompletion(std::move(dateOfCompletion));
}

int Event::totalEvents = 0;

void Event::checkCompleted(const vector<int> &currentDate) {
    if (currentDate[2] > this->dateOfCompletion[2]) {
        this->hasCompleted = true;
    } else if (currentDate[2] == this->dateOfCompletion[2]) {
        if (currentDate[1] > this->dateOfCompletion[1]) {
            this->hasCompleted = true;
        } else if (currentDate[1] == this->dateOfCompletion[1]) {
            if (currentDate[0] > this->dateOfCompletion[0]) {
                this->hasCompleted = true;
            }
        }
    }
}