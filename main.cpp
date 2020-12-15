#include "Event.h"
#include "Todo.h"
#include <windows.h>

using namespace std;
#define HRLINE \
    CONSOLE_SCREEN_BUFFER_INFO csbi; \
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); \
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1; \
    for(int i=1; i<=width; i++) std::cout<< "-"; std::cout << std::endl;

int main() {
    cout << boolalpha;
    string dateStr = "11/12/2020";
    vector<int> date;
    vector<string> dateSplit = Functions::split(dateStr, "/");
    date.reserve(dateSplit.size()); // create space in memory equal to size of dateSplit
    for (const auto &i : dateSplit) {
        date.push_back(stoi(i));
    }

    Event e1("Test", "test", date);
    cout << "Event name: " << e1.getName() << endl;
    cout << "Event description: " << e1.getDescription() << endl;
    cout << "Event date: ";
    for (auto a: e1.getDateOfCompletion()) cout << a << " ";
    cout << endl;
    cout << "Has completed? :" << e1.isCompleted() << endl;
//    e1.dumpToFile();

    Event e2("Test2", "test2", date);
    cout << "Event name: " << e2.getName() << endl;
    cout << "Event description: " << e2.getDescription() << endl;
    cout << "Event date: ";
    for (auto a: e2.getDateOfCompletion()) cout << a << " ";
    cout << endl;
    cout << "Has completed? :" << e2.isCompleted() << endl;
    cout << "Total events: " << Event::getTotalEvents() << endl;
//    e2.dumpToFile();

    cout << endl;
    Todo t1("Todo 1", date);
    cout << "Todo name: " << t1.getName() << endl;
    cout << "Todo due date: ";
    for (auto a: t1.getDueDate()) cout << a << " ";
    cout << endl;
    cout << "Has completed? :" << t1.isCompleted() << endl;
    cout << t1.markCompleted() << endl;
    cout << "Has completed? :" << t1.isCompleted() << endl;
    cout << "Total todos: " << Todo::getTotalTodos() << endl;
    t1.dumpToFile();
//    for (auto a: Event::eventStore) {a->dumpToFile();}
//    vector<Todo> todos;
//    Functions::loadFromFile(".todostorage.csv", todos);

//    Show menu
//
//    Event e;
//    Functions::showMenu();
//    HRLINE
}
