#ifndef CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H
#define CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

class Functions {
public:
    static vector<string> split(const string &s, const string &delimiter="/") {
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

    static vector<vector<string>> loadFromFile(const string &fileName) {
        ifstream inputFile;
        inputFile.open((string) getenv("USERPROFILE") + "/" + fileName);
        string line, temp;
        vector<string> entities;
        while (inputFile >> temp) {
            getline(inputFile, line);
            entities.push_back(line);
        }
        vector<vector<string>> objects;
        for (const auto &entity: entities) {
            vector<string> row;
            stringstream stream(entity);
            string word;
            while (getline(stream, word, ',')) {
                row.push_back(word);
            }
            objects.push_back(row);
        }
        return objects;
    }

    static void printHRLine() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        for (int i = 1; i <= width; i++) std::cout << "=";
    }

    static void showMenu() {
        printHRLine();
        cout << "| 1. Manage Events\n";
        cout << "| 2. Manage Todos\n";
        cout << "| 3. Exit\n";
        printHRLine();
        cout << endl << endl;
    }

    static void showIdentifier(string identifier) {
        printHRLine();
        cout << "| 1. Add " + identifier << endl;
        cout << "| 2. View " + identifier << endl;
        cout << "| 3. Update " + identifier << endl;
        cout << "| 4. Delete " + identifier << endl;
        printHRLine();
    }
};

#endif //CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H
