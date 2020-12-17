#include "Event.h"
#include "Todo.h"

int manageMenu(string option, vector<Event> &events, vector<Todo> &todos);

void manageMainMenu(vector<Event> &events, vector<Todo> &todos);

using namespace std;

int main() {
    cout << boolalpha;
    vector<Event> events;
    vector<Todo> todos;
    for (const auto& eventStr : Functions::loadFromFile(".eventstorage(do_not_modify).csv")) {
        if(!eventStr.empty())
            events.emplace_back(Event(eventStr));
    }
    for (const auto& todoStr : Functions::loadFromFile(".todostorage(do_not_modify).csv")) {
        if (!todoStr.empty())
            todos.emplace_back(Todo(todoStr));
    }
    manageMainMenu(events, todos);
}

void manageMainMenu(vector<Event> &events, vector<Todo> &todos) {
    Functions::showMainMenu();
    int choice;
    do{
        cout << "Enter your choice => ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                Functions::showIdentifier("event");
                if (manageMenu("event", events, todos)) {
//                    Functions::showMainMenu();
                    manageMainMenu(events, todos);
                }
                break;
            case 2:
                Functions::showIdentifier("todo");
                if (manageMenu("todo", events, todos)) {
//                    Functions::showMainMenu();
                    manageMainMenu(events, todos);
                }
                break;
            case 3:
                cout << "Exit"<<endl;
                Event::dumpAllToFile(events);
                Todo::dumpAllToFile(todos);
                exit(0);
            default:
                Functions::showMainMenu();
                cout << endl;
        }
    } while (choice != 3);
}

int manageMenu(string option, vector<Event> &events, vector<Todo> &todos) {
    int select;
    cout << "Enter your choice for events => ";
    cin >> select;
    cout << endl;
    bool isEvent = (option == "event");
    switch(select) {
        case 1:
            // Add - Adding event functionality
            cout << "Adding functionality for " << option << "s\n";
            if(isEvent) {
                Event newEvent = Event::addEvent();
                events.push_back(newEvent);
                Functions::printHRLine();
                Event::showEvent(newEvent);
                Functions::printHRLine();
            }else {
                Todo newTodo = Todo::addTodo();
                todos.push_back(newTodo);
                Functions::printHRLine();
                Todo::showTodo(newTodo);
                Functions::printHRLine();
            }

            Functions::showIdentifier(option);
            manageMenu(option, events, todos);
            break;
        case 2:
            // Add - View events functionality
            cout << "View functionality for " << option << "s\n";
            if(isEvent) {
                for (const auto &event : events) {
                    Functions::printHRLine();
                    Event::showEvent(event);
                    Functions::printHRLine();
                }
            }
            else {
                for (const auto &todo : todos) {
                    Functions::printHRLine();
                    Todo::showTodo(todo);
                    Functions::printHRLine();
                }
            }
            Functions::showIdentifier(option);
                manageMenu(option, events, todos);
            break;
        case 3:
            // Update functionality
            cout << "Update functionality for events\n";
            isEvent ? Event::updateEvent(events) :Todo::updateTodo(todos);
            Functions::showIdentifier(option);
            manageMenu(option, events, todos);
            break;
        case 4:
            // Delete functionality
            cout << "Delete functionality for events\n";
            isEvent ? Event::deleteEvent(events) :Todo::deleteTodo(todos);
            Functions::showIdentifier(option);
            manageMenu(option, events, todos);
            break;
        case 0:
            return 1;
        default:
            cerr << "Invalid choice! " << endl;
            Functions::showIdentifier("events");
            break;
    }
    return 0;
}
