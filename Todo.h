#ifndef CALENDAREVENTMANAGEMENT_TODO_H
#define CALENDAREVENTMANAGEMENT_TODO_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Functions.h"

using namespace std;

class Todo{
    int id = totalTodos + 1;
    string name;
    vector<int> dueDate;
    bool hasCompleted = false;
    static int totalTodos;
public:
    int getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    const vector<int> &getDueDate() const {
        return dueDate;
    }

    void setDueDate(vector<int> dueDate) {
        this->dueDate = dueDate;
    }

    void setDueDate(const vector<string> &dueDate) {
        this->dueDate.clear();
        for (const auto &i : dueDate) {
            this->dueDate.push_back(stoi(i));
        }
    }

    bool isCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        this->hasCompleted = hasCompleted;
    }

    static int getTotalTodos() {
        return totalTodos;
    }

    bool markCompleted() {
        if (!isCompleted()) {
            setHasCompleted(true);
            return true;
        }
        return false;
    }

    string dumpToString();

    void dumpToFile(const string &fileName=".todostorage.csv") {
        const string &stringToDump=this->dumpToString();
        ofstream outputFile;
        outputFile.open((string) getenv("USERPROFILE") + "/" + fileName, ios_base::app | ios_base::out);
        outputFile << stringToDump << endl;
        outputFile.close();
    }

    Todo();

    explicit Todo(vector<string>);

    Todo(const string &name, vector<int> dueDate);

    virtual ~Todo() {
        this->dumpToFile();
    }

    static Todo addTodo();

    static void showTodo(Todo todo);

    static void updateTodo(vector<Todo> &todolist);

    static void deleteTodo(vector<Todo> &todolist);
};


#endif //CALENDAREVENTMANAGEMENT_TODO_H
