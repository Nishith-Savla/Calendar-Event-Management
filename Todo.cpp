#include "Todo.h"

int Todo::totalTodos = 0;

Todo::Todo() {
    ++Todo::totalTodos;
    this->dueDate.reserve(3); // create 3 blocks of space in memory
}

Todo::Todo(const string &name, const vector<int> &dueDate) : Todo() {
    this->setName(name);
    this->setDueDate(dueDate);
}

string Todo::dumpToString() {
    string todo;
    todo.append(this->name).append(",");
    todo.append(this->hasCompleted ? "true" : "false").append(",");
    for (auto dateValue: this->dueDate) {
        todo.append(to_string(dateValue)).append(" ");
    }
    return todo;
}