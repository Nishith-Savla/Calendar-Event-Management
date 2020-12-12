//
// Created by Admin on 12-12-2020.
//

#include "Event.h"

Event::Event() {
    ++Event::totalEvents;
}

Event::Event(const string& name, const string& description, int date[]) : Event() {
    this->setName(name);
    this->setDescription(description);
    this->setDateOfCompletion(date);

}

int Event::totalEvents = 0;

void Event::checkCompleted(const int currentDate[]) {
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