#include <iostream>
#include <ctime>
#include <vector>
#include "Event.h"
#include "Todo.h"
//#include <sqlite3.h>

using namespace std;

vector<int> getTodaysDate() {
    time_t currentTime = time(nullptr);
    tm *ltime = localtime(&currentTime);
    vector<int> date;
    date.push_back(ltime->tm_mday);
    date.push_back(ltime->tm_mon + 1); // +1 as tm_mon returns month based on index 0
    date.push_back(ltime->tm_year + 1900); // +1900 as tm_year returns years passed after 1900
    return date;
}

vector<string> split(const string &s, const string &delimiter) {
    size_t pos_start = 0, pos_end, delimiter_len = delimiter.length();
    string token;
    vector<string> split_strings;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delimiter_len;
        split_strings.push_back(token);
    }
    split_strings.push_back(s.substr(pos_start));
    return split_strings;

}

int main() {
    string dateStr = "11/12/2020";
    vector<int> date;
    vector<string> dateSplit = split(dateStr, "/");

    date.reserve(dateSplit.size()); // create space in memory equal to size of dateSplit
    for (const auto &i : dateSplit) {
        date.push_back(stoi(i));
    }

    Event e1("Test", "test", date);
    cout << e1.getName() << endl;
    cout << e1.getDescription() << endl;
    cout << "HAS COMPLETED:" << e1.getHasCompleted() << endl;
    for (auto a: e1.getDateOfCompletion()) cout << a << " ";
    cout << endl;
    e1.checkCompleted(getTodaysDate());
    cout << e1.getHasCompleted() << endl;

}
