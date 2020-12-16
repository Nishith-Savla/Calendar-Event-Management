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
    vector<int> date;
    vector<string> dateSplit = Functions::split(event[2]);
    date.reserve(3);
    for (const auto &i : dateSplit) {
        date.push_back(stoi(i));
    }
    this->setDateOfCompletion(date);
    this->checkCompleted(getTodaysDate());
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
    for (auto dateValue: this->dateOfCompletion) {
        event.append(to_string(dateValue)).append(" ");
    }
    return event;
}

Event Event::addEvent() {
    string name, description, date;
    cout << "Enter event name: ";
    getline(cin, name);
    cout << "Enter event description: ";
    getline(cin, description);
    cout << "Enter event date: ";
    getline(cin, date);
    return Event(vector<string> {name, description, date});
}

void Event::showEvent(Event event) {
    cout << "Id: " << event.getId() << endl;
    cout << "Name: " << event.getName() << endl;
    cout << "Description: " << event.getDescription() << endl;
    cout << "Date: ";
    vector<int> dateOfCompletion = event.getDateOfCompletion();
    for (auto date = dateOfCompletion.begin(); date != dateOfCompletion.end(); ++date) {
        cout << *date;
        if (date + 1 != dateOfCompletion.end())
            cout << "/";
    }
    cout << endl;
    cout << "Has occured: " <<  event.isCompleted() << endl;
}

void Event::updateEvent(vector<Event> *eventList) { // TODO event not updating
    int Id;
    Event *event = &(*eventList)[Id + 1];
    string fieldToChange, newValue;
    cout << "Enter the Id of the event you want to update: ";
    cin >> Id;
    cout << "Enter the field you want to change: ";
    cin.ignore();
    getline(cin, fieldToChange);
    transform(fieldToChange.begin(), fieldToChange.end(), fieldToChange.begin(), ::tolower);
    if (fieldToChange == "name") {
        cout << "Enter new " << fieldToChange << " for the event: ";
        getline(cin, newValue);
        event->setName(newValue);
    } else if (fieldToChange == "description") {
        cout << "Enter new " << fieldToChange << " for the event: ";
        getline(cin, newValue);
        event->setDescription(newValue);
    } else if (fieldToChange == "date") {
        cout << "Enter new " << fieldToChange << " for the event: ";
        getline(cin, newValue);
        event->setDateOfCompletion(Functions::split(newValue));
    } else {
        cerr << "Please enter a valid field (name/description/date):" << endl;
        updateEvent(eventList);
    }
}
void Event::deleteEvent(vector<Event> *eventList) {
    int Id;
    cout << "Enter the Id of the event you want to delete: ";
    cin >> Id;
    if(eventList->size() > Id-1) {
        eventList->erase(eventList->begin() + Id - 1);
    }
}

