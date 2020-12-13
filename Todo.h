#include <iostream>
#include <vector>

#ifndef CALENDAREVENTMANAGEMENT_TODO_H
#define CALENDAREVENTMANAGEMENT_TODO_H

class Todo {
private:
    std::string name;
    std::vector<int> dueDate;
    bool hasCompleted = false;
    static int totalTodos;
public:
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Todo::name = name;
    }

    const std::vector<int> &getDueDate() const {
        return dueDate;
    }

    void setDueDate(const std::vector<int> &dueDate) {
        Todo::dueDate = dueDate;
    }

    bool getHasCompleted() const {
        return hasCompleted;
    }

    void setHasCompleted(bool hasCompleted) {
        Todo::hasCompleted = hasCompleted;
    }

    Todo();

    Todo(const std::string &name, const std::vector<int> &dueDate);
};


#endif //CALENDAREVENTMANAGEMENT_TODO_H
