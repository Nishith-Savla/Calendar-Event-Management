#include <iostream>
#include <vector>

#ifndef CALENDAREVENTMANAGEMENT_TODO_H
#define CALENDAREVENTMANAGEMENT_TODO_H

using namespace std;

class Todo {
private:
    string name;
    vector<int> dueDate;
    bool hasCompleted = false;
    static int totalTodos;
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    const vector<int> &getDueDate() const {
        return dueDate;
    }

    void setDueDate(const vector<int> &dueDate) {
        this->dueDate = dueDate;
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

    Todo();

    Todo(const string &name, const vector<int> &dueDate);
};


#endif //CALENDAREVENTMANAGEMENT_TODO_H
