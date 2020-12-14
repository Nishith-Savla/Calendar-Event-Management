#include "Event.h"
#include "Todo.h"
#include "Functions.cpp"

using namespace std;

//vector<string> split(const string &s, const string &delimiter) {
//    size_t pos_start = 0, pos_end, delimiter_len = delimiter.length();
//    string token;
//    vector<string> split_strings;
//    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
//        token = s.substr(pos_start, pos_end - pos_start);
//        pos_start = pos_end + delimiter_len;
//        split_strings.push_back(token);
//    }
//    split_strings.push_back(s.substr(pos_start));
//    return split_strings;
//
//}

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
    cout << "Total events: " << Event::getTotalEvents() << endl;
    e1.dumpToFile();

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
}
