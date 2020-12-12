#include <iostream>
#include <ctime>
//#include <sqlite3.h>
#include <cstring>
#include <vector>
#include "Event.h"

using namespace std;

int *getTodaysDate() {
    time_t currentTime = time(nullptr);
    tm *ltime = localtime(&currentTime);
    int *date = new int[3];
    date[0] = ltime->tm_mday;
    date[1] = ltime->tm_mon + 1;
    date[2] = ltime->tm_year + 1900;
    return date;
}

vector<string> split(const string& s, const string& delimiter) {
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
//    int *todaysDate = getTodaysDate();
//    for (int i = 0; i < 3; ++i) {
//        cout << todaysDate[i] << " ";
//    }

    string dateStr = "11/12/2020";
    vector<int> date;
    vector<string> dateSplit = split(dateStr, "/");
    for (auto i : dateSplit) {
        date.push_back(stoi(i));
    }
    for (auto a: date) cout << a << endl;
    Event e1("Test", "test", date);
    cout << e1.getName() << endl;
    cout << e1.getDescription() << endl;
    cout << "HAS COMPLETED:" << e1.getHasCompleted() << endl;
    for (auto a: e1.getDateOfCompletion()) cout << a << " ";
    cout << endl;
}


