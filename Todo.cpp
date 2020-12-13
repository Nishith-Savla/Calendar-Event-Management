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
