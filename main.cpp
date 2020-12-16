#include "Event.h"
#include "Todo.h"

void eventMenu(vector<Event> &events, int select);

using namespace std;

int main() {
//    cout << boolalpha;
//    string dateStr = "11/12/2020";
//    vector<int> date;
//    vector<string> dateSplit = Functions::split(dateStr);
//    date.reserve(dateSplit.size()); // create space in memory equal to size of dateSplit
//    for (const auto &i : dateSplit) {
//        date.push_back(stoi(i));
//    }
//
//    Event e1("Test", "test", date);
//    cout << "Event name: " << e1.getName() << endl;
//    cout << "Event description: " << e1.getDescription() << endl;
//    cout << "Event date: ";
//    for (auto a: e1.getDateOfCompletion()) cout << a << " ";
//    cout << endl;
//    cout << "Has completed? :" << e1.isCompleted() << endl;
////    e1.dumpToFile();
//
//    Event e2("Test2", "test2", date);
//    cout << "Event name: " << e2.getName() << endl;
//    cout << "Event description: " << e2.getDescription() << endl;
//    cout << "Event date: ";
//    for (auto a: e2.getDateOfCompletion()) cout << a << " ";
//    cout << endl;
//    cout << "Has completed? :" << e2.isCompleted() << endl;
//    cout << "Total events: " << Event::getTotalEvents() << endl;
////    e2.dumpToFile();
//
//    cout << endl;
//    Todo t1("Todo 1", date);
//    cout << "Todo name: " << t1.getName() << endl;
//    cout << "Todo due date: ";
//    for (auto a: t1.getDueDate()) cout << a << " ";
//    cout << endl;
//    cout << "Has completed? :" << t1.isCompleted() << endl;
//    cout << t1.markCompleted() << endl;
//    cout << "Has completed? :" << t1.isCompleted() << endl;
//    cout << "Total todos: " << Todo::getTotalTodos() << endl;
//
//    cout << endl;
//    Todo t2("Todo 1", date);
//    cout << "Todo name: " << t2.getName() << endl;
//    cout << "Todo due date: ";
//    for (auto a: t2.getDueDate()) cout << a << " ";
//    cout << endl;
//    cout << "Has completed? :" << t2.isCompleted() << endl;
//    cout << t2.markCompleted() << endl;
//    cout << "Has completed? :" << t2.isCompleted() << endl;
//    cout << "Total todos: " << Todo::getTotalTodos() << endl;
////    vector<Todo> todos;
//    Functions::loadFromFile(".todostorage.csv", "TODO", todos);

//    Show menu

//    Functions::showMenu();
//
//    Functions::showIdentifier("Events");
//
////    Event e3 = Event::addEvent();
////    Event::showEvent(e3);
//    vector<Event> eventList {e1, e2};
//    Event::updateEvent(eventList);
//    Event::showEvent(eventList[1]);
//    eventList.push_back(Event::addEvent());
//    Event::dumpAllToFile(eventList);
//    cout << eventList[1].getName() << endl;
//    cout << eventList.size() << endl;
//    Event::deleteEvent(eventList);
//    cout << eventList.size() << endl;
//    for (Event a: eventList) {
//        cout << a.getId() << endl;
//        cout << a.dumpToString() << endl;
//    }

//    vector<Todo> todoList {t1,t2};
//    Todo::updateTodo(todoList);
//    Todo::showTodo(todoList[1]);
//    cout << todoList.size() << endl;
//    Todo::deleteTodo(todoList);
//    cout << todoList.size() << endl;
//    cin.get();
    vector<Event> events;
    vector<Todo> todos;
    Functions::showMenu();
    int choice;
    do{
        cout << "Enter your choice => ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                Functions::showIdentifier("events");
                int select;
                cout << "Enter your choice for events => ";
                cin >> select;
                cout << endl;
                eventMenu(events, select);
                break;
            case 2:
                Functions::showIdentifier("todos ");
                int select2;
                cout << "Enter your choice for todos => ";
                cin >> select2;
                switch (select2) {
                    case 1:
                        // Add todo
                        cout << "Add functionality for todo\n";
                        Functions::showMenu();
                        break;
                    case 2:
                        // View todo
                        cout << "View functionality for todo\n";
                        Functions::showMenu();
                        break;
                    case 3:
                        // Update todo
                        cout << "Update functionality for todo\n";
                        Functions::showMenu();
                        break;
                    case 4:
                        // Delete functionality
                        cout << "Delete functionality for todo\n";
                        Functions::showMenu();
                        break;
                    default:
                        Functions::showIdentifier("todos");
                        cout << endl;
                }
                break;
            case 3:
                cout << "Exit"<<endl;
                break;
            default:
                Functions::showMenu();
                cout << endl;
        }
    } while (choice != 3);

}

void manageMenu(string option, vector<Event> &events, vector<Todo> &todos, int select) {
    bool isEvent = (option == "event");
    switch(select) {
        case 1:
            // Add - Adding event functionality
            cout << "Adding functionality for " << option << "s\n";
            isEvent ? events.push_back(Event::addEvent()) : todos.push_back(Todo::addTodo());
            Functions::showMenu();
            break;
        case 2:
            // Add - View events functionality
            cout << "View functionality for " << option << "s\n";
            if(isEvent)
                for(auto event : events) Event::showEvent(event);
            else
                for(auto todo : todos) Todo::showTodo(todo);
            Functions::showMenu();
            break;
        case 3:
            // Update functionality
            cout << "Update functionality for events\n";
            Event::updateEvent(events);
            Functions::showMenu();
            break;
        case 4:
            // Delete functionality
            cout << "Delete functionality for events\n";
            Event::deleteEvent(events);
            Functions::showMenu();
            break;
        case 0:
            Functions::showMenu();
            break;
        default:
            cerr << "Invalid choice! " << endl;
            Functions::showIdentifier("events");
            break;

    }
}
