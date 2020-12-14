#ifndef CALENDAREVENTMANAGEMENT_FUNCTION_CPP
#define CALENDAREVENTMANAGEMENT_FUNCTION_CPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Functions {

public:
    static vector<string> split(const string s, const string &delimiter) {
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

    void dumpToFile(const string &stringToDump, const string &fileName) {
        string userprofile = getenv("USERPROFILE");
        ofstream outputFile;
        outputFile.open(userprofile + "/" + fileName);
        outputFile << stringToDump;
        outputFile.close();
    }
};

#endif // CALENDAREVENTMANAGEMENT_FUNCTION_CPP