#ifndef CALENDAREVENTMANAGEMENT_FUNCTION_CPP
#define CALENDAREVENTMANAGEMENT_FUNCTION_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Event.h"

using namespace std;

class Functions {
public:
    static vector<string> split(const string &s, const string &delimiter) {
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

    static void dumpToFile(const string &stringToDump, const string &fileName) {
        ofstream outputFile;
        outputFile.open((string)getenv("USERPROFILE") + "/" + fileName, ios_base::app | ios_base::out);
        outputFile << stringToDump << endl;
        outputFile.close();
    }

    static void loadFromFile(const string &fileName, auto &objectCollection) {
        ifstream inputFile;
        inputFile.open((string)getenv("USERPROFILE") + "/" + fileName);
        string line, temp;
        vector<string> events;
        while (inputFile >> temp) {
            getline(inputFile, line);
            events.push_back(line);
        }
        for (const auto &event: events) {
            vector<string> row;
            stringstream stream(event);
            string word;
            while (getline(stream, word, ',')) {
                row.push_back(word);
            }
            objectCollection.push_back(row);
        }
    }

    static void showMenu() {
        cout << "=============================";
    }
};

#endif // CALENDAREVENTMANAGEMENT_FUNCTION_CPP
