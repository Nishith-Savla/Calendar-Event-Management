//
// Created by acer on 15-12-2020.
//

#ifndef CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H
#define CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Functions{
public:
    static vector <string> split(const string &s, const string &delimiter) {
        size_t pos_start = 0, pos_end, delimiter_len = delimiter.length();
        string token;
        vector <string> split_strings;
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
        outputFile.open((string) getenv("USERPROFILE") + "/" + fileName, ios_base::app | ios_base::out);
        outputFile << stringToDump << endl;
        outputFile.close();
    }

    static vector <vector<string>> loadFromFile(const string &fileName) {
        ifstream inputFile;
        inputFile.open((string) getenv("USERPROFILE") + "/" + fileName);
        string line, temp;
        vector <string> entities;
        while (inputFile >> temp) {
            getline(inputFile, line);
            entities.push_back(line);
        }
        vector <vector<string>> objects;
        for (const auto &entity: entities) {
            vector <string> row;
            stringstream stream(entity);
            string word;
            while (getline(stream, word, ',')) {
                row.push_back(word);
            }
            objects.push_back(row);
        }
        return objects;
    }

};


#endif //CALENDAR_EVENT_MANAGEMENT_FUNCTIONS_H
